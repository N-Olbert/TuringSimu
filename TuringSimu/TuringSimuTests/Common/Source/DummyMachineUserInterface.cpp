#include "../Header/DummyMachineUserInterface.hpp"

void DummyMachineUserInterface::OnError(const std::string& errorMessage)
{
}

void DummyMachineUserInterface::OnInitialized()
{
}

void DummyMachineUserInterface::OnTapeWritten(char written)
{
}

void DummyMachineUserInterface::OnHeadMoved(HeadDirection direction)
{
}

void DummyMachineUserInterface::OnStateChanged(const State& newState)
{
	StateChanges++;
}