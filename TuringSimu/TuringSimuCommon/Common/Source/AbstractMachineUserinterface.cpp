#include "../Header/AbstractMachineUserinterface.hpp"
#include "../Header/BaseTransition.hpp"
using namespace ts_common;

void AbstractMachineUserinterface::NotifyInitialized(AbstractMachineUserinterface* toNotify)
{
	if(toNotify != nullptr)toNotify->OnInitialized();
}

void AbstractMachineUserinterface::NotifyTransitionChoosen(AbstractMachineUserinterface* toNotify, const BaseTransition& transition)
{
	if (toNotify != nullptr)toNotify->OnTransitionChoosen(transition);
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

void AbstractMachineUserinterface::NotifyBacktraceDifferentExecutionPathChosen(AbstractMachineUserinterface * toNotify)
{
	if (toNotify != nullptr) toNotify->OnBacktraceDifferentExecutionPathChosen();
}
