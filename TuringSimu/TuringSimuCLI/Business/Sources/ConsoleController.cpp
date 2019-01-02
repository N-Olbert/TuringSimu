#include "..\Header\ConsoleController.hpp"
#include "../../../TuringSimuUICommon/UI/Header/Localization.hpp"
#include "../../../TuringSimu/Business/Header/MachineFactory.hpp"
#include <thread>
#include <cctype>

using namespace ts_cliui_business;
using namespace ts_ui;

ConsoleController::ConsoleController()
{
	this->machine = nullptr;
}

void ConsoleController::Start()
{
	while (PrintMenu() != SpecialCommand::Exit)
	{		
	}
}

ConsoleController::SpecialCommand ConsoleController::PrintMenu()
{
	Console::ClearScreen();
	const auto textId = this->machine == nullptr ? LocId::ConsoleMenuTextBasic : LocId::ConsoleMenuTextAdvanced;
	Console::Print(Localization::GetString(textId));
	while (true)
	{
		const auto selected = Console::GetIntInput();
		if (!selected.Failure)
		{
			switch (selected.Value)
			{
				case 1:
					ReadInMachine();
					return SpecialCommand::None;
				case 2:
					if(this->machine != nullptr)
					{
						InitAndExecuteMachine();
					}

					return SpecialCommand::None;
				case 88:
					ChangeLanguage();
					return SpecialCommand::None;
				case 99:
					return SpecialCommand::Exit;
				default:
					Console::Print(Localization::GetString(LocId::InvalidInput));
					break;
			}
		}
		else
		{
			Console::Print(Localization::GetString(LocId::InvalidInput));
		}
	}	
}

void ConsoleController::ChangeLanguage()
{
	Console::ClearScreen();
	Console::PrintLine("Please choose your language... / Bitte waehlen Sie ihre Sprache...");
	Console::PrintLine("2)				 Deutsch");
	Console::PrintLine("Any other key)	 English");
	auto c = Console::GetCharInput();
	if (c == '2')
	{
		Localization::SetRequestedLocalization(Language::German);
	}
	else
	{
		Localization::SetRequestedLocalization(Language::English);
	}
}

void ConsoleController::ReadInMachine()
{
	//Load TM from file
	Console::ClearScreen();
	Console::Print(Localization::GetString(LocId::TMFilePathRequest));
	std::unique_ptr<AbstractMachine> machine = nullptr;
	auto path = Console::GetStringInput();
	while ((machine = ts_business::MachineFactory::CreateMachineFromFile(path, this)) == nullptr)
	{
		Console::Print(Localization::GetString(LocId::TryAgain));
		path = Console::GetStringInput();
	}

	this->machine = std::move(machine);
	auto blank = this->machine->GetSpecificValue("BLANK");
	if (blank == AbstractMachine::UnknownSpecificValue || blank.length() != 1)
	{
		Console::Print(Localization::GetString(LocId::ErrorNoValidBlank));
		this->machine = nullptr;
		return;
	}

	this->blank = blank[0];
	InitAndExecuteMachine();
}

void ConsoleController::InitAndExecuteMachine()
{
	//Init TM
	Console::ClearScreen();
	Console::Print(Localization::GetString(LocId::RequestTapeInput));
	auto tapeContent = Console::GetStringInput();
	while (!this->machine->Init(tapeContent))
	{
		Console::Print(Localization::GetString(LocId::TryAgain));
		tapeContent = Console::GetStringInput();
	}

	//Select auto run
	Console::ClearScreen();
	Console::Print(Localization::GetString(LocId::AutoRunYesNo));
	const auto noAutoRun = Console::GetCharInput();
	std::thread{&ConsoleController::ExecuteMachine, this, std::tolower(noAutoRun) != 'y'}.join();
}

void ConsoleController::NotifyInvalidMachineDefinition(const std::string& errorMessage)
{
	Console::NewLine();
	Console::Print(Localization::GetString(LocId::Error));
	Console::PrintLine(errorMessage);
}

void ConsoleController::NotifyInitialized(const std::string& tapeInput, const std::string& initialState)
{ 
	this->currentState = initialState;
	this->tape.clear();
	for (auto i = 0; i < 5; ++i)
	{
		this->tape.push_back(this->blank);
	}

	for (char c : tapeInput)
	{
		this->tape.push_back(c);
	}

	for (auto i = 0; i < 5; ++i)
	{
		this->tape.push_back(this->blank);
	}

	this->position = 5;
}

void ConsoleController::ExecuteMachine(bool autoRun)
{
	std::lock_guard<std::mutex> memBarrier{memoryBarrierForcer};
	Console::HideCursor();
	PrintTape();
	while (!this->machine->IsFinished())
	{
		if(!autoRun)
		{
			Console::AwaitEnter();
			Console::LineBack();
		}
		else 
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}

		this->machine->PerformNextStep();
	}

	Console::NewLine();
	Console::NewLine();
	Console::NewLine();
	Console::PrintLine(Localization::GetString(LocId::TMTerminated));
	Console::ShowCursor();
	Console::AwaitEnter();
}

void ConsoleController::NotifyTapeWritten(char written)
{
	this->tape[this->position] = written;
	PrintTape();
}

void ConsoleController::NotifyHeadMoved(HeadDirection direction)
{
	switch (direction)
	{
		case Left:
			HandleMoveHeadLeft();
			break;
		case Right:
			HandleMoveHeadRight();
			break;
		case Stay: break;
	}

	PrintTape();
}

void ConsoleController::NotifyStateChanged(const std::string& newState)
{
	this->currentState = newState;
	PrintTape();
}

void ConsoleController::HandleMoveHeadLeft()
{
	if (this->position == 1)
	{
		this->tape.push_front(this->blank);
	}
	else
	{
		this->position--;
	}
}

void ConsoleController::HandleMoveHeadRight()
{
	if (this->position + 2 >= this->tape.size())
	{
		this->tape.push_back(this->blank);
	}

	this->position++;
}

void ConsoleController::PrintTape()
{
	Console::ClearLine();
	for (size_t i = 0; i < this->position; ++i)
	{
		Console::PrintDelayed(' ');
	}

	Console::PrintDelayed('|');
	Console::NewLine();

	Console::ClearLine();
	for (char c : this->tape)
	{
		Console::PrintDelayed(c);
	}

	Console::NewLine();
	Console::ClearLine();
	Console::PrintDelayed(Localization::GetString(LocId::CurrentState));
	Console::PrintDelayed(this->currentState);
	Console::LineBack();
	Console::LineBack();
}
