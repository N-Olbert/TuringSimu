#include "../Header/AbstractMachineUserinterface.hpp"
using namespace ts_common;

void AbstractMachineUserinterface::NotifyInitialized(AbstractMachineUserinterface* toNotify)
{
	if(toNotify != nullptr)toNotify->OnInitialized();
}

void AbstractMachineUserinterface::NotifyTapeWritten(AbstractMachineUserinterface* toNotify, char written)
{
	if(toNotify != nullptr)toNotify->OnTapeWritten(written);
}

void AbstractMachineUserinterface::NotifyHeadMoved(AbstractMachineUserinterface* toNotify, HeadDirection direction)
{
	if(toNotify != nullptr)toNotify->OnHeadMoved(direction);
}

void AbstractMachineUserinterface::NotifyStateChanged(AbstractMachineUserinterface* toNotify, const State& newState)
{
	if(toNotify != nullptr) toNotify->OnStateChanged(newState);
}