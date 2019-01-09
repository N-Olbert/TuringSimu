#include "../Header/NonDeterministicTuringMachine.hpp"

using namespace ts_common;
using namespace ts_business;
using AMU = AbstractMachineUserinterface;

void NonDeterministicTuringMachine::PerformNextStep()
{
	auto transitions = GetNextTransitions();
	if (transitions.size() > 0)
	{
		if (transitions.size() > 1)
		{
			//Store current state for potential backtracking
			for (size_t i = 1; i < transitions.size(); i++)
			{
				auto toAdd = TraceData{};
				toAdd.Header = std::move(std::unique_ptr<TuringMachineTapeHeader>(new TuringMachineTapeHeader{ *this->head.get() }));
				toAdd.Transiton = transitions[i];
				this->backtraceList.push_back(std::move(toAdd));
			}
		}

		const Transition* transition = transitions[0];
		if ((*transition).IsEmpty() &&
			!this->definition.finalStates.Contains(this->currentState) && this->backtraceList.size() > 0)
		{
			//Backtrace: Jump back in execution

			//Move out the element of the vector
			auto toRestore = std::move(this->backtraceList.back());

			// https://stackoverflow.com/questions/23118391/can-i-stdmove-an-element-out-of-a-stdvector
			//item in vector is now in an valid, but unspecified state -> remove it
			this->backtraceList.erase(this->backtraceList.begin() + (this->backtraceList.size() - 1));
			this->head = std::move(toRestore.Header);
			this->currentState = toRestore.Transiton->GetCurrentState();
			transition = toRestore.Transiton; 
			AMU::NotifyBacktraceDifferentExecutionPathChosen(GetUI());
		}
		
		if (!transition->IsEmpty())
		{
			const auto toWrite = transition->GetToWrite();
			this->head->WriteChar(toWrite);
			AMU::NotifyTapeWritten(GetUI(), toWrite);

			const auto moveDirection = transition->GetHeadDirection();
			this->head->Move(moveDirection);
			AMU::NotifyHeadMoved(GetUI(), moveDirection);

			auto& nextState = transition->GetNextState();
			this->currentState = nextState;
			AMU::NotifyStateChanged(GetUI(), nextState);
		}
	}
}


bool NonDeterministicTuringMachine::IsFinished() const
{
	return GetNextTransition().IsEmpty() && 
		  (this->definition.finalStates.Contains(this->currentState) || this->backtraceList.size() == 0);
}

bool NonDeterministicTuringMachine::IsFinishedSuccessfully() const
{
	return this->definition.finalStates.Contains(this->currentState) && IsFinished();
}

const std::vector<const Transition*> NonDeterministicTuringMachine::GetNextTransitions() const
{
	auto result = std::vector<const Transition*>();
	const auto currentChar = this->head->GetChar();
	auto& transitions = this->definition.transitions;
	for (size_t i = 0; i < transitions.size(); i++)
	{
		auto& transition = transitions.data()[i];
		if (transition.GetCurrentState() == this->currentState &&
			transition.GetCurrentChar() == currentChar)
		{
			result.push_back(&transition);
		}
	}

	if (result.size() == 0)
	{
		result.push_back(&Transition::Empty);
	}

	return result;
}
