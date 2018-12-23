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
			 *			NOTE: must be called with std::move()
			 * \param path The path of the file from which a turing machine should be created. 
			 * \param observingUI The UI which will observe the machine which will be created.
			 * \return The created turing machine
			 */
			static std::unique_ptr<AbstractMachine> CreateMachineFromFile(
				std::string& path, AbstractMachineUserinterface* observingUI);
		private:
			/**
			 * \brief Checks whether a given machine definition is valid
			 * \param definition The definition to check.
			 * \return true if machine is valid, false otherwise
			 */
			static bool IsValidMachineDefinition(TuringMachineDefinition& definition);
	};
}
#endif // TM_MACHINEFACTORY
