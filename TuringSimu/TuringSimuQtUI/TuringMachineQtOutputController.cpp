#include "TuringMachineQtOutputController.hpp"
#include "../TuringSimuCommon/UI/Header/TuringMachineUIExecutionData.hpp"


TuringMachineQtOutputController::TuringMachineQtOutputController(AbstractMachine* machine, TuringSimuQtPresenter* presenter)
: MachineExecutionController(machine), presenter(presenter)
{
	this->typedExecutionData = dynamic_cast<TuringMachineUIExecutionData*>(this->executionData.get());
}


void TuringMachineQtOutputController::OnError(const std::string& errorMessage)
{
}

void TuringMachineQtOutputController::OnBacktraceDifferentExecutionPathChosen()
{
	//TODO, that's (and the display of the transition table) is the reason why non determinism isn't fully supported
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
	auto& tape = this->typedExecutionData->GetTape();
	auto tapeStr = std::string{ tape.begin(), tape.end() };
	this->presenter->DisplayTapeSequence(tapeStr, this->typedExecutionData->GetPosition());
	this->presenter->SetTapeHeaderVisibleAt(this->typedExecutionData->GetPosition(), tapeStr);
	this->presenter->DisplayCurrentState(this->typedExecutionData->GetCurrentState().ToString());
	this->presenter->DisplayCurrentChar(this->typedExecutionData->GetTape()[this->typedExecutionData->GetPosition()]);
	this->presenter->DisplayCurrentStep(0);
}

void TuringMachineQtOutputController::OnTransitionChoosen(const BaseTransition& transition)
{
	this->presenter->HighlightTransition(transition);
}

void TuringMachineQtOutputController::OnTapeWritten(char written)
{
	this->executionData->HandleTapeWritten(written);
	auto& tape = this->typedExecutionData->GetTape();
	auto tapeStr = std::string{ tape.begin(), tape.end() };
	this->presenter->DisplayTapeSequence(tapeStr, this->typedExecutionData->GetPosition());
}

void TuringMachineQtOutputController::OnHeadMoved(HeadDirection direction)
{
	this->executionData->HandleHeadMoved(direction);
	auto& tape = this->typedExecutionData->GetTape();
	auto tapeStr = std::string{ tape.begin(), tape.end() };
	this->presenter->SetTapeHeaderVisibleAt(this->typedExecutionData->GetPosition(), tapeStr);
	this->presenter->DisplayCurrentChar(this->typedExecutionData->GetTape()[this->typedExecutionData->GetPosition()]);
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

	this->presenter->DisplayCurrentStep(this->typedExecutionData->GetStepsCounter());
}

void TuringMachineQtOutputController::OnAfterMachineExecution()
{
	this->presenter->ExitSeparateThreadExecutionMode();
}

void TuringMachineQtOutputController::CancelExecution()
{
	this->cancellationRequested = true;
}

