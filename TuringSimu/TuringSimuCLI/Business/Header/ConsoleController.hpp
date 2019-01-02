#ifndef TMS_COMMANDLINEMACHINEUI
#define TMS_COMMANDLINEMACHINEUI
#include "../../../TuringSimu/Common/Header/AbstractMachineUserinterface.hpp"
#include "../../UI/Header/Console.hpp"
#include "../../../TuringSimu/Business/Header/TuringMachine.hpp"
using namespace ts_common;
namespace ts_cliui_business
{
	class ConsoleController : AbstractMachineUserinterface
	{
		private:
			std::unique_ptr<AbstractMachine> machine;
			std::deque<char> tape;
			size_t position = 0;
			std::string currentState;
			char blank = 0;
			enum class SpecialCommand { None, Exit };

			/**
			 * \brief Only purpose of this mutex is to force a memory barrier.
			 */
			std::mutex memoryBarrierForcer;

		public:
			ConsoleController();
			void Start();

		private:
			SpecialCommand PrintMenu();
		static void ChangeLanguage();
			void ReadInMachine();
			void InitAndExecuteMachine();
			void NotifyInvalidMachineDefinition(const std::string& errorMessage) override;
			void NotifyInitialized(const std::string& tapeInput, const std::string& initialState) override;
			void ExecuteMachine(bool autoRun);
			void NotifyTapeWritten(char written) override;
			void NotifyHeadMoved(HeadDirection direction) override;
			void NotifyStateChanged(const std::string& newState) override;
			void HandleMoveHeadLeft();
			void HandleMoveHeadRight();
			void PrintTape();
	};
}
#endif // TMS_COMMANDLINEMACHINEUI
