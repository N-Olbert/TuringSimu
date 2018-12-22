#pragma once
#ifndef TM_DISKIO
#define TM_DISKIO
#include <string>
#include "../../Common/Header/TuringMachineDefinition.hpp"
#include <fstream>

namespace ts_io
{
	using namespace ts_common;


	/**
	 * \brief Loads a TM from a file. The only method for endusers
	 * \param path The path to the save file
	 * \return The TuringMachineDefinition specified by the file. This can be made into an actual TM
	 */
	TuringMachineDefinition GetTuringMachineDefinitionFromFile(std::string path);

	//Namespace for nestings sake
	namespace ts_io_intern {

		/**
		 * \brief Specializations of the GetTuringMachineDefinitionFromFile method
		 * \param path The path to the save File
		 * \return A TuringMachineDefinition
		 */
		TuringMachineDefinition GetTuringMachineDefinitionFromCSV(std::string path);
		TuringMachineDefinition GetTuringMachineDefinitionFromBinary(std::string path);


		/**
		 * \brief Checks if a string could be a directive
		 * \param toTest The string that should be tested
		 * \return True if the string starts and ends with an '%', false otherwise
		 */
		bool isDirective(std::string &toTest);


		/**
		 * \brief Gets the appropriate enum for the given string, Default return is DTM
		 * \param in the string containing the TM-Type
		 * \return The appropriate enum
		 */
		MachineType getType(std::string &in);

		std::string readString(std::ifstream &in, char* dest);
		std::string readString(std::ifstream &in, char* dest,uint16_t size);
		uint16_t readSize(std::ifstream& in, char* dest);
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
