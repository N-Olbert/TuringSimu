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
	class NonDeterministicTuringMachineUIExecutionData : public TuringMachineUIExecutionData
	{
		private:
			static const size_t TapeFillup = 4;
			AbstractMachine* machine;

		public:
			virtual const std::deque<char>& GetTape() const;
			virtual size_t GetPosition() const;
			virtual const State& GetCurrentState() const;
			virtual char GetBlank() const;
			virtual size_t GetStepsCounter() const;

			void HandleInitialized(AbstractMachine* machine) override;
			void HandleTapeWritten(char written) override;
			void HandleHeadMoved(HeadDirection direction) override;
			void HandleStateChanged(const State& newState) override;
	};
}
#endif // TMS_NONDETERMINISTICTURINGMACHINEEXECUTIONDATA