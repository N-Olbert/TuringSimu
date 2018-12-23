#include "..\Header\DummyMachineUserInterface.hpp"

void DummyMachineUserInterface::NotifyInvalidMachineDefinition()
{
}

void DummyMachineUserInterface::NotifyInitialized(std::string& tapeInput, std::string& initialState)
{
}

void DummyMachineUserInterface::NotifyTapeWritten(char written)
{
}

void DummyMachineUserInterface::NotifyHeadMoved(HeadDirection direction)
{
}

void DummyMachineUserInterface::NotifyStateChanged(std::string& newState)
{
	StateChanges++;
}