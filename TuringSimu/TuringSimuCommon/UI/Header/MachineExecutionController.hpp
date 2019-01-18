#ifndef TM_MACHINEEXECUTIONCONSOLECONTROLLER
#define TM_MACHINEEXECUTIONCONSOLECONTROLLER
#include "../../../TuringSimuCommon/Common/Header/AbstractMachine.hpp"
#include "../../../TuringSimuCommon/UI/Header/MachineUIExecutionData.hpp"
#include <mutex>
#include <atomic>

using namespace ts_common;
using namespace ts_ui;

namespace ts_ui_business
{
	/**
	 * \brief A base class for all execution controllers.
	 */
	class MachineExecutionController : AbstractMachineUserinterface {
	private:
		/**
		* \brief Only purpose of this mutex is to force a memory barrier before (and after)
		* we switch to a different thread for machine execution.
		*/
		std::mutex memoryBarrierForcer;

	protected:
		//initializer list, since copy-constructor is deleted
		std::atomic_bool cancellationRequested = { false };

		/**
		 * \brief The machine which should be executed by this controller.
		 */
		AbstractMachine* machine;

		/**
		 * \brief The data of the current execution process.
		 */
		std::unique_ptr<MachineUIExecutionData> executionData;
		static const char WhiteSpace = ' ';
		static const char TapeHeaderChar = '|';

	public:
		MachineExecutionController(AbstractMachine* machine);

		/**
		 * \brief Displays the current execution state of the machine.
		 */
		virtual void ShowMachineExecutionState() = 0;

		/**
		 * \brief Displays the loaded machine itself (-> its definition)
		 */
		virtual void ShowLoadedMachine() = 0;

		/**
		 * \brief Initializes and executes the machine.
		 */
		virtual void InitAndExecuteMachine() = 0;

		/**
		 * \brief Awaits till the machine execution finishes.
		 */
		virtual void AwaitMachineExecution(bool autoRun);

		/**
		 * \brief Called before the next operation is executed by the machine
		 * \param autoRun -
		 */
		virtual void OnBeforeNextExecutionStep(bool autoRun) { /* Not using: autoRun*/ }

		/**
		 * \brief Called after machine execution finishes
		 */
		virtual void OnAfterMachineExecution() {}

		/**
		 * \brief Requests and cancellation of the current execution
		 */
		virtual void CancelExecution() {}

		//Overrides

		void OnInitialized() override;
		virtual void OnTransitionChoosen(const BaseTransition& transition) override {}
		void OnTapeWritten(char written) override;
		void OnHeadMoved(HeadDirection direction) override;
		void OnStateChanged(const State& newState) override;

	private:
		void ExecuteMachine(bool autoRun);
	};
}
#endif // TM_MACHINEEXECUTIONCONSOLECONTROLLER
