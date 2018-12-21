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
	}
	TuringMachineDefinition t;
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
			std::vector<State> finalStatesVector;

			while (true) {
				if (!line.empty()) {
					switch (activeDirective) {

					case states:
					{
						auto tmp = split(line);
						if (tmp.size() > 1) {
							if (tmp[1] == "f") {
								finalStatesVector.emplace_back(State{ tmp[0] });
							}
						}
						stateVector.emplace_back(State{ tmp[0] });
					}
					break;
					case tape: {
						auto vector = split(line);
						for (auto c : vector) {
							tapeAlpha.push_back(c[0]);
						}
					}
							   break;
					case alphabet: {
						auto vector = split(line);
						for (auto c : vector) {
							tmd.alphabet.insert(c[0]);
						}
					}
								   break;
					case startState: {
						tmd.beginState = line;
						metStartStateDirective = true;
					}
									 break;
					case finalState: {
						//TODO
						finalStatesVector.push_back(State{ split(line)[0] });
					}
									 break;
					case blank: {
						tmd.blank = split(line)[0].at(0);
						metBlankDirective = true;
					}
								break;
					case transitions: {
						Transition t{ line };
						tmd.transitions.push_back(t);
					}
									  break;
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
			std::cout << "im here";
			if (!metBlankDirective) {
				//tapealpha cant be initialized currently so this needs to be commented out
				tmd.blank = tapeAlpha[0];
			}
			if (!metStartStateDirective) {
				tmd.beginState = State{ stateVector[0] };
			}

			tmd.states.UnionWith(stateVector);
			//getting rid of vectors

			tmd.finalStates.UnionWith(finalStatesVector);

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
	//TODO
	throw std::logic_error("Not implemented yet");

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