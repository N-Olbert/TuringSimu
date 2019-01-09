#include "..\Header\NonDeterministicTuringMachineUIExecutionData.hpp"

const std::deque<char>& ts_ui::NonDeterministicTuringMachineUIExecutionData::GetTape() const
{
	auto content = this->machine->GetSpecificValue(SpecificMachineValue::TapeContent)->As<std::string>();
	auto blank = GetBlank();

	// !!! Unsafe block !!!
	// Reviewed, by definiton we must return a reference, so this is the quick and dirty way to ensure that
	const_cast<std::deque<char>&>(this->tape).clear();
	for (size_t i = 0; i < TapeFillup; i++)
	{
		const_cast<std::deque<char>&>(this->tape).push_back(blank);
	}

	for (char c : content)
	{
		const_cast<std::deque<char>&>(this->tape).push_back(c);
	}

	for (size_t i = 0; i < TapeFillup; i++)
	{
		const_cast<std::deque<char>&>(this->tape).push_back(blank);
	}

	return this->tape;
}

size_t ts_ui::NonDeterministicTuringMachineUIExecutionData::GetPosition() const
{
	return this->machine->GetSpecificValue(SpecificMachineValue::CurrentHeadPositon)->As<size_t>() + TapeFillup;
}

const State& NonDeterministicTuringMachineUIExecutionData::GetCurrentState() const
{
	// !!!Unsafe block !!!
	// Reviewed, same as above
	const_cast<State&>(this->currentState) = this->machine->GetSpecificValue(SpecificMachineValue::CurrentState)->As<State>();
	return this->currentState;
}

char NonDeterministicTuringMachineUIExecutionData::GetBlank() const
{
	return this->machine->GetSpecificValue(SpecificMachineValue::Blank)->As<char>();
}

size_t NonDeterministicTuringMachineUIExecutionData::GetStepsCounter() const
{
	return this->stepsCounter;
}

void NonDeterministicTuringMachineUIExecutionData::HandleInitialized(AbstractMachine * machine)
{
	this->machine = machine;
}

void NonDeterministicTuringMachineUIExecutionData::HandleTapeWritten(char written)
{
}

void NonDeterministicTuringMachineUIExecutionData::HandleHeadMoved(HeadDirection direction)
{
	this->stepsCounter++;
}

void NonDeterministicTuringMachineUIExecutionData::HandleStateChanged(const State & newState)
{
}
