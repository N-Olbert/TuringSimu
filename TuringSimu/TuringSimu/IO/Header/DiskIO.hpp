#pragma once
#ifndef TM_DISKIO
#define TM_DISKIO
#include <string>
#include "../../Common/Header/TuringMachineDefinition.hpp"
#include <fstream>
//for everything concerning public IO-Action
namespace ts_io
{
	using namespace ts_common;

	/**
	 * \brief Loads a TM from a file. The only method for endusers
	 * \param path The path to the save file
	 * \return The TuringMachineDefinition specified by the file. This can be made into an actual TM
	 */
	TuringMachineDefinition GetTuringMachineDefinitionFromFile(std::string path);

	//Namespace for nesting's sake
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
		 * \brief Reads a string from the given input stream into the specified buffer. Stringlength is
		 * //determined by a call to \see readSize
		 * \param in The stream to read from
		 * \param dest The buffer to read into
		 * \return The read string
		 */
		std::string readString(std::ifstream &in, char* dest);

		/**
		 * \brief Reads a string from the given fileinputstream
		 * \param in The fileinputstream to read from
		 * \param dest The buffer to read into
		 * \param size The length of characters to read
		 * \return The read string
		 * \throws std::runtime_error if the filestream is invalid
		 */
		std::string readString(std::ifstream &in, char* dest,uint16_t size);

		/**
		 * \brief Reads a uint16_t from the given stream
		 * \param in The fileinputstream to read from
		 * \param dest The buffer to read into
		 * \return The read uint16_t
		 */
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
