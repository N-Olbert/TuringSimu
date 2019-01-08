#pragma once
#include <string>
#ifndef TS_MACHINETYPE
namespace ts_common
{
	/*
	 * Enumeration of possible machine types.
	 */
	enum MachineType 
	{
		/*
		 * Default value.
		 */
		UNKNOWN,

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

	/**
	 * \brief Returns the string matching the enum value
	 * \param type The enum value we need a string of
	 * \return The matching string
	 */
	std::string TypeToString(MachineType type);

	/**
	* \brief Gets the appropriate enum for the given string, Default return is DTM
	* \param in the string containing the TM-Type
	* \return The appropriate enum
	* \throws std::logic_error if it could not match the string to an enum value
	*/
	MachineType getType(std::string &in);
}
#define TS_MACHINETYPE
#endif