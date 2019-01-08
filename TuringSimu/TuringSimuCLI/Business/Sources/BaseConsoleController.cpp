#include "../Header/BaseConsoleController.hpp"
#include "../../../TuringSimuCommon/UI/Header/Localization.hpp"
#include "../../../TuringSimu/Business/Header/MachineFactory.hpp"
#include "../../../TuringSimuCommon/UI/Header/MachineExecutionControllerFactory.hpp"

using namespace ts_common;
using namespace ts_ui_business;
using namespace ts_ui;

void BaseConsoleController::Start()
{
	PrintMenu();
}

void BaseConsoleController::PrintMenu()
{
	Console::ClearScreen();
	Console::Print(Localization::GetString(LocId::ConsoleMenuText));
	while (true)
	{
		const auto selected = Console::GetIntInput();
		if (!selected.Failure)
		{
			switch (selected.Value)
			{
				case 1:
					ReadInMachine();
					Console::ClearScreen();
					Console::Print(Localization::GetString(LocId::ConsoleMenuText));
					break;
				case 88:
					ChangeLanguage();
					Console::ClearScreen();
					Console::Print(Localization::GetString(LocId::ConsoleMenuText));
					break;
				case 99:
					return;
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

void BaseConsoleController::ChangeLanguage()
{
	Console::ClearScreen();
	Console::PrintLineDelayed(Localization::GetString(LocId::ChooseLanguage));

	//Hardcoded specific language strings (the name of the language itself is always localized)
	Console::PrintLineDelayed("X) English");
	Console::PrintLine("1) Deutsch");
	auto c = Console::GetCharInput();
	if (c == '1')
	{
		Localization::SetRequestedLocalization(Language::German);
	}
	else
	{
		Localization::SetRequestedLocalization(Language::English);
	}
}

void BaseConsoleController::ReadInMachine()
{
	//Load machine from file
	Console::ClearScreen();
	Console::Print(Localization::GetString(LocId::TMFilePathRequest));
	std::unique_ptr<AbstractMachine> machine;
	auto path = Console::GetStringInput();
	while ((machine = ts_business::MachineFactory::CreateMachineFromFile(MachineType::DTM, path)) == nullptr)
	{
		Console::Print(Localization::GetString(LocId::TryAgain));
		path = Console::GetStringInput();
	}

	PrintLoadedMachineMenu(std::move(machine));
}

void BaseConsoleController::PrintLoadedMachineMenu(std::unique_ptr<AbstractMachine> machine)
{
	while (true)
	{
		Console::ClearScreen();
		Console::PrintLineDelayed(Localization::GetString(LocId::LoadedMachineMenuHeader) +
								  machine->GetSpecificValue(SpecificMachineValue::FileName)->As<std::string>());
		Console::NewLineDelayed();
		Console::PrintLine(Localization::GetString(LocId::LoadedMachineMenuOption1));
		Console::PrintLine(Localization::GetString(LocId::LoadedMachineMenuOption2));
		Console::PrintLine(Localization::GetString(LocId::LoadedMachineMenuOption3));
		Console::PrintLine(Localization::GetString(LocId::LoadedMachineMenuOption4));
		const auto selected = Console::GetIntInput();
		if (!selected.Failure)
		{
			switch (selected.Value)
			{
			case 1:
				MachineExecutionControllerFactory::GetExecutionController(UI::Console, machine.get())->InitAndExecuteMachine();
				break;
			case 2:
				MachineExecutionControllerFactory::GetExecutionController(UI::LogFile, machine.get())->InitAndExecuteMachine();
				break;
			case 3:
				MachineExecutionControllerFactory::GetExecutionController(UI::Console, machine.get())->PrintLoadedMachine();
				break;
			case 4:
				return;
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