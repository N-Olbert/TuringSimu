#include "../Header/DiskIO.hpp"
#include <iostream>
#include <fstream>
#include "../../Common/Header/Utility.hpp"
#include "../Header/Directives.hpp"

using namespace ts_common;
using namespace ts_io;

TuringMachineDefinition ts_io::GetTuringMachineDefinitionFromFile(std::string path) {
	auto const index = path.find_last_of('.');
	auto const fileExtension = path.substr(index + 1, path.length() - index);
	std::cout << fileExtension;
	if (fileExtension == "csv") {
		return ts_io_intern::GetTuringMachineDefinitionFromCSV(path);
	} else if (fileExtension == "tmsim") {
		return ts_io_intern::GetTuringMachineDefinitionFromBinary(path);
	}
	//TODO maybe different handling of bad user input
	throw std::logic_error("unsupported File extension");
}

TuringMachineDefinition ts_io_intern::GetTuringMachineDefinitionFromCSV(std::string path) {
	bool metBlankDirective = false;
	bool metStartStateDirective = false;
	std::ifstream input;
	TuringMachineDefinition tmd;
	try {
		input.open(path);
		if (input.is_open()) {
			std::string line;
			std::getline(input, line);
			auto version = std::stoi(line); //TODO redefine later stuff, so it is parsed according to versionnumber
			std::getline(input, line);
			tmd.type = getType(line);

			std::getline(input, line); //initializing the current directive

			directive activeDirective = switchOnDirectives(line);

			std::getline(input, line); //getting the first actual data
			std::vector<char> tapeAlpha;
			std::vector<State> stateVector;

			while (true) {
				//skips empty lines
				if (!line.empty()) {
					switch (activeDirective) {

					case states:
					{
						auto tmp = split(line);
						if (tmp.size() > 1) {
							if (tmp[1] == "f") {
								tmd.finalStates.insert(State{ tmp[0] });
							}
						}
						stateVector.emplace_back(State{ tmp[0] });
						break;
					}

					case tape: {
						auto vector = split(line);
						for (auto c : vector) {
							tapeAlpha.push_back(c[0]);
						}
						break;
					}

					case alphabet: {
						auto vector = split(line);
						for (auto c : vector) {
							tmd.alphabet.insert(c[0]);
						}
						break;
					}

					case startState: {
						tmd.beginState = line;
						metStartStateDirective = true;
					}
									 break;
					case finalState: {
						tmd.finalStates.insert(State{ split(line)[0] });
						break;
					}
					case blank: {
						tmd.blank = split(line)[0].at(0);
						metBlankDirective = true;
						break;
					}
					case transitions: {
						tmd.transitions.emplace_back(line);
						break;
					}

					}
				}
				if (!input.eof()) {
					std::getline(input, line);

				} else break;
				if (isDirective(line)) {
					activeDirective = switchOnDirectives(line);
					std::getline(input, line);
				}
			}
			//fulfilling the convenience promises given in CSVFormatV0.txt
			if (!metBlankDirective) {
				tmd.blank = tapeAlpha[0];
			}
			if (!metStartStateDirective) {
				//copy-constructor usage
				tmd.beginState = State{ stateVector[0] };
			}

			//getting rid of vectors
			tmd.states.UnionWith(stateVector);
			tmd.tapeAlphabet.UnionWith(tapeAlpha);
			tmd.tapeAlphabet.insert(tmd.alphabet.begin(), tmd.alphabet.end());
		}

	}
	catch (...) {
		input.close();
	}
	input.close();
	return tmd;
}

TuringMachineDefinition ts_io_intern::GetTuringMachineDefinitionFromBinary(std::string path) {
	std::ifstream in;
	TuringMachineDefinition tmd;
	try {
		in.open(path);
		if (in.is_open()) {

			char buffer[1024];
			auto version = readFromBinaryStream<uint16_t>(in, buffer);
			//TODO maybe different version handling
			std::string type = readString(in, buffer,3);
			tmd.type = getType(type);

			auto stateNR = readFromBinaryStream<uint16_t>(in, buffer);
			for (int i = 0; i < stateNR; ++i) {
				auto s = readString(in, buffer);
				tmd.states.insert(State{ s });
			}
			auto beginstate = readString(in, buffer);
			tmd.beginState = State{ beginstate };

			auto finalStateNr = readFromBinaryStream<uint16_t>(in, buffer);
			for (int i = 0; i < finalStateNr; ++i) {
				auto s = readString(in, buffer);
				tmd.finalStates.insert(State{ s });
			}
			auto alphabetNr = readFromBinaryStream<uint16_t>(in, buffer);
			for (int i = 0; i < alphabetNr; ++i) {
				auto c = readFromBinaryStream<char>(in, buffer);
				tmd.alphabet.insert(c);
			}
			auto tapeAlphabetNr = readFromBinaryStream<uint16_t>(in, buffer);
			for (int i = 0; i < tapeAlphabetNr; ++i) {
				auto c = readFromBinaryStream<char>(in, buffer);
				tmd.tapeAlphabet.insert(c);
			}
			auto blank = readFromBinaryStream<char>(in, buffer);
			tmd.blank = blank;

			auto transitionNr = readFromBinaryStream<uint16_t>(in, buffer);
			for (int i = 0; i < transitionNr; ++i) {

				auto currentState = State{ readString(in, buffer) };
				auto currentChar = readFromBinaryStream<char>(in, buffer);
				auto nextState = State{ readString(in,buffer) };
				auto nextChar = readFromBinaryStream<char>(in, buffer);
				auto hd = readFromBinaryStream<char>(in, buffer);
				std::string temp;
				temp.push_back(hd);
				auto headDirection = getDirection(temp);
				tmd.transitions.push_back(Transition{ currentState,currentChar,nextChar,nextState,headDirection });
			}
		}
	}
	catch (...) {
		in.close();
	}
	in.close();
	return tmd;
}

//specifies wether a string could be a directive
bool ts_io_intern::isDirective(std::string &toTest) {
	//TODO maybe flesh out and harden it
	if (toTest.size() < 2)
		return false;
	return toTest.front() == '%'&&toTest.back() == '%';
}

//method to simulate a switch on strings. returns DTM as default

MachineType ts_io_intern::getType(std::string &line) {
	if (line == ("DTM")) {
		return DTM;
	} else if (line == "TM") {
		return DTM;
	} else if (line == "NTM") {
		return NTM;
	}
	return DTM;
}

std::string ts_io_intern::readString(std::ifstream& in, char* dest) {
	return readString(in, dest, readSize(in, dest));
}

std::string ts_io_intern::readString(std::ifstream& in, char* dest, uint16_t size) {
	std::string toReturn;
	for (int i = 0; i < size; ++i) {
		auto c = readFromBinaryStream<char>(in, dest);
		toReturn.push_back(c);
	}
	return toReturn;
}

uint16_t ts_io_intern::readSize(std::ifstream& in, char* dest) {
	return readFromBinaryStream<uint16_t>(in, dest);
}
