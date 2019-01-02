#include "..\Header\DummyMachineUserInterface.hpp"

void DummyMachineUserInterface::NotifyInvalidMachineDefinition(const std::string& errorMessage)
{
}

void DummyMachineUserInterface::NotifyInitialized(const std::string& tapeInput, const std::string& initialState)
{
}

void DummyMachineUserInterface::NotifyTapeWritten(char written)
{
}

void DummyMachineUserInterface::NotifyHeadMoved(HeadDirection direction)
{
}

void DummyMachineUserInterface::NotifyStateChanged(const std::string& newState)
{
	StateChanges++;
}