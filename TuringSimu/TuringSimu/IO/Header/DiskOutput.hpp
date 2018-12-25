#pragma once
#ifndef TS_DISKOUTPUT
#define TS_DISKOUTPUT
#include <string>
#include "../../Common/Header/HeadDirection.hpp"
#include "../../Common/Header/TuringMachineDefinition.hpp"
#include <fstream>
#include <iostream>
using namespace ts_common;
namespace ts_io {
	/**
	 * \brief Saves the given data as a CSVfile, so you can brag with it
	 * \param filePath where the file should be saved. Fileextension .csv is necessary
	 * \param data The TM to be saved
	 */
	void saveAsCSV(std::string const &filePath, TuringMachineDefinition &data);

	/**
	 * \brief Saves the given TM as a binary, you can brag even better with this
	 * \param filePath the filepath, needs to end with ".tmsim"
	 * \param data The TM to be saved
	 */
	void saveAsBinary(std::string const &filePath, TuringMachineDefinition &data);

	//for private helper functions concerning IO
	namespace ts_io_intern {

		/**
		 * \brief Returns a string representation of its parameter which is
		 * appropriate for a CSVfile
		 */
		std::string stringifyCSV(Transition &t);
		std::string stringifyCSV(char &c);
		std::string stringifyCSV(State &state);
		/**
		 * \brief Saves its parameter in the defined format
		 * \see BinaryFormatV0.txt
		 */
		void makeBinary(std::ofstream &out, State &state);
		void makeBinary(std::ofstream &out, Transition &t);
		void makeBinary(std::ofstream &out, char &c);
		void makeBinary(std::ofstream &out, std::string &s);

		/**
		 * \brief Writes its parameters into a csvFile 
		 * \tparam T The type of the parameter, needs to have an implementation of \see stringifyCSV
		 * \param out The fileoutputstream to write to
		 * \param toWrite The vector to write into the file
		 * \return 
		 */
		template <typename T>
		bool writeToCSVFile(std::ofstream &out, std::vector<T> &toWrite) {
			if (out.is_open()) {
				for (auto & value : toWrite) {
					auto s = stringifyCSV(value);
					out << s << '\n';
				}return true;
			}
			return false;
		}

		/**
		 * \brief Writes it parameter in the ofstream in binary format
		 * \tparam T Type of the parameter, needs to have a implemented \see makeBinary method
		 * \param out The fileoutputstream to write to
		 * \param param The parameter to write
		 */
		template <typename T>
		void writeToBinary(std::ofstream &out, T param) {
			if (out.is_open()) {
				ts_io_intern::makeBinary(out, param);
			}
		}

		/**
		 * \brief Writes a vector of type T to the given ofstream in binary format 
		 * \tparam T Type of the parameters, needs to have a corresponding \see writeToBinary implementation
		 * \param out The fileoutputstream to write to
		 * \param params The vector of things to write
		 */
		template <typename T>
		void writeToBinary(std::ofstream &out, std::vector<T> params) {
			uint16_t size = params.size();
			out.write((char*)&size, sizeof(uint16_t));
			for (auto element : params) {
				writeToBinary(out, element);
			}
		}
	}
}
#endif