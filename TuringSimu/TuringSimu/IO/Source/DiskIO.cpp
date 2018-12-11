#include "../../Common/Header/HeadDirection.hpp"
#include "../Header/DiskIO.hpp"
#include <iostream>
#include <fstream>
using namespace ts_common;
using namespace ts_io;

//int main() {
//	DiskIO::GetTuringMachineDefinitionFromFile("alabaster.derpify");
//	throw std::logic_error("Needs to be moved to ConsoleUI.cpp");
//	return 0;
//}

TuringMachineDefiniton DiskIO::GetTuringMachineDefinitionFromFile(std::string path) {
	auto index = path.find_last_of('.');
	auto fileExtension = path.substr(index + 1, path.length() - index);
	std::cout << fileExtension;
	if (fileExtension.compare("csv")) {
		return GetTuringMachineDefinitionFromCSV(path);
	}
	TuringMachineDefiniton t;
	throw std::logic_error("Not implemented yet");
	return t;
}

TuringMachineDefiniton DiskIO::GetTuringMachineDefinitionFromCSV(std::string path) {
	bool metBlankDirective = false;
	bool metStartStateDirective = false;
	std::ifstream input;
	TuringMachineDefiniton tmd;
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
			std::vector<std::string> stateVector;
			while (!input.eof()) {
				switch (activeDirective) {

				case states:
				{
					auto tmp = DiskIO::breakIntoStrings(line);
					stateVector.insert(stateVector.end(), tmp.begin(), tmp.end());
				}
				break;
				case tape: {
					auto set = DiskIO::breakIntoStrings(line);
					//tmd.tapeAlphabet.insert(set.begin(), set.end());
				}
						   break;
				case alphabet: {
					auto set = DiskIO::breakIntoStrings(line);
					//tmd.alphabet.insert(set.begin(), set.end());
				}
							   break;
				case startState: {
					tmd.beginState = line;
					metStartStateDirective = true;
				}
								 break;
				case finalState: {

				}
								 break;
				case blank: {

				}
							break;
				case transitions: {

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

			//getting rid of vectors
			for (auto value : stateVector) {
				auto result = tmd.states.insert(State{ value });
				if (result.second) {
					std::cout << "Ignoring the duplicate state " << value << std::endl;
				}
			}
			for (auto value : tapeAlpha) {
				auto result = tmd.tapeAlphabet.insert(value);
				if (result.second) {
					std::cout << "Ignoring the duplicate character " << value << std::endl;
				}
			}

		}

	}
	catch (...) {
		input.close();
	}
	input.close();
	throw std::logic_error("Not implemented yet");
	return tmd;
}

TuringMachineDefiniton DiskIO::GetTuringMachineDefinitionFromBinary(std::string path) {
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
	if (!line.compare("DTM")) {
		return DTM;
	} else if (!line.compare("TM")) {
		return DTM;
	} else if (!line.compare("NTM")) {
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
	if (!directive.compare("tape")) {
		return tape;
	} else if (!directive.compare("alphabet")) {
		return alphabet;
	} else if (!directive.compare("states")) {
		return states;
	} else if (!directive.compare("startState")) {
		return startState;
	} else if (!directive.compare("finalState")) {
		return finalState;
	} else if (!directive.compare("blank")) {
		return blank;
	} else if (!directive.compare("transitions")) {
		return transitions;
	} else throw std::exception("Not a valid directive");
}

std::vector<std::string> DiskIO::breakIntoStrings(std::string line) {
	std::vector<std::string> returnSet;
	while (line.find(';') != std::string::npos) {
		int pos = line.find(';');
		std::string substr = line.substr(0, pos);
		line.erase(0, pos + 1);
		returnSet.push_back(substr);
	}
	returnSet.push_back(line);
	return returnSet;
}