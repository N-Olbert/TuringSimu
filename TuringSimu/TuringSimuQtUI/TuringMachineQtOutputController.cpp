#include "TuringMachineQtOutputController.hpp"
#include "../TuringSimuCommon/UI/Header/TuringMachineUIExecutionData.hpp"


TuringMachineQtOutputController::TuringMachineQtOutputController(AbstractMachine* machine, TuringSimuQtPresenter* presenter)
: MachineExecutionController(machine), presenter(presenter)
{
}


void TuringMachineQtOutputController::OnError(const std::string& errorMessage)
{
}

void TuringMachineQtOutputController::OnBacktraceDifferentExecutionPathChosen()
{
	//TODO
}

void TuringMachineQtOutputController::ShowMachineExecutionState()
{
	//Doesnt make sense here
}

void TuringMachineQtOutputController::ShowLoadedMachine()
{
	//Doesnt make sense here
}

void TuringMachineQtOutputController::InitAndExecuteMachine()
{
	auto initialContent = this->presenter->GetInitialTapeContent();
	this->machine->InitMachineForExecution(initialContent);
	AwaitMachineExecution(this->presenter->GetIsAutoRunMode());
}

void TuringMachineQtOutputController::OnInitialized()
{
	this->executionData->HandleInitialized(this->machine);
	const auto execData = dynamic_cast<TuringMachineUIExecutionData*>(this->executionData.get());
	auto& tape = execData->GetTape();
	auto tapeStr = std::string{ tape.begin(), tape.end() };
	this->presenter->DisplayTapeSequence(tapeStr, execData->GetPosition());
	this->presenter->SetTapeHeaderVisibleAt(execData->GetPosition(), tapeStr);
	this->presenter->DisplayCurrentState(execData->GetCurrentState().ToString());
	this->presenter->DisplayCurrentChar(execData->GetTape()[execData->GetPosition()]);
	this->presenter->DisplayCurrentStep(0);
}

void TuringMachineQtOutputController::OnTransitionChoosen(const BaseTransition& transition)
{
	this->presenter->HighlightTransition(transition);
}

void TuringMachineQtOutputController::OnTapeWritten(char written)
{
	this->executionData->HandleTapeWritten(written);
	const auto execData = dynamic_cast<TuringMachineUIExecutionData*>(this->executionData.get());
	auto& tape = execData->GetTape();
	auto tapeStr = std::string{ tape.begin(), tape.end() };
	this->presenter->DisplayTapeSequence(tapeStr, execData->GetPosition());
}

void TuringMachineQtOutputController::OnHeadMoved(HeadDirection direction)
{
	this->executionData->HandleHeadMoved(direction);
	const auto execData = dynamic_cast<TuringMachineUIExecutionData*>(this->executionData.get());
	auto& tape = execData->GetTape();
	auto tapeStr = std::string{ tape.begin(), tape.end() };
	this->presenter->SetTapeHeaderVisibleAt(execData->GetPosition(), tapeStr);
	this->presenter->DisplayCurrentChar(execData->GetTape()[execData->GetPosition()]);
}

void TuringMachineQtOutputController::OnStateChanged(const State& newState)
{
	this->executionData->HandleStateChanged(newState);
	this->presenter->DisplayCurrentState(newState.ToString());
}

void TuringMachineQtOutputController::OnBeforeNextExecutionStep(bool autoRun)
{
	if (this->cancellationRequested) return;
	if (autoRun)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
	else
	{
		this->presenter->AwaitClickOnStepButton();
	}

	const auto execData = dynamic_cast<TuringMachineUIExecutionData*>(this->executionData.get());
	this->presenter->DisplayCurrentStep(execData->GetStepsCounter());
}

void TuringMachineQtOutputController::OnAfterMachineExecution()
{
	this->presenter->ExitSeparateThreadExecutionMode();
}

void TuringMachineQtOutputController::CancelExecution()
{
	this->cancellationRequested = true;
}

