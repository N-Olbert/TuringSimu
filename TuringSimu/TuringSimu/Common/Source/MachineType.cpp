#include "../Header/MachineType.hpp"
#include <string>
using namespace ts_common;

std::string ts_common::TypeToString(MachineType type) {
	switch (type) {
	case DTM:
		return "DTM";
	case NTM:
		return "NTM";
	case DEA:
		return "DEA";
	case NEA:
		return "NEA";
	//default case should never be reached but compiler gives out warnings otherwise
	default: return "";
	}
}

//method to simulate a switch on strings. returns DTM as default
MachineType ts_common::getType(std::string &line) {
	if (line == ("DTM")) {
		return DTM;
	} else if (line == "TM") {
		return DTM;
	} else if (line == "NTM") {
		return NTM;
	} else if (line == "DEA") {
		return DEA;
	} else if (line == "NEA") {
		return NEA;
	}
	return DTM;
}
