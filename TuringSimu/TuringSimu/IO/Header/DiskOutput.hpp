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
	void saveAsCSV(std::string const filePath, TuringMachineDefinition data);
	void saveAsBinary(std::string filePath, TuringMachineDefinition data);

	
	std::string stringifyCSV(Transition &t);
	std::string stringifyCSV(char &c);
	std::string stringifyCSV(State &state);

	template <typename T>
	bool writeToCSVFile(std::ofstream &out, std::vector<T> &toWrite) {
		if (out.is_open()) {
			for ( auto & value : toWrite) {
				auto s = stringifyCSV(value);
				out << s << '\n';
			}return true;
		} else return false;
	};
}
#endif