#ifndef TM_TURINGMACHINECONSOLEOUTPUTCONTROLLER
#define TM_TURINGMACHINECONSOLEOUTPUTCONTROLLER
#include "../../../TuringSimuCommon/UI/Header/MachineExecutionController.hpp"

namespace ts_ui_business
{
	class TuringMachineConsoleOutputController : public MachineExecutionController
	{
		public:
			TuringMachineConsoleOutputController(AbstractMachine* machine) : MachineExecutionController(machine) {};
			void PrintMachineExecutionState() override;
			void PrintLoadedMachine() override;
			void InitAndExecuteMachine() override;
			void OnStateChanged(const State& newState) override;
			void OnError(const std::string& errorMessage) override;
			void OnBeforeNextExecutionStep(bool autoRun) override;
			void OnAfterMachineExecution() override;
	};
}
#endif // TM_TURINGMACHINECONSOLEOUTPUTCONTROLLER
