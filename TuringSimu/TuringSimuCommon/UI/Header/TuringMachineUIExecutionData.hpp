#pragma once
#ifndef TMS_TURINGMACHINEEXECUTIONDATA
#define TMS_TURINGMACHINEEXECUTIONDATA
#include <string>
#include <deque>
#include "MachineUIExecutionData.hpp"
#include "../../Common/Header/AbstractMachine.hpp"
#include <fstream>

namespace ts_ui
{
	class TuringMachineUIExecutionData : public MachineUIExecutionData
	{
		protected:
			std::deque<char> tape;
			size_t position = 0;
			State currentState;
			char blank = 0;
			size_t stepsCounter = 0;
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
		private:
			void HandleMoveHeadLeft();
			void HandleMoveHeadRight();
	};
}
#endif // TMS_TURINGMACHINEEXECUTIONDATA
