#include "../Header/DiskOutput.hpp"
#include <fstream>
#include "../Header/Directives.hpp"
using namespace ts_io;
using namespace ts_common;
void ts_io::saveAsCSV(std::string const filePath, TuringMachineDefinition data) {
	std::ofstream out;
	try {
		out.open(filePath);
		if (out.is_open()) {
			out << "0\n";

			if (data.type == DTM) {
				out << "DTM\n";
			} else {
				out << "NTM\n";
			}
			out << directiveToString(states);
			auto v = data.states.asVector();
			writeToCSVFile<State>(out, v);
			out << directiveToString(startState);
			out << data.beginState.GetIdentifier() << std::endl;
			out << directiveToString(transitions);
			writeToCSVFile<Transition>(out, data.transitions);
			out << directiveToString(tape);
			auto anotherVector = data.tapeAlphabet.asVector();
			writeToCSVFile<char>(out, anotherVector);
			out << directiveToString(blank);
			out << data.blank << std::endl;
			out << directiveToString(alphabet);
			auto yetanothervector = data.alphabet.asVector();
			writeToCSVFile<char>(out,yetanothervector);
			//leaves a trailing \n which kills inputreading so either harden input or remove it
		}
	}
	catch (...) {
		out.close();
	}
	out.close();
}

void ts_io::saveAsBinary(std::string filePath, TuringMachineDefinition data) {
	//TODO
	throw std::logic_error("Not implemented");
}

std::string ts_io::stringifyCSV(Transition & t) {
	std::string string;
	auto s = t.GetCurrentState();
	string.append(stringifyCSV(s));
	string.push_back(';');
	string.push_back(t.GetCurrentChar());
	string.push_back(';');
	s = t.GetNextState();
	string.append(stringifyCSV(s));
	string.push_back(';');
	string.push_back(t.GetToWrite());
	string.push_back(';');
	switch (t.GetHeadDirection()) {

	case Left: string.push_back('L');
		break;
	case Right:
		string.push_back('R');
		break;
	case Stay: string.push_back('S');
		break;
	default:;
	}
	return string;
}

std::string ts_io::stringifyCSV(char & c) {
	std::string string;
	string.push_back(c);
	return string;
}

std::string ts_io::stringifyCSV(State & state) {
	return state.GetIdentifier();
}
