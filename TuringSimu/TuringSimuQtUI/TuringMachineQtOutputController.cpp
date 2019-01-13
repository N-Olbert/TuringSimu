#include "TuringMachineQtOutputController.hpp"
#include "../TuringSimuCommon/UI/Header/TuringMachineUIExecutionData.hpp"
#include <QThread>


TuringMachineQtOutputController::TuringMachineQtOutputController(AbstractMachine* machine, TuringSimuQtPresenter* presenter)
: MachineExecutionController(machine), presenter(presenter)
{
}

void TuringMachineQtOutputController::OnError(const std::string& errorMessage)
{
}

void TuringMachineQtOutputController::OnBacktraceDifferentExecutionPathChosen()
{
}

void TuringMachineQtOutputController::PrintMachineExecutionState()
{
	//Doesnt make sense here
}

void TuringMachineQtOutputController::PrintLoadedMachine()
{
	//Doesnt make sense here
}

void TuringMachineQtOutputController::InitAndExecuteMachine()
{
	auto initialContent = this->presenter->GetInitialTapeContent();
	this->machine->InitMachineForExecution(initialContent);
	AwaitMachineExecution(true);
}

void TuringMachineQtOutputController::OnInitialized()
{
	this->executionData->HandleInitialized(this->machine);
	const auto execData = dynamic_cast<TuringMachineUIExecutionData*>(this->executionData.get());
	auto& tape = execData->GetTape();
	this->presenter->DisplayTapeSequence(std::string{ tape.begin(), tape.end() });
	this->presenter->SetTapeHeaderVisibleAt(execData->GetPosition());
	this->presenter->DisplayCurrentState(execData->GetCurrentState().ToString());
	this->presenter->DisplayCurrentChar(execData->GetTape()[execData->GetPosition()]);
}

void TuringMachineQtOutputController::OnTapeWritten(char written)
{
	this->executionData->HandleTapeWritten(written);
	const auto execData = dynamic_cast<TuringMachineUIExecutionData*>(this->executionData.get());
	auto& tape = execData->GetTape();
	this->presenter->DisplayTapeSequence(std::string{tape.begin(), tape.end()});
}

void TuringMachineQtOutputController::OnHeadMoved(HeadDirection direction)
{
	this->executionData->HandleHeadMoved(direction);
	const auto execData = dynamic_cast<TuringMachineUIExecutionData*>(this->executionData.get());
	this->presenter->SetTapeHeaderVisibleAt(execData->GetPosition());
	this->presenter->DisplayCurrentChar(execData->GetTape()[execData->GetPosition()]);
}

void TuringMachineQtOutputController::AwaitMachineExecution(bool autoRun)
{
	QThread dummy;
	if(this->executorThread == nullptr)
	{
		this->executorThread = std::make_unique<std::thread>( &MachineExecutionController::ExecuteMachine, this, autoRun );
	}
	//TODO
}

void TuringMachineQtOutputController::OnStateChanged(const State& newState)
{
	this->executionData->HandleStateChanged(newState);
	this->presenter->DisplayCurrentState(newState.ToString());
}

void TuringMachineQtOutputController::OnBeforeNextExecutionStep(bool autoRun)
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void TuringMachineQtOutputController::OnAfterMachineExecution()
{
	this->executorThread = nullptr;
}

