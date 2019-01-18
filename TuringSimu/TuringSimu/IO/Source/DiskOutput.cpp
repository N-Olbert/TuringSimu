#include "../Header/DiskOutput.hpp"
#include <fstream>
#include <memory>
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

			out << directiveToString(finalStates);
			auto finalStates = data.finalStates.asVector();
			ts_io_intern::writeToCSVFile<State>(out, finalStates);

			out << directiveToString(startState);
			out << data.beginState.GetIdentifier() << std::endl;

			out << directiveToString(transitions);
			//Nobody needs to know how we internally handle statemachines, so 
			//we need to cut a bit of the transition of there
			if (!(data.type == DEA || data.type == NEA)) {
				ts_io_intern::writeToCSVFile<Transition>(out, data.transitions);
			} else {
				for (auto& element : data.transitions) {
					out << ts_io_intern::stringifyCSV(element.GetCurrentState()) <<
						';' << element.GetCurrentChar() << ';' <<
						ts_io_intern::stringifyCSV(element.GetNextState()) << std::endl;
				}
			}
			//a state machine doesn't have a tape so we skip this part if data is 
			//specifying a state machine
			if (!(data.type == DEA || data.type == NEA)) {
				out << directiveToString(tape);
				auto anotherVector = data.tapeAlphabet.asVector();
				ts_io_intern::writeToCSVFile<char>(out, anotherVector);

				out << directiveToString(blank);
				out << data.blank << std::endl;
			}
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
			uint16_t version = 1;
			out.write(reinterpret_cast<char*>(&version), sizeof(uint16_t));

			uint32_t count = 0;
			ts_io_intern::writeToBinary<std::string>(out, TypeToString(data.type));

			ts_io_intern::writeToBinary<State>(out, data.states.asVector());
			ts_io_intern::writeToBinary<State>(out, data.beginState);
			ts_io_intern::writeToBinary<State>(out, data.finalStates.asVector());
			ts_io_intern::writeToBinary<char>(out, data.alphabet.asVector());
			ts_io_intern::writeToBinary<char>(out, data.tapeAlphabet.asVector());
			ts_io_intern::writeToBinary<char>(out, data.blank);
			ts_io_intern::writeToBinary<Transition>(out, data.transitions);

			count += static_cast<uint32_t>(data.states.size());
			count += static_cast<uint32_t>(data.finalStates.size());
			count += static_cast<uint32_t>(data.alphabet.size());
			count += static_cast<uint32_t>(data.tapeAlphabet.size());
			count += static_cast<uint32_t>(data.transitions.size());

			out.write(reinterpret_cast<char*>(&count), sizeof(uint32_t));
		}
	}
	catch (...) {
		out.close();
	}
	out.close();
}

bool ts_io::WriteToFile(const std::string& filePath, const std::string& data)
{
	bool success;
	std::unique_ptr<std::ofstream> stream;
	try
	{
		stream = std::make_unique<std::ofstream>(filePath, std::ios::trunc);
		if ((success = stream->is_open()))
		{
			*stream << data;
		}
	}
	catch (...)
	{
		if(stream != nullptr)
		{
			stream->close();
		}

		return false;
	}

	if (stream != nullptr)
	{
		stream->close();
	}

	return success;
}

std::string ts_io_intern::stringifyCSV(const Transition & t) {
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

std::string ts_io_intern::stringifyCSV(const char & c) {
	std::string string;
	string.push_back(c);
	return string;
}

std::string ts_io_intern::stringifyCSV(const State & state) {
	return state.GetIdentifier();
}

void ts_io_intern::makeBinary(std::ofstream &out, State & state) {
	auto identifier = state.GetIdentifier();
	auto identifierLength = static_cast<uint16_t>(identifier.length());
	out.write(reinterpret_cast<char*>(&identifierLength), sizeof(uint16_t));
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

void ts_io_intern::makeBinary(std::ofstream& out, std::string& s) {
	//C++11 feature
	for (char& i : s) {
		out.write(&i, sizeof(char));
	}
}
