#ifndef TMS_COMMANDLINEMACHINEUI
#define TMS_COMMANDLINEMACHINEUI
#include "../../UI/Header/Console.hpp"
#include "../../../TuringSimuCommon/Common/Header/AbstractMachine.hpp"
using namespace ts_common;
using namespace ts_ui;
namespace ts_ui_business
{
	class BaseConsoleController
	{
		public:
			static void Start();

		private:
			static void PrintMenu();
			static void ChangeLanguage();
			static void ReadInMachine();
			static void PrintLoadedMachineMenu(std::unique_ptr<AbstractMachine> machine);
	};
}
#endif // TMS_COMMANDLINEMACHINEUI
