#include "../Header/AbstractMachineUserinterface.hpp"
using namespace ts_common;

void AbstractMachineUserinterface::NotifyInvalidMachineDefinition(AbstractMachineUserinterface* toNotify, const std::string& errorMessage)
{
	if(toNotify != nullptr)toNotify->NotifyInvalidMachineDefinition(errorMessage);
}

void AbstractMachineUserinterface::NotifyInitialized(AbstractMachineUserinterface* toNotify, const std::string& tapeInput, const std::string& initialState)
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

void AbstractMachineUserinterface::NotifyStateChanged(AbstractMachineUserinterface* toNotify, const std::string & newState)
{
	if(toNotify != nullptr) toNotify->NotifyStateChanged(newState);
}