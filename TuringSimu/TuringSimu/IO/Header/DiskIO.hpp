#pragma once
#ifndef TM_DISKIO
#define TM_DISKIO
#include <string>
#include "../../Common/Header/TuringMachineDefinition.hpp"
namespace ts_io
{
	using namespace ts_common;
	class DiskIO {
	public:
		TuringMachineDefiniton GetTuringMachineDefinitionFromFile(std::string path);
	private:
		TuringMachineDefiniton GetTuringMachineDefinitionFromCSV(std::string path);
		TuringMachineDefiniton GetTuringMachineDefinitionFromBinary(std::string path);
	};
}
#endif // TM_DISKIO
