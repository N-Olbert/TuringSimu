#pragma once
#ifndef TM_DISKIO
#define TM_DISKIO
#include <string>
#include "../../Common/Header/TuringMachineDefinition.hpp"
#include <fstream>

namespace ts_io
{
	using namespace ts_common;

	TuringMachineDefinition GetTuringMachineDefinitionFromFile(std::string path);

	namespace ts_io_intern {
		TuringMachineDefinition GetTuringMachineDefinitionFromCSV(std::string path);
		TuringMachineDefinition GetTuringMachineDefinitionFromBinary(std::string path);
		bool isDirective(std::string &toTest);
		MachineType getType(std::string &in);

		//taken from the lecture
		template <typename typ1>
		typ1 readFromBinaryStream(std::ifstream &stream, char *dest) {
			if (stream.is_open()) {
				stream.read(dest, sizeof(typ1));
				typ1 *ptr = reinterpret_cast<typ1 *>(dest);
				return std::move(*ptr);
			} else {
				throw std::runtime_error("Could not read from file");
			}
		}
	}

	enum versionNumber { v0 };

}
#endif // TM_DISKIO
