#pragma once
#ifndef TURINGMACHINEQTOUTPUTCONTROLLER_HPP
#define TURINGMACHINEQTOUTPUTCONTROLLER_HPP
#include "../TuringSimuCommon/UI/Header/MachineExecutionController.hpp"
#include "TuringSimuQtPresenter.hpp"
#include <thread>
using namespace ts_ui_business;

class TuringMachineQtOutputController : public MachineExecutionController
{
	private: 
		TuringSimuQtPresenter* presenter;
	
	public:
		TuringMachineQtOutputController(AbstractMachine* machine, TuringSimuQtPresenter* presenter);
		void OnError(const std::string& errorMessage) override;
		void OnBacktraceDifferentExecutionPathChosen() override;
		void ShowMachineExecutionState() override;
		void ShowLoadedMachine() override;
		void InitAndExecuteMachine() override;
		void OnInitialized() override;
		void OnTransitionChoosen(const BaseTransition& transition) override;
		void OnTapeWritten(char written) override;
		void OnHeadMoved(HeadDirection direction) override;
		void OnStateChanged(const State& newState) override;
		void OnBeforeNextExecutionStep(bool autoRun) override;
		void OnAfterMachineExecution() override;
		void CancelExecution() override;
};

#endif // TURINGMACHINEQTOUTPUTCONTROLLER_HPP
