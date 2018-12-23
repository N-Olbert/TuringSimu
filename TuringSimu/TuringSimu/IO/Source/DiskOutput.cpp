#include "../Header/DiskOutput.hpp"
#include <fstream>
#include "../Header/Directives.hpp"
using namespace ts_io;
using namespace ts_common;
void ts_io::saveAsCSV(std::string const &filePath, TuringMachineDefinition &data) {
	std::ofstream out;
	try {
		out.open(filePath);
		if (out.is_open()) {
			out << "0\n";

			out << TypeToString(data.type) << std::endl;

			out << directiveToString(states);
			auto v = data.states.asVector();

			ts_io_intern::writeToCSVFile<State>(out, v);
			out << directiveToString(startState);
			out << data.beginState.GetIdentifier() << std::endl;
			out << directiveToString(transitions);
			ts_io_intern::writeToCSVFile<Transition>(out, data.transitions);
			out << directiveToString(tape);
			auto anotherVector = data.tapeAlphabet.asVector();
			ts_io_intern::writeToCSVFile<char>(out, anotherVector);

			out << directiveToString(blank);
			out << data.blank << std::endl;
			out << directiveToString(alphabet);
			auto yetanothervector = data.alphabet.asVector();
			ts_io_intern::writeToCSVFile<char>(out, yetanothervector);
		}
	}
	catch (...) {
		out.close();
	}
	out.close();
}

void ts_io::saveAsBinary(std::string const &filePath, TuringMachineDefinition &data) {
	std::ofstream out;
	try {
		out.open(filePath);
		if (out.is_open()) {
			uint16_t version = 0;
			out.write((char*)&version, sizeof(uint16_t));

			ts_io_intern::writeToBinary<std::string>(out, TypeToString(data.type));

			ts_io_intern::writeToBinary<State>(out, data.states.asVector());
			ts_io_intern::writeToBinary<State>(out, data.beginState);
			ts_io_intern::writeToBinary<State>(out, data.finalStates.asVector());
			ts_io_intern::writeToBinary<char>(out, data.alphabet.asVector());
			ts_io_intern::writeToBinary<char>(out, data.tapeAlphabet.asVector());
			ts_io_intern::writeToBinary<char>(out, data.blank);
			ts_io_intern::writeToBinary<Transition>(out, data.transitions);
		}
	}
	catch (...) {
		out.close();
	}
	out.close();
}

std::string ts_io_intern::stringifyCSV(Transition & t) {
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

std::string ts_io_intern::stringifyCSV(char & c) {
	std::string string;
	string.push_back(c);
	return string;
}

std::string ts_io_intern::stringifyCSV(State & state) {
	return state.GetIdentifier();
}

void ts_io_intern::makeBinary(std::ofstream &out, State & state) {
	auto identifier = state.GetIdentifier();
	uint16_t identifierLength = identifier.length();
	out.write((char*)&identifierLength, sizeof(uint16_t));
	//TODO maybe its possible to just interpret std::string as a char* and do the entire string at once
	for (int i = 0; i < identifierLength; ++i) {
		out.write(&(identifier.at(i)), sizeof(char));
	}

}

void ts_io_intern::makeBinary(std::ofstream &out, Transition & t) {
	auto state = t.GetCurrentState();
	makeBinary(out, state);
	auto const c = t.GetCurrentChar();
	out.write(&c, sizeof(char));
	state = t.GetNextState();
	makeBinary(out, state);
	auto const nc = t.GetToWrite();
	out.write(&nc, sizeof(char));
	char  hd;
	switch (t.GetHeadDirection()) {
	case Left: {
		hd = 'L';
		break; }
	case Right: {
		hd = 'R';
		break;
	}
	case Stay: {
		hd = 'S';
		break; }
	default:;
	}
	out.write(&hd, sizeof(char));
}

void ts_io_intern::makeBinary(std::ofstream& out, char& c) {
	out.write(&c, sizeof(char));
}

void ts_io_intern::makeBinary(std::ofstream& out, std::string& s)
{
	for (int i = 0; i < s.length(); ++i) {
		out.write(&(s.at(i)), sizeof(char));
	}
}
