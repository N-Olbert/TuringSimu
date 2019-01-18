#include "../Header/DiskIO.hpp"
#include <fstream>
#include "../../../TuringSimuCommon/Common/Header/Utility.hpp"
#include "../Header/Directives.hpp"

using namespace ts_common;
using namespace ts_io;


//Todo: we probably should return a pointer here
TuringMachineDefinition ts_io::GetTuringMachineDefinitionFromFile(std::string path) {
	//needs to be last of since the path may contain ".."/"." 
	//if the path doesn't contain a '.' there are no problems because the substr method 
	//then just returns the entire string
	auto const index = path.find_last_of('.');
	auto const fileExtension = path.substr(index + 1, path.length() - index);
	if (fileExtension == "csv") {
		auto machineDefinition = ts_io_intern::GetTuringMachineDefinitionFromCSV(path);
        machineDefinition.fileName =  path;
		return machineDefinition;
	} else if (fileExtension == "tmsim") {
		auto machineDefinition = ts_io_intern::GetTuringMachineDefinitionFromBinary(path);
        machineDefinition.fileName = path;
		return machineDefinition;
	}
	TuringMachineDefinition dummy;
	dummy.error = true;
	return dummy;
}

std::string ts_io::GetAbsolutePath(const std::string & relativePath)
{
    return relativePath;
    //return absolute(std::filesystem::path{ relativePath }).string();
}

TuringMachineDefinition ts_io_intern::GetTuringMachineDefinitionFromCSV(std::string path) {
	bool metBlankDirective = false;
	bool metStartStateDirective = false;
	std::ifstream input;
	TuringMachineDefinition tmd;
	tmd.error = false;
	try {
		//pointer?
		input.open(path);
		if (input.is_open()) {
			std::string line;
			std::getline(input, line);
			auto version = ts_io_intern::getVersion(std::stoi(line));
			//getting out of dodge since this version is not supported for this file format
			if (version != v0) {
				tmd.error = true;
				return tmd;
			}
			std::getline(input, line);
			tmd.type = getType(line);

			std::getline(input, line); //initializing the current directive

			directive activeDirective = switchOnDirectives(line);

			std::getline(input, line); //getting the first actual data
			std::vector<char> tapeAlpha;
			std::vector<State> stateVector;
			std::vector<Transition> transitionsWithEpsilon;

			while (true) {
				//skips empty lines
				if (!line.empty()) {
					switch (activeDirective) {

					case states: {
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
						//Neither a DEA nor a NEA possess a tape so we set the error bit
						if (tmd.type == DEA || tmd.type == NEA) {
							tmd.error = true;
						}
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
					case blank: {
						if (tmd.type == DEA || tmd.type == NEA) {
							tmd.error = true;
						}
						tmd.blank = split(line)[0].at(0);
						metBlankDirective = true;
						break;
					}
					case transitions: {
						bool epsilonUsed = false;
						if (tmd.type == DEA || tmd.type == NEA) {
							//since DEA and NEA transitions only have 2 input- and 1 outputparameter
							//we append stuff to simulate them in a TM
							line.push_back(';');
							//s is the current character (as a string)
							auto s = split(line)[1];
							if (!s.empty()) {
								line.push_back(s.at(0));
							} else {
								line.push_back(BaseTransition::Epsilon);
								epsilonUsed = true;
							}
							//finite state machines only move right
							line.append(";R");
						}
						if (!epsilonUsed) {
							tmd.transitions.emplace_back(Transition{ line });
						} else {
							transitionsWithEpsilon.emplace_back(Transition{ line });
						}
						break;
					}
					case finalStates: {
						tmd.finalStates.insert(State{ line });
						break; }
					default:;
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
				if (tmd.type == DEA || tmd.type == NEA) {
					tmd.blank = '#';
					tmd.tapeAlphabet.insert('#');
				} else {
					tmd.blank = tapeAlpha[0];
				}
			}
			if (!metStartStateDirective) {
				//copy-constructor usage
				tmd.beginState = State{ stateVector[0] };
			}


			//getting rid of vectors
			tmd.states.UnionWith(stateVector);
			tmd.tapeAlphabet.UnionWith(tapeAlpha);
			tmd.tapeAlphabet.insert(tmd.alphabet.begin(), tmd.alphabet.end());

			//constructing the equivalents of epsilon transitions in a NEA for the tm
			if (!transitionsWithEpsilon.empty() && tmd.type != NEA) {
				//found some epsilon transitions for a TM type that doesn't allow them so we 
				//set the error bit
				tmd.error = true;
			} else if (!transitionsWithEpsilon.empty()) {
				//if we get here the type is NEA and there are some epsilon transitions, so we
				//need to convert them
				for (auto const element : transitionsWithEpsilon) {
					//converts qX;\epsilon;qY;\epsilon;R to qX;a;qY;a;S
					for (auto value : tmd.tapeAlphabet) {
						tmd.transitions.push_back(Transition{ element.GetCurrentState(), value, value, element.GetNextState(), Stay });
					}
				}

			}
		} else {
			//happens when the std::ifstream couldn't be opened, aka the filepath was bad
			tmd.error = true;
		}

	}
	//catches any exceptions thrown by methods like ts_io_intern::GetType
	catch (...) {
		input.close();
		tmd.error = true;
	}
	input.close();
	return tmd;
}

TuringMachineDefinition ts_io_intern::GetTuringMachineDefinitionFromBinary(std::string path) {
	std::ifstream in;
	TuringMachineDefinition tmd;
	tmd.error = false;
	try {
		in.open(path);
		if (in.is_open()) {

			char buffer[1024];
			auto version = ts_io_intern::getVersion(
				readFromBinaryStream<uint16_t>(in, buffer));
			uint32_t count = 0;
			std::string type = readString(in, buffer, 3);
			tmd.type = getType(type);

			auto const stateNR = readFromBinaryStream<uint16_t>(in, buffer);
			count += stateNR;
			for (int i = 0; i < stateNR; ++i) {
				auto s = readString(in, buffer);
				tmd.states.insert(State{ s });
			}
			auto const beginstate = readString(in, buffer);
			tmd.beginState = State{ beginstate };

			auto const finalStateNr = readFromBinaryStream<uint16_t>(in, buffer);
			count += finalStateNr;
			for (int i = 0; i < finalStateNr; ++i) {
				auto s = readString(in, buffer);
				tmd.finalStates.insert(State{ s });
			}

			auto const alphabetNr = readFromBinaryStream<uint16_t>(in, buffer);
			count += alphabetNr;
			for (int i = 0; i < alphabetNr; ++i) {
				auto c = readFromBinaryStream<char>(in, buffer);
				tmd.alphabet.insert(c);
			}

			auto const tapeAlphabetNr = readFromBinaryStream<uint16_t>(in, buffer);
			count += tapeAlphabetNr;
			for (int i = 0; i < tapeAlphabetNr; ++i) {
				auto c = readFromBinaryStream<char>(in, buffer);
				tmd.tapeAlphabet.insert(c);
			}

			const auto blank = readFromBinaryStream<char>(in, buffer);
			tmd.blank = blank;

			const auto transitionNr = readFromBinaryStream<uint16_t>(in, buffer);
			count += transitionNr;
			for (int i = 0; i < transitionNr; ++i) {
				auto currentState = State{ readString(in, buffer) };
				auto currentChar = readFromBinaryStream<char>(in, buffer);
				auto nextState = State{ readString(in,buffer) };
				auto nextChar = readFromBinaryStream<char>(in, buffer);
				auto hd = readFromBinaryStream<char>(in, buffer);
				std::string temp;
				temp.push_back(hd);
				auto headDirection = getDirection(temp);
				tmd.transitions.emplace_back(currentState, currentChar, nextChar, nextState, headDirection);
			}

			//checksum feature introduced in v1
			if (version == v1) {
				auto compareCount = readFromBinaryStream<uint32_t>(in, buffer);
				if (compareCount != count) {
					tmd.error = true;
				}
			}
		} else {
			//happens when the std::ifstream couldn't be opened
			tmd.error = true;
		}
	}
	catch (...) {
		in.close();
		tmd.error = true;
	}
	in.close();
	return tmd;
}

//checks if a string could be a directive
bool ts_io_intern::isDirective(std::string &toTest) {
	//size test, so the method wont crash on single char or empty input
	if (toTest.size() < 2)
		return false;
	return toTest.front() == '%' && toTest.back() == '%';
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

ts_io_intern::versionNumber ts_io_intern::getVersion(uint16_t in) {
	switch (in) {
	case 0:
		return v0;
	case 1:
		return v1;
	default:
		throw std::runtime_error("unsupportedVersion");
	}
}
