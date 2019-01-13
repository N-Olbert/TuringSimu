#include "../../TuringSimu/Business/Header/MachineFactory.hpp"
#include "TuringSimuQtPresenter.hpp"
#include "../TuringSimuCommon/UI/Header/MachineExecutionControllerFactory.hpp"
#include "TuringMachineQtOutputController.hpp"
#include <QThread>


TuringSimuQtPresenter::TuringSimuQtPresenter(AbstractTuringSimuQtForm* view, QObject *parent)
    : QObject(parent), view(view), model(nullptr)
{
	const auto view_obj = dynamic_cast<QObject*>(view);
    connect(view_obj, SIGNAL(LoadFileButtonClicked()), this, SLOT(HandleLoadFileButtonClicked()));
	connect(view_obj, SIGNAL(RunButtonClicked()), this, SLOT(HandleRunButtonClicked()));
	connect(view_obj, SIGNAL(ResetButtonClicked()), this, SLOT(HandleResetButtonClicked()));
	connect(view_obj, SIGNAL(StepButtonClicked()), this, SLOT(HandleStepButtonClicked()));
	connect(view_obj, SIGNAL(InitialTapeContentChanged()), this, SLOT(HandleInitialTapeContentChanged()));

	this->view->SetEnableInitialTapeContentInput(false);
	this->view->SetEnableResetButton(false);
	this->view->SetEnableRunButton(false);
	this->view->SetEnableStepButton(false);
	this->view->SetEnableMachineExecutionControls(false);
}

void TuringSimuQtPresenter::DisplayTapeSequence(std::string toDisplay)
{
	this->view->DisplayTapeSequence(toDisplay);
}

void TuringSimuQtPresenter::SetTapeHeaderVisibleAt(size_t pos)
{
	this->view->SetTapeHeaderVisibleAt(pos);
}

std::string TuringSimuQtPresenter::GetInitialTapeContent()
{
	return this->view->GetInitialTapeContent();
}

void TuringSimuQtPresenter::DisplayCurrentState(const std::string& currentState)
{
	this->view->DisplayCurrentState(currentState);
}

void TuringSimuQtPresenter::DisplayCurrentChar(char toDisplay)
{
	this->view->DisplayCurrentChar(toDisplay);
}

void TuringSimuQtPresenter::HandleLoadFileButtonClicked()
{
    const auto path = this->view->GetFilePath();
	auto machine = ts_business::MachineFactory::CreateMachineFromFile(MachineType::DTM, path);
	if(machine != nullptr)
	{
		this->currentMachine = std::move(machine);
		this->model = std::make_unique<TuringMachineQtOutputController>(this->currentMachine.get(), this);
		this->view->SetEnableMachineExecutionControls(true);
		this->view->SetEnableInitialTapeContentInput(true);
	}
}

void TuringSimuQtPresenter::HandleRunButtonClicked()
{
	this->view->SetEnableResetButton(true);
	this->view->SetEnableStepButton(false);
	this->view->SetEnableInitialTapeContentInput(false);
	if(this->currentMachine != nullptr)
	{
		this->model->InitAndExecuteMachine();
	}
}

void TuringSimuQtPresenter::HandleStepButtonClicked()
{
	this->view->SetEnableResetButton(true);
	this->view->SetEnableRunButton(false);
}

void TuringSimuQtPresenter::HandleResetButtonClicked()
{
	this->view->SetEnableInitialTapeContentInput(true);
	this->view->SetEnableResetButton(false);
	this->view->SetEnableRunButton(true);
	this->view->SetEnableStepButton(true);
}

void TuringSimuQtPresenter::HandleInitialTapeContentChanged()
{
	if(this->currentMachine != nullptr)
	{
		auto input = GetInitialTapeContent();
		this->currentMachine->InitMachineForExecution(input);
		this->model->OnInitialized();
		this->view->SetEnableResetButton(false);
		this->view->SetEnableRunButton(true);
		this->view->SetEnableStepButton(true);
	}
}
