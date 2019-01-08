#ifndef TM_TURINGMACHINELOGFILEOUTPUTCONTROLLER
#define TM_TURINGMACHINELOGFILEOUTPUTCONTROLLER
#include "../../../TuringSimuCommon/UI/Header/MachineExecutionController.hpp"

namespace ts_ui_business
{
	class TuringMachineLogfileOutputController : public MachineExecutionController
	{
		private:
			const char LineFeed = '\n';
			std::string logFilePath;
			std::string stringBuilder;
		public:
			TuringMachineLogfileOutputController(AbstractMachine* machineFilePath);
			void PrintMachineExecutionState() override;
			void PrintLoadedMachine() override;
			void InitAndExecuteMachine() override;
			void OnStateChanged(const State& newState) override;
			void OnError(const std::string& errorMessage) override;
			void OnAfterMachineExecution() override;
	};
}
#endif // TM_TURINGMACHINELOGFILEOUTPUTCONTROLLER