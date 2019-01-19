#pragma once
#ifndef TMS_NONDETERMINISTICTURINGMACHINEEXECUTIONDATA
#define TMS_NONDETERMINISTICTURINGMACHINEEXECUTIONDATA
#include <string>
#include <deque>
#include "TuringMachineUIExecutionData.hpp"

using namespace ts_common;
using namespace ts_ui;

namespace ts_ui
{
	//We cant use the normal TuringMachineUIExecutionData if we encounter backtracking, which is why this class exists.
	//Reason is:
	//In order to support backtracking, we would also have to create and manage a history of the executed actions 
	//within the UIExecutionData. This is too complex! For this reason we always query the current value from the machine 
	//in case of non determinism. This isn't very good in terms of performance (as these queried values 
	//are always copies), but it doesn't matter at all for the UI.
	class NonDeterministicTuringMachineUIExecutionData : public TuringMachineUIExecutionData
	{
		private:
			static const size_t TapeFillup = 4;
			AbstractMachine* machine = nullptr;

		public:
			const std::deque<char>& GetTape() const override;
			size_t GetPosition() const override;
			const State& GetCurrentState() const override;
			char GetBlank() const override;
			size_t GetStepsCounter() const override;

			void HandleInitialized(AbstractMachine* machine) override;
			void HandleTapeWritten(char written) override;
			void HandleHeadMoved(HeadDirection direction) override;
			void HandleStateChanged(const State& newState) override;
	};
}
#endif // TMS_NONDETERMINISTICTURINGMACHINEEXECUTIONDATA