#ifndef TM_TURINGMACHINECONSOLEOUTPUTCONTROLLER
#define TM_TURINGMACHINECONSOLEOUTPUTCONTROLLER
#include "../../../TuringSimuCommon/UI/Header/MachineExecutionController.hpp"

namespace ts_ui_business
{
	/**
	 * \brief Impelementation of MachineExecutionController which handles the console output of a turing machine
	 */
	class TuringMachineConsoleOutputController : public MachineExecutionController
	{
		////Overrides
		public:
			TuringMachineConsoleOutputController(AbstractMachine* machine) : MachineExecutionController(machine) {};
			void ShowMachineExecutionState() override;
			void ShowLoadedMachine() override;
			void InitAndExecuteMachine() override;
			void OnStateChanged(const State& newState) override;
			void OnBacktraceDifferentExecutionPathChosen() override;
			void OnError(const std::string& errorMessage) override;
			void OnBeforeNextExecutionStep(bool autoRun) override;
			void OnAfterMachineExecution() override;
	};
}
#endif // TM_TURINGMACHINECONSOLEOUTPUTCONTROLLER
