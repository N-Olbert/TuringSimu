#ifndef TM_MACHINEEXECUTIONCONSOLECONTROLLER
#define TM_MACHINEEXECUTIONCONSOLECONTROLLER
#include "../../../TuringSimuCommon/Common/Header/AbstractMachine.hpp"
#include "../../../TuringSimuCommon/UI/Header/MachineUIExecutionData.hpp"
#include <mutex>

using namespace ts_common;
using namespace ts_ui;

namespace ts_ui_business
{
	class MachineExecutionController : AbstractMachineUserinterface
	{
		private:
			/**
			* \brief Only purpose of this mutex is to force a memory barrier before (and after)
			* we switch to a different thread for machine execution.
			*/
			std::mutex memoryBarrierForcer;
		protected:
			AbstractMachine* machine;
			std::unique_ptr<MachineUIExecutionData> executionData;
			static const char WhiteSpace = ' ';
			static const char TapeHeaderChar = '|';
		public:
			MachineExecutionController(AbstractMachine* machine);
			virtual ~MachineExecutionController() = default;
			virtual void PrintMachineExecutionState() = 0;
			virtual void PrintLoadedMachine() = 0;
			virtual void InitAndExecuteMachine() = 0;
			void AwaitMachineExecution(bool autoRun);
			void OnInitialized() override;
			void OnTapeWritten(char written) override;
			void OnHeadMoved(HeadDirection direction) override;
			void OnStateChanged(const State& newState) override;
			virtual void OnBeforeNextExecutionStep(bool autoRun) {};
			virtual void OnAfterMachineExecution() {};

		private:
			void ExecuteMachine(bool autoRun);
	};
}
#endif // TM_MACHINEEXECUTIONCONSOLECONTROLLER
