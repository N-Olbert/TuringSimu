#pragma once
#ifndef TM_DISKIO
#define TM_DISKIO
#include <string>
#include "../../Common/Header/TuringMachineDefinition.hpp"
namespace ts_io
{
	using namespace ts_common;
	class DiskIO
	{
		public:
			TuringMachineDefiniton GetTuringMachineDefinitionFromCSV(std::string path);
	};
}
#endif // TM_DISKIO
