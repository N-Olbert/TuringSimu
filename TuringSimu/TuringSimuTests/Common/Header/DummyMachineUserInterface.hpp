#pragma once
#ifndef TMST_DUMMYMACHINEUSERINTERFACE
#define TMST_DUMMYMACHINEUSERINTERFACE
#include "../../../TuringSimuCommon/Common/Header/AbstractMachineUserinterface.hpp"

using namespace ts_common;
namespace ts_common
{
	class DummyMachineUserInterface : public AbstractMachineUserinterface
	{
	public:
		size_t StateChanges;
		void OnError(const std::string& errorMessage) override;
		void OnInitialized() override;
		void OnTapeWritten(char written) override;
		void OnHeadMoved(HeadDirection direction) override;
		void OnStateChanged(const State& newState) override;
		~DummyMachineUserInterface() = default;
		void OnBacktraceDifferentExecutionPathChosen() override {};
	};
}
#endif // TMST_DUMMYMACHINEUSERINTERFACE
