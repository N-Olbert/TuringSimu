#pragma once
#include "../TuringSimuCommon/UI/Header/MachineExecutionController.hpp"
#include "TuringSimuQtPresenter.hpp"
#include <thread>
using namespace ts_ui_business;

class TuringMachineQtOutputController : public MachineExecutionController
{
	private: 
		TuringSimuQtPresenter* presenter;
		std::unique_ptr<std::thread> executorThread;
	public:
		TuringMachineQtOutputController(AbstractMachine* machine, TuringSimuQtPresenter* presenter);
		~TuringMachineQtOutputController() override = default;
		void OnError(const std::string& errorMessage) override;
		void OnBacktraceDifferentExecutionPathChosen() override;
		void PrintMachineExecutionState() override;
		void PrintLoadedMachine() override;
		void InitAndExecuteMachine() override;
		void OnInitialized() override;
		void OnTapeWritten(char written) override;
		void OnHeadMoved(HeadDirection direction) override;
		void AwaitMachineExecution(bool autoRun) override;
		void OnStateChanged(const State& newState) override;
		void OnBeforeNextExecutionStep(bool autoRun) override;
		void OnAfterMachineExecution() override;
};

