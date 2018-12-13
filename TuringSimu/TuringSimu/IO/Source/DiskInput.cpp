#include "../Header/DiskInput.hpp"
#include <iostream>
#include <fstream>
#include "../../Common/Header/Utility.hpp"

using namespace ts_common;
using namespace ts_io;

TuringMachineDefinition DiskIO::GetTuringMachineDefinitionFromFile(std::string path) {
	auto const index = path.find_last_of('.');
	auto const fileExtension = path.substr(index + 1, path.length() - index);
	std::cout << fileExtension;
	if (fileExtension == "csv") {
		return GetTuringMachineDefinitionFromCSV(path);
	}
	TuringMachineDefinition t;
	throw std::logic_error("unsupported File extension");
}

TuringMachineDefinition DiskIO::GetTuringMachineDefinitionFromCSV(std::string path) {
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

			tmd.type = getType(input);

			std::getline(input, line); //initializing the current directive
			directive activeDirective = switchOnDirectives(line);

			std::getline(input, line); //getting the first actual data
			std::vector<char> tapeAlpha;
			std::vector<State> stateVector;
			std::vector<State> finalStatesVector;
			while (!input.eof()) {
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
						tmd.tapeAlphabet.insert(c[0]);
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
					finalStatesVector.emplace_back(State{ split(line)[0] });
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
				std::getline(input, line);
				if (isDirective(line)) {
					activeDirective = switchOnDirectives(line);
					std::getline(input, line);
				}
			}
			if (!metBlankDirective) {
				tmd.blank = tapeAlpha[0];
			}
			if (!metStartStateDirective) {
				tmd.beginState = State{ stateVector[0] };
			}

			tmd.states.UnionWith(stateVector);
			//getting rid of vectors
			
			tmd.finalStates.UnionWith(finalStatesVector);

			tmd.tapeAlphabet.UnionWith(tapeAlpha);
			

		}

	}
	catch (...) {
		input.close();
	}
	input.close();
	return tmd;
}

TuringMachineDefinition DiskIO::GetTuringMachineDefinitionFromBinary(std::string path) {
	//TODO
	throw std::logic_error("Not implemented yet");

}

//specifies wether a string could be a directive
bool DiskIO::isDirective(std::string &toTest) {
	return toTest.front() == '%'&&toTest.back() == '%';
}

//method to simulate a switch on strings. returns DTM as default
MachineType DiskIO::getType(std::ifstream &in) {
	std::string line;
	std::getline(in, line);
	if (line == "DTM") {
		return DTM;
	} else if (line == "TM") {
		return DTM;
	} else if (line == "NTM") {
		return NTM;
	}
	return DTM;
}

std::string DiskIO::getDirectiveString(std::string &directive) {
	return directive.substr(1, directive.length() - 2);
}

//method to simulate a switch on strings. Throws exception if default case is reached
directive DiskIO::switchOnDirectives(std::string &directive) {
	DiskIO::getDirectiveString(directive);
	if (directive == "tape") {
		return tape;
	} else if (directive == "alphabet") {
		return alphabet;
	} else if (directive == "states") {
		return states;
	} else if (directive == "startState") {
		return startState;
	} else if (directive == "finalState") {
		return finalState;
	} else if (directive == "blank") {
		return blank;
	} else if (directive == "transitions") {
		return transitions;
	} else throw std::exception("Not a valid directive");
}