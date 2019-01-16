#include "../Header/TuringMachineConsoleOutputController.hpp"
#include "../../UI/Header/Console.hpp"
#include "../../../TuringSimuCommon/UI/Header/Localization.hpp"
#include <cctype>
#include "../../../TuringSimuCommon/Common/Header/HashSet.hpp"
#include "../../../TuringSimuCommon/Common/Header/MachineType.hpp"
#include "../../../TuringSimuCommon/UI/Header/TuringMachineUIExecutionData.hpp"

using namespace ts_common;
using namespace ts_ui;
using namespace ts_ui_business;

void TuringMachineConsoleOutputController::ShowMachineExecutionState()
{
	if (this->machine != nullptr)
	{
		const auto execData = dynamic_cast<TuringMachineUIExecutionData*>(this->executionData.get());
		Console::ClearLine();
		auto offset = execData->GetPosition();
		for (size_t i = 0; i < offset; ++i)
		{
			Console::PrintDelayed(WhiteSpace);
		}

		Console::PrintDelayed(TapeHeaderChar);
		Console::NewLineDelayed();

		Console::ClearLine();
		for (char c : execData->GetTape())
		{
			Console::PrintDelayed(c);
		}

		Console::NewLine();
		Console::ClearLine();
		Console::PrintDelayed(Localization::GetString(LocId::CurrentState));
		Console::PrintDelayed(execData->GetCurrentState().ToString());
		Console::NewLine();
		Console::PrintDelayed(Localization::GetString(LocId::CurrentStep));
		Console::PrintDelayed(static_cast<uint64_t>(execData->GetStepsCounter()));
		Console::LineBack();
		Console::LineBack();
		Console::LineBack();
	}
}

void TuringMachineConsoleOutputController::ShowLoadedMachine()
{
	if (this->machine != nullptr)
	{
		Console::ClearScreen();
		Console::PrintDelayed(Localization::GetString(LocId::LoadedMachineMenuHeader));

		//We never perform nullptr checks here as we know that all values must exist

		//File name
		auto requestedValueIdentifer = SpecificMachineValue::FileName;
		auto dyn = this->machine->GetSpecificValue(requestedValueIdentifer);
		Console::PrintDelayed(dyn->As<std::string>());
		Console::NewLineDelayed();
		Console::NewLineDelayed();
		Console::PrintLineBlueUnderlinedDelayed(Localization::GetString(ToLocId(requestedValueIdentifer)));

		//Machine type
		requestedValueIdentifer = SpecificMachineValue::Type;
		dyn = this->machine->GetSpecificValue(requestedValueIdentifer);
		Console::PrintLineDelayed(TypeToString(dyn->As<MachineType>()));
		Console::NewLineDelayed();

		requestedValueIdentifer = SpecificMachineValue::Blank;
		Console::PrintLineBlueUnderlinedDelayed(Localization::GetString(ToLocId(requestedValueIdentifer)));
		dyn = this->machine->GetSpecificValue(SpecificMachineValue::Blank);
		Console::PrintLine(dyn->As<char>());
		Console::NewLineDelayed();


		requestedValueIdentifer = SpecificMachineValue::InitialState;
		Console::PrintLineBlueUnderlinedDelayed(Localization::GetString(ToLocId(requestedValueIdentifer)));
		dyn = this->machine->GetSpecificValue(SpecificMachineValue::InitialState);
		Console::PrintLine(dyn->As<State>());
		Console::NewLineDelayed();

		requestedValueIdentifer = SpecificMachineValue::TapeAlphabet;
		Console::PrintLineBlueUnderlinedDelayed(Localization::GetString(ToLocId(requestedValueIdentifer)));
		dyn = this->machine->GetSpecificValue(SpecificMachineValue::TapeAlphabet);
		Console::PrintEnumerable<HashSet<char>, char>(dyn->As<HashSet<char>>());
		Console::NewLineDelayed();

		requestedValueIdentifer = SpecificMachineValue::Alphabet;
		Console::PrintLineBlueUnderlinedDelayed(Localization::GetString(ToLocId(requestedValueIdentifer)));
		dyn = this->machine->GetSpecificValue(SpecificMachineValue::Alphabet);
		Console::PrintEnumerable<HashSet<char>, char>(dyn->As<HashSet<char>>());
		Console::NewLineDelayed();

		requestedValueIdentifer = SpecificMachineValue::States;
		Console::PrintLineBlueUnderlinedDelayed(Localization::GetString(ToLocId(requestedValueIdentifer)));
		dyn = this->machine->GetSpecificValue(SpecificMachineValue::States);
		Console::PrintEnumerable<HashSet<State>>(dyn->As<HashSet<State>>());
		Console::NewLineDelayed();

		requestedValueIdentifer = SpecificMachineValue::FinalStates;
		Console::PrintLineBlueUnderlinedDelayed(Localization::GetString(ToLocId(requestedValueIdentifer)));
		dyn = this->machine->GetSpecificValue(SpecificMachineValue::FinalStates);
		Console::PrintEnumerable<HashSet<State>>(dyn->As<HashSet<State>>());
		Console::NewLineDelayed();


		requestedValueIdentifer = SpecificMachineValue::Transitions;
		Console::PrintLineBlueUnderlinedDelayed(Localization::GetString(ToLocId(requestedValueIdentifer)));
		dyn = this->machine->GetSpecificValue(SpecificMachineValue::Transitions);
		Console::PrintEnumerablePointer<std::vector<StringRepresentable*>>(dyn->As<std::vector<StringRepresentable*>>());
		Console::NewLineDelayed();
		Console::PrintLine(Localization::GetString(LocId::EnterToContinue));
		Console::AwaitEnter();
	}
}

void TuringMachineConsoleOutputController::OnStateChanged(const State& newState)
{
	MachineExecutionController::OnStateChanged(newState);
	ShowMachineExecutionState();
}

void TuringMachineConsoleOutputController::OnBacktraceDifferentExecutionPathChosen()
{
	Console::NewLineDelayed();
	Console::NewLineDelayed();
	Console::NewLineDelayed();
	Console::NewLineDelayed();
	Console::PrintLineRedUnderlinedDelayed(Localization::GetString(LocId::ExecutionPathChanged));
	ShowMachineExecutionState();
	Console::NewLineDelayed();
	Console::NewLineDelayed();
	Console::NewLineDelayed();
	Console::NewLineDelayed();
	Console::NewLineDelayed();
	Console::PrintLineDelayed(Localization::GetString(LocId::EnterToContinue));
	Console::AwaitEnter();
	Console::LineBack();
	Console::LineBack();
}

void TuringMachineConsoleOutputController::OnError(const std::string& errorMessage)
{
	Console::NewLineDelayed();
	Console::PrintDelayed(Localization::GetString(LocId::Error));
	Console::PrintLine(errorMessage);
}

void TuringMachineConsoleOutputController::OnBeforeNextExecutionStep(bool autoRun)
{
	if (autoRun)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	else
	{
		Console::AwaitEnter();
		Console::LineBack();
	}

	MachineExecutionController::OnBeforeNextExecutionStep(autoRun);
}

void TuringMachineConsoleOutputController::OnAfterMachineExecution()
{
	Console::NewLineDelayed();
	Console::NewLineDelayed();
	Console::NewLineDelayed();
	Console::NewLineDelayed();
	Console::NewLineDelayed();
	Console::ShowCursor();

	if (this->machine->IsFinishedSuccessfully())
	{
		Console::PrintDelayed(Localization::GetString(LocId::TMTerminatedSuccessfully));
	}
	else
	{
		Console::PrintDelayed(Localization::GetString(LocId::TMTerminatedNotSuccessfully));
	}

	Console::PrintLine(Localization::GetString(LocId::EnterToContinue));
	Console::AwaitEnter();
}

void TuringMachineConsoleOutputController::InitAndExecuteMachine()
{
	//Init TM
	Console::ClearScreen();
	Console::Print(Localization::GetString(LocId::RequestTapeInput));
	auto tapeContent = Console::GetStringInput();
	while (!this->machine->InitMachineForExecution(tapeContent))
	{
		Console::Print(Localization::GetString(LocId::TryAgain));
		tapeContent = Console::GetStringInput();
	}

	//Select auto run
	Console::ClearScreen();
	Console::HideCursor();
	Console::Print(Localization::GetString(LocId::AutoRunYesNo));
	const auto autoRun = std::tolower(Console::GetCharInput()) != Localization::GetString(LocId::AutoRunYesNoYesLowerCaseIdentifer)[0];
	AwaitMachineExecution(autoRun);
}
