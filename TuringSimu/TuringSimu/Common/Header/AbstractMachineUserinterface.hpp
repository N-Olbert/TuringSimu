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
		virtual void NotifyInvalidMachineDefinition(std::string& errorMessage) = 0;
		virtual void NotifyInitialized(std::string& tapeInput, std::string& initialState) = 0;
		virtual void NotifyTapeWritten(char written) = 0;
		virtual void NotifyHeadMoved(HeadDirection direction) = 0; 
		virtual void NotifyStateChanged(std::string& newState) = 0;
		static void NotifyInvalidMachineDefinition(AbstractMachineUserinterface* toNotify, std::string& errorMessage);
		static void NotifyInitialized(AbstractMachineUserinterface* toNotify, std::string& tapeInput, std::string& initialState);
		static void NotifyTapeWritten(AbstractMachineUserinterface* toNotify,char written);
		static void NotifyHeadMoved(AbstractMachineUserinterface* toNotify,HeadDirection direction);
		static void NotifyStateChanged(AbstractMachineUserinterface* toNotify, std::string& newState);
	};
}
#endif // TM_ABSTRACTMACHINEUSERINTERFACE
