#pragma once
#ifndef TM_ABSTRACTMACHINEUSERINTERFACE
#define TM_ABSTRACTMACHINEUSERINTERFACE
#include <string>
#include "HeadDirection.hpp"
#include "State.hpp"
#include "ErrorDisplayableUserinterface.hpp"

namespace ts_common
{
	/**
	 * \brief Abstract base class for all userinterfaces which should be used to receive events from
	 * machine execution.
	 */
	class AbstractMachineUserinterface : public ErrorDisplayableUserinterface
	{
		public:
		virtual ~AbstractMachineUserinterface() = default;
		virtual void OnInitialized() = 0;
		virtual void OnTapeWritten(char written) = 0;
		virtual void OnHeadMoved(HeadDirection direction) = 0; 
		virtual void OnStateChanged(const State& newState) = 0;
		virtual void OnBacktraceDifferentExecutionPathChosen() = 0;
		static void NotifyInitialized(AbstractMachineUserinterface* toNotify);
		static void NotifyTapeWritten(AbstractMachineUserinterface* toNotify, char written);
		static void NotifyHeadMoved(AbstractMachineUserinterface* toNotify, HeadDirection direction);
		static void NotifyStateChanged(AbstractMachineUserinterface* toNotify, const State& newState);
		static void NotifyBacktraceDifferentExecutionPathChosen(AbstractMachineUserinterface* toNotify);
	};
}
#endif // TM_ABSTRACTMACHINEUSERINTERFACE
