#pragma once
#ifndef TM_MACHINEFACTORY
#define TM_MACHINEFACTORY
#include "TuringMachine.hpp"
using namespace ts_common;
namespace ts_business
{
	/*
	 * Factory to create turing machines
	 */
	class MachineFactory
	{
		public:
			/**
			 * \brief Creates a turing machine (if possible) from the given file.
			 * \param path The path of the file from which a turing machine should be created. 
			 * \return The created turing machine
			 */
			static TuringMachine CreateMachineFromFile(std::string& path);
		private:
			/**
			 * \brief Checks whether a given machine definition is valid
			 * \param definition The definition to check.
			 * \return true if machine is valid, false otherwise
			 */
			static bool IsValidMachineDefiniton(TuringMachineDefiniton& definition);
	};
}
#endif // TM_MACHINEFACTORY
