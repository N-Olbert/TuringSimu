#include "../Header/TuringMachineUIExecutionData.hpp"
#include "../../../TuringSimuCLI/UI/Header/Console.hpp"
#include "../../Common/Header/AbstractMachine.hpp"

using namespace ts_common;
using namespace ts_ui;

const std::deque<char>& TuringMachineUIExecutionData::GetTape() const
{
	return tape;
}

size_t TuringMachineUIExecutionData::GetPosition() const
{
	return position;
}

const State& TuringMachineUIExecutionData::GetCurrentState() const
{
	return currentState;
}

char TuringMachineUIExecutionData::GetBlank() const
{
	return blank;
}

size_t TuringMachineUIExecutionData::GetStepsCounter() const
{
	return stepsCounter;
}

void TuringMachineUIExecutionData::HandleInitialized(AbstractMachine* machine)
{
	this->blank = machine->GetSpecificValue(SpecificMachineValue::Blank)->As<char>();
	this->currentState = machine->GetSpecificValue(SpecificMachineValue::InitialState)->As<State>();
	this->tape.clear();
	for (auto i = 0; i < 5; ++i)
	{
		this->tape.push_back(this->blank);
	}

	auto initialTapeContent = machine->GetSpecificValue(SpecificMachineValue::TapeContent)->As<std::string>();
	for (char c : initialTapeContent)
	{
		this->tape.push_back(c);
	}

	for (auto i = 0; i < 5; ++i)
	{
		this->tape.push_back(this->blank);
	}

	this->position = 5;
	this->stepsCounter = 0;
}

void TuringMachineUIExecutionData::HandleTapeWritten(char written)
{
	this->tape[this->position] = written;
}

void TuringMachineUIExecutionData::HandleHeadMoved(HeadDirection direction)
{
	switch (direction)
	{
		case Left:
			HandleMoveHeadLeft();
			break;
		case Right:
			HandleMoveHeadRight();
			break;
		case Stay: break;
	}

	this->stepsCounter++;
}

void TuringMachineUIExecutionData::HandleStateChanged(const State& newState)
{
	this->currentState = newState;
}

void TuringMachineUIExecutionData::HandleMoveHeadLeft()
{
	if (this->position == 4)
	{
		this->tape.push_front(this->blank);
	}
	else
	{
		this->position--;
	}
}

void TuringMachineUIExecutionData::HandleMoveHeadRight()
{
	if (this->position + 5 >= this->tape.size())
	{
		this->tape.push_back(this->blank);
	}

	this->position++;
}
