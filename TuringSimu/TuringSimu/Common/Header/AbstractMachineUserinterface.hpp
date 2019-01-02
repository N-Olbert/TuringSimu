#pragma once
#ifndef TM_ABSTRACTMACHINEUSERINTERFACE
#define TM_ABSTRACTMACHINEUSERINTERFACE
#include <string>
#include "HeadDirection.hpp"

namespace ts_common
{
	/**
	 * \brief Abstract base class for all userinterfaces.
	 */
	class AbstractMachineUserinterface
	{
		public:
		virtual ~AbstractMachineUserinterface() = default;
		virtual void NotifyInvalidMachineDefinition(const std::string& errorMessage) = 0;
		virtual void NotifyInitialized(const std::string& tapeInput, const std::string& initialState) = 0;
		virtual void NotifyTapeWritten(char written) = 0;
		virtual void NotifyHeadMoved(HeadDirection direction) = 0; 
		virtual void NotifyStateChanged(const std::string& newState) = 0;
		static void NotifyInvalidMachineDefinition(AbstractMachineUserinterface* toNotify, const std::string& errorMessage);
		static void NotifyInitialized(AbstractMachineUserinterface* toNotify, const std::string& tapeInput, const std::string& initialState);
		static void NotifyTapeWritten(AbstractMachineUserinterface* toNotify, char written);
		static void NotifyHeadMoved(AbstractMachineUserinterface* toNotify, HeadDirection direction);
		static void NotifyStateChanged(AbstractMachineUserinterface* toNotify, const std::string& newState);
	};
}
#endif // TM_ABSTRACTMACHINEUSERINTERFACE
