#pragma once
#include <string>
#ifndef TS_MACHINETYPE
namespace ts_common
{
	/*
	 * Enumeration of possible machine types.
	 */
	enum MachineType {
		/*
		 * Deterministic turing machine.
		 */
		DTM,

		/*
		 * Non-deterministic turing machine
		 */
		NTM,

		/*
		 * Deterministic finite state machine
		 */
		DEA,

		/*
		 * Non-deterministic finite state machine
		 */
		NEA
	};
	std::string TypeToString(MachineType type);

	/**
	* \brief Gets the appropriate enum for the given string, Default return is DTM
	* \param in the string containing the TM-Type
	* \return The appropriate enum
	*/
	MachineType getType(std::string &in);
}
#define TS_MACHINETYPE
#endif