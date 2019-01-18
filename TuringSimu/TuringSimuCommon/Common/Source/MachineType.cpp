#include "../Header/MachineType.hpp"
#include <string>
#include <stdexcept>
using namespace ts_common;

/**
 * \brief Returns the string corresponding to the enum value
 * \param type The enum value to stringify
 * \return The string representation of the enum value 
 */
std::string ts_common::TypeToString(MachineType type) {
	switch (type) {
	case UNKNOWN:
		return "UNKNOWN";
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


/**
 * \brief Returns the enum value corresponding to the string
 * \param line The string representation of an enum value
 * \return The corresponding enum value
 * \throws std::logic_error if the string doesn't correspond to an enum value
 */
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
	} else if (line == "UNKNOWN") {
		return UNKNOWN;
	}
	throw std::logic_error("Unsupported TuringMachineType");
}
