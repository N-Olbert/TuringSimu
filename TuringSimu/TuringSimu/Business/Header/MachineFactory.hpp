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
			 *		  FACTORY: The returned pointer wont be managed, furthermore the caller must 
			 *		  maintain the returned pointer.
			 * \param path The path of the file from which a turing machine should be created. 
			 * \param observingUI The UI which will observe the machine which will be created.
			 * \return The created turing machine
			 */
			static AbstractMachine* CreateMachineFromFile(std::string& path, AbstactMachineUserinterface& observingUI);
		private:
			/**
			 * \brief Checks whether a given machine definition is valid
			 * \param definition The definition to check.
			 * \return true if machine is valid, false otherwise
			 */
			static bool IsValidMachineDefiniton(TuringMachineDefinition& definition);
	};
}
#endif // TM_MACHINEFACTORY
