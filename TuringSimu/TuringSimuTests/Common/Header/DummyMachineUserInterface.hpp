#pragma once
#ifndef TMST_DUMMYMACHINEUSERINTERFACE
#define TMST_DUMMYMACHINEUSERINTERFACE
#include "../../../TuringSimu/Common/Header/AbstractMachineUserinterface.hpp"

using namespace ts_common;
namespace ts_common
{
	class DummyMachineUserInterface : public AbstractMachineUserinterface
	{
	public:
		size_t StateChanges;
		void NotifyInvalidMachineDefinition(const std::string& errorMessage) override;
		void NotifyInitialized(const std::string& tapeInput, const std::string& initialState) override;
		void NotifyTapeWritten(char written) override;
		void NotifyHeadMoved(HeadDirection direction) override;
		void NotifyStateChanged(const std::string& newState) override;
		~DummyMachineUserInterface() = default;
	};
}
#endif // TMST_DUMMYMACHINEUSERINTERFACE
