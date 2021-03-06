#pragma once
#ifndef TM_MACHINEFACTORY
#define TM_MACHINEFACTORY
#include "../../../TuringSimuCommon/Common/Header/AbstractMachine.hpp"
#include "../../../TuringSimuCommon/Common/Header/AbstractMachineUserinterface.hpp"
#include "../../../TuringSimuCommon/Common/Header/MachineType.hpp"
#include "../Header/TuringMachine.hpp"

using namespace ts_common;
namespace ts_business
{
	/*
	 * Factory to create machines
	 */
	class MachineFactory
	{
		public:
			/**
			 * \brief Creates a turing machine (if possible) from the given file with no observing UI.
			 * \param path The path of the file from which a turing machine should be created.
			 * \return The created turing machine
			 */
			static std::unique_ptr<AbstractMachine> CreateMachineFromFile(const std::string& path);

			/**
			 * \brief Creates a turing machine (if possible) from the given file.
			 * \param path The path of the file from which a turing machine should be created. 
			 * \param observingUI The UI which will observe the machine which will be created.
			 * \return The created turing machine
			 */
			static std::unique_ptr<AbstractMachine> CreateMachineFromFile(const std::string& path,
																		  AbstractMachineUserinterface* observingUI);
		private:
			/**
			 * \brief Checks whether a given machine definition is valid
			 * \param definition The definition to check
			 * \return true if machine is valid, false otherwise
			 */
			static bool IsValidTuringMachineDefinition(TuringMachineDefinition& definition, std::string& errorMessage);
	};
}
#endif // TM_MACHINEFACTORY
