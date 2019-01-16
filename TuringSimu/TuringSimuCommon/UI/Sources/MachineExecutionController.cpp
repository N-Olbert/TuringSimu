#include "../Header/MachineExecutionController.hpp"
#include "../../../TuringSimu/Business/Header/MachineFactory.hpp"
#include "../../../TuringSimuCommon/UI/Header/UIExecutionDataFactory.hpp"

using namespace ts_common;
using namespace ts_ui;
using namespace ts_ui_business;

MachineExecutionController::MachineExecutionController(AbstractMachine* machine)
{
	this->machine = machine;
	this->machine->SetObservingUI(this);
	this->executionData = UIExecutionDataFactory::GetUIExecutionData(this->machine);
}

void MachineExecutionController::OnInitialized()
{
	this->executionData->HandleInitialized(this->machine);
}

void MachineExecutionController::OnTapeWritten(char written)
{
	this->executionData->HandleTapeWritten(written);
}

void MachineExecutionController::OnHeadMoved(HeadDirection direction)
{
	this->executionData->HandleHeadMoved(direction);
}

void MachineExecutionController::OnStateChanged(const State& newState)
{
	this->executionData->HandleStateChanged(newState);
}

void MachineExecutionController::AwaitMachineExecution(bool autoRun)
{
	std::thread{ &MachineExecutionController::ExecuteMachine, this, autoRun }.join();
}

void MachineExecutionController::ExecuteMachine(bool autoRun)
{
	std::lock_guard<std::mutex> memBarrier{ memoryBarrierForcer };
	this->cancellationRequested = false;
	ShowMachineExecutionState();
	while (!this->machine->IsFinished() && !this->cancellationRequested)
	{
		OnBeforeNextExecutionStep(autoRun);
		this->machine->PerformNextStep();
	}

	OnAfterMachineExecution();
}
