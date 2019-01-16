#ifndef TMS_COMMANDLINEMACHINEUI
#define TMS_COMMANDLINEMACHINEUI
#include "../../UI/Header/Console.hpp"
#include "../../../TuringSimuCommon/Common/Header/AbstractMachine.hpp"
using namespace ts_common;
using namespace ts_ui;
namespace ts_ui_business
{
	/**
	 * \brief Base controller for all console applications. Redirects to concrete controller instances later on.
	 */
	class BaseConsoleController
	{
		public:
			/**
			 * \brief Starts the execution.
			 */
			static void Start();

		private:

			/**
			 * \brief Prints the main menu
			 */
			static void PrintMenu();

			/**
			 * \brief Changes the language
			 */
			static void ChangeLanguage();

			/**
			 * \brief Attempts to read in a machine form a requested file path.
			 */
			static void ReadInMachine();

			/**
			 * \brief Prints the machine menu of the given machine.
			 */
			static void PrintLoadedMachineMenu(std::unique_ptr<AbstractMachine> machine);
	};
}
#endif // TMS_COMMANDLINEMACHINEUI
