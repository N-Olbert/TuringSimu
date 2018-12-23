#include "../Header/AbstractMachineUserinterface.hpp"
using namespace ts_common;

void AbstractMachineUserinterface::NotifyInvalidMachineDefinition(AbstractMachineUserinterface* toNotify, std::string& errorMessage)
{
	if(toNotify != nullptr)toNotify->NotifyInvalidMachineDefinition(errorMessage);
}

void AbstractMachineUserinterface::NotifyInitialized(AbstractMachineUserinterface* toNotify, std::string & tapeInput, std::string& initialState)
{
	if(toNotify != nullptr)toNotify->NotifyInitialized(tapeInput, initialState);
}

void AbstractMachineUserinterface::NotifyTapeWritten(AbstractMachineUserinterface* toNotify, char written)
{
	if(toNotify != nullptr)toNotify->NotifyTapeWritten(written);
}

void AbstractMachineUserinterface::NotifyHeadMoved(AbstractMachineUserinterface* toNotify, HeadDirection direction)
{
	if(toNotify != nullptr)toNotify->NotifyHeadMoved(direction);
}

void AbstractMachineUserinterface::NotifyStateChanged(AbstractMachineUserinterface* toNotify, std::string & newState)
{
	if(toNotify != nullptr) toNotify->NotifyStateChanged(newState);
}