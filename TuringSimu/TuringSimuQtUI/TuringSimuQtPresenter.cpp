#include "../TuringSimu/Business/Header/MachineFactory.hpp"
#include "TuringSimuQtPresenter.hpp"
#include "../TuringSimuCommon/UI/Header/MachineExecutionControllerFactory.hpp"
#include "TuringMachineQtOutputController.hpp"
#include <QObject>
#include "../TuringSimuCommon/Common/Header/BaseTransition.hpp"
#include "../TuringSimuCommon/UI/Header/Localization.hpp"

using namespace ts_common;
TuringSimuQtPresenter::~TuringSimuQtPresenter()
{
	if (this->EXECUTING)
	{
		this->model->CancelExecution();
		AwaitExceutionCompleted();
	}
}


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

void TuringSimuQtPresenter::DisplayTapeSequence(std::string& toDisplay, size_t pos) const
{
	//AdjustTapeSize(toDisplay, pos);
}

void TuringSimuQtPresenter::AdjustTapeForView(std::string &toDisplay, size_t pos) const
{
	auto optimalSize = this->view->GetAmountOfDisplayedTapeLetters();
	auto blank = toDisplay[0];
	while (toDisplay.size() < optimalSize)
	{
		toDisplay.push_back(blank); // Fill up
	}

	if (toDisplay.size() > optimalSize)
	{
		//Remove unneccesarry blanks at the end
		for (size_t j = toDisplay.size() - 2; j >= 1 && j > pos && toDisplay.size() > optimalSize; j--)
		{
			if (toDisplay[j] == blank)
			{
				toDisplay.pop_back();
			}
			else
			{
				break;
			}
		}

		//Remove unneccesarry blanks at the begin
		for (size_t j = 0; j < toDisplay.size() && toDisplay.size() > optimalSize; j++)
		{
			if (toDisplay[j] == blank && pos > 1)
			{
				toDisplay = toDisplay.substr(1, toDisplay.size() - 1);
				pos--;
				j--;
			}
			else
			{
				break;
			}
		}

		if (toDisplay.size() > optimalSize)
		{
			//still to long -> curtail
			if (pos >= optimalSize)
			{
				pos -= toDisplay.size() - optimalSize;
				toDisplay = toDisplay.substr(toDisplay.size() - optimalSize, optimalSize);
			}
			else
			{
				toDisplay = toDisplay.substr(0, optimalSize);
			}
		}
	}

	this->view->SetTapeHeaderVisibleAt(pos);
	this->view->DisplayTapeSequence(toDisplay);
}

void TuringSimuQtPresenter::SetTapeHeaderVisibleAt(size_t pos, std::string& tape)
{
    AdjustTapeForView(tape, pos);
}

std::string TuringSimuQtPresenter::GetInitialTapeContent() const
{
	return this->view->GetInitialTapeContent();
}

void TuringSimuQtPresenter::DisplayCurrentState(const std::string& currentState) const
{
	this->view->DisplayCurrentState(currentState);
}

void TuringSimuQtPresenter::DisplayCurrentChar(char toDisplay) const
{
	this->view->DisplayCurrentChar(toDisplay);
}

void TuringSimuQtPresenter::ExitSeparateThreadExecutionMode()
{
	this->EXECUTING = false;
	if (!disposing)
	{
		this->HandleResetButtonClicked();
	}
}

void TuringSimuQtPresenter::AwaitClickOnStepButton()
{
	this->clickOnStepButtonOccured = false;
	this->listeningForStepButtonClick = true;
	while (!this->autoRunMode && !this->clickOnStepButtonOccured)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}

bool TuringSimuQtPresenter::GetIsAutoRunMode() const
{
	return this->autoRunMode;
}

void TuringSimuQtPresenter::StartMachineExecution(bool autoRun)
{
	if (!this->EXECUTING && this->currentMachine != nullptr)
	{
		//this is the only critial area, everything else can be controller by atomic booleans
		std::lock_guard<std::mutex> lock(this->presenterMutex); 

		//double check
		if(!this->EXECUTING)
		{
			this->EXECUTING = true; //The critical flag
			this->view->SetEnableResetButton(true);
			this->view->SetEnableInitialTapeContentInput(false);
			this->view->SetEnableStepButton(!autoRun);
			this->view->SetEnableRunButton(false);
			this->autoRunMode = autoRun;
			FireAndForget([this]{ this->model->InitAndExecuteMachine(); });
		}
	}
}

void TuringSimuQtPresenter::DisplayCurrentStep(size_t step)
{
	this->view->DisplayCurrentStep(step);
}

void TuringSimuQtPresenter::HighlightTransition(const BaseTransition & transition)
{
	this->view->HighlightTransition(transition);
}

void TuringSimuQtPresenter::AwaitExceutionCompleted()
{
	if (this->model != nullptr)
	{
		this->autoRunMode = true; //end waiting for user input
		this->model->CancelExecution();
	}

	while (this->EXECUTING)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}

void TuringSimuQtPresenter::HandleLoadFileButtonClicked()
{
    const auto path = this->view->GetMachineDefintionFilePath();
	auto machine = ts_business::MachineFactory::CreateMachineFromFile(path);
	if(machine != nullptr)
	{
		this->currentMachine = std::move(machine);
		this->model = std::make_unique<TuringMachineQtOutputController>(this->currentMachine.get(), this);
		this->view->SetEnableMachineExecutionControls(true);
		this->view->SetEnableInitialTapeContentInput(true);
		std::vector<std::string> states;
		for (auto& s : this->currentMachine->GetSpecificValue(SpecificMachineValue::States)->As<HashSet<State>>().asVector())
		{
			states.push_back(s.ToString());
		}


		std::vector<std::string> tapeAlphabet;
		for (auto& s : this->currentMachine->GetSpecificValue(SpecificMachineValue::TapeAlphabet)->As<HashSet<char>>().asVector())
		{
			tapeAlphabet.push_back(std::string{ s });
		}

		auto transitions = this->currentMachine->GetSpecificValue(SpecificMachineValue::RawTransitions)->As<std::vector<const BaseTransition*>>();

		this->view->FillTransitionTable(states, tapeAlphabet, transitions);
		
		std::string infoText = Localization::GetString(LocId::Type);
		infoText.push_back(' ');
		auto type = this->currentMachine->GetSpecificValue(SpecificMachineValue::Type)->As<MachineType>();
		infoText.append(TypeToString(type));
		if(type == NEA || type == NTM)
		{
			infoText.append(" (Warning: Not completely supported (BETA))");
		}

		infoText.push_back('\n');
		infoText.push_back('\n');
		infoText.append(Localization::GetString(LocId::Alphabet));
		infoText.push_back('\n');
		auto inputAlphabet = this->currentMachine->GetSpecificValue(SpecificMachineValue::Alphabet)->As<HashSet<char>>();
		for (const char c : inputAlphabet)
		{
			infoText.push_back(c);
			infoText.push_back('\n');
		}

		this->view->DisplayMachineInfo(infoText);
		this->HandleInitialTapeContentChanged();
	}
}

void TuringSimuQtPresenter::HandleRunButtonClicked()
{
	StartMachineExecution(true);
}

void TuringSimuQtPresenter::HandleStepButtonClicked()
{
	StartMachineExecution(false);

	if (this->listeningForStepButtonClick)
	{
		this->clickOnStepButtonOccured = true;
	}
}

void TuringSimuQtPresenter::HandleResetButtonClicked()
{
	FireAndForget([this] {
							AwaitExceutionCompleted();
							if (this->view != nullptr)
							{
								this->view->SetEnableInitialTapeContentInput(true);
								this->view->SetEnableResetButton(false);
								this->view->SetEnableRunButton(true);
								this->view->SetEnableStepButton(true);
							}
						});
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

void TuringSimuQtPresenter::FireAndForget(const std::function<void()>& lambda)
{
	std::thread(lambda).detach();
}

void TuringSimuQtPresenter::FireAndAwait(const std::function<void()>& lambda)
{
	std::thread(lambda).join();
}
