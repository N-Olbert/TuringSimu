#ifndef TM_TURINGMACHINELOGFILEOUTPUTCONTROLLER
#define TM_TURINGMACHINELOGFILEOUTPUTCONTROLLER
#include "../../../TuringSimuCommon/UI/Header/MachineExecutionController.hpp"

namespace ts_ui_business
{
	/**
	 * \brief Impelementation of MachineExecutionController which handles the log file output of a turing machine
	 */
	class TuringMachineLogfileOutputController : public MachineExecutionController
	{
		private:
			/**
			 * \brief Line feed char
			 */
			static const char LineFeed = '\n';

			/**
			 * \brief The path of the log file which should be created.
			 */
			std::string logFilePath;

			/**
			 * \brief A string builder (will be written to the log file in the end).
			 */
			std::string stringBuilder;

		public:
			////Overrides
			TuringMachineLogfileOutputController(AbstractMachine* machineFilePath);
			void ShowMachineExecutionState() override;
			void ShowLoadedMachine() override;
			void InitAndExecuteMachine() override;
			void OnStateChanged(const State& newState) override;
			void OnBacktraceDifferentExecutionPathChosen() override;
			void OnError(const std::string& errorMessage) override;
			void OnAfterMachineExecution() override;
	};
}
#endif // TM_TURINGMACHINELOGFILEOUTPUTCONTROLLER