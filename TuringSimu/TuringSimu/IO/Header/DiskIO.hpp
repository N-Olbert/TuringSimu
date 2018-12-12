#pragma once
#ifndef TM_DISKIO
#define TM_DISKIO
#include <string>
#include "../../Common/Header/TuringMachineDefinition.hpp"
namespace ts_io
{
	using namespace ts_common;
	enum directive { states, tape, alphabet, startState, finalState, blank, transitions };
	class DiskIO {
	public:
		static TuringMachineDefinition GetTuringMachineDefinitionFromFile(std::string path);
	private:
		static TuringMachineDefinition GetTuringMachineDefinitionFromCSV(std::string path);
		static TuringMachineDefinition GetTuringMachineDefinitionFromBinary(std::string path);
		static bool isDirective(std::string &toTest);
		static MachineType getType(std::ifstream &in);
		static std::string getDirectiveString(std::string &directive);
		static directive switchOnDirectives(std::string &directive);
		static std::vector<std::string> breakIntoStrings(std::string line);
		static HeadDirection getDirection(std::string line);
	};
	enum versionNumber {V0};
	
}
#endif // TM_DISKIO
