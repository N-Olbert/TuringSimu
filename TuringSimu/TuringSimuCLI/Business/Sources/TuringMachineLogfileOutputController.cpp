#include "../../../TuringSimuCommon/UI/Header/Localization.hpp"
#include "../../../TuringSimuCommon/Common/Header/MachineType.hpp"
#include "../../../TuringSimuCommon/UI/Header/TuringMachineUIExecutionData.hpp"
#include "../Header/TuringMachineLogfileOutputController.hpp"
#include "../../UI/Header/Console.hpp"
#include "../../../TuringSimu/IO/Header/DiskOutput.hpp"
#include "../../../TuringSimu/IO/Header/DiskIO.hpp"

using namespace ts_common;
using namespace ts_ui;
using namespace ts_ui_business;

TuringMachineLogfileOutputController::TuringMachineLogfileOutputController(AbstractMachine* machine) : MachineExecutionController(machine)
{
	auto machineFileName = machine->GetSpecificValue(SpecificMachineValue::FileName)->As<std::string>();
	this->logFilePath = "TuringSimuExecutionLog_" + machineFileName + "_" + std::to_string(time(nullptr)) + ".log";
	this->stringBuilder.append(Localization::GetString(LocId::LogFileHeading));
	this->stringBuilder.append(machineFileName);
	this->stringBuilder.push_back(LineFeed);
	this->stringBuilder.push_back(LineFeed);
}

void TuringMachineLogfileOutputController::ShowMachineExecutionState()
{
	if (this->machine != nullptr)
	{
		const auto execData = static_cast<TuringMachineUIExecutionData*>(this->executionData.get());
		stringBuilder.append(Localization::GetString(LocId::CurrentStep));
		stringBuilder.append(std::to_string(static_cast<uint64_t>(execData->GetStepsCounter())));
		this->stringBuilder.push_back(LineFeed);
		stringBuilder.append(Localization::GetString(LocId::CurrentState));
		stringBuilder.append(execData->GetCurrentState().ToString());
		this->stringBuilder.push_back(LineFeed);
		for (size_t i = 0; i < execData->GetPosition(); ++i)
		{
			stringBuilder.push_back(WhiteSpace);
		}

		stringBuilder.push_back(TapeHeaderChar);
		this->stringBuilder.push_back(LineFeed);

		for (const char c : execData->GetTape())
		{
			stringBuilder.push_back(c);
		}

		this->stringBuilder.push_back(LineFeed);
		this->stringBuilder.push_back(LineFeed);
	}
}

void TuringMachineLogfileOutputController::ShowLoadedMachine()
{
	this->OnError(Localization::GetString(LocId::NotImplementedFunction));
}

void TuringMachineLogfileOutputController::OnStateChanged(const State& newState)
{
	MachineExecutionController::OnStateChanged(newState);
	ShowMachineExecutionState();
}

void TuringMachineLogfileOutputController::OnBacktraceDifferentExecutionPathChosen()
{
	this->stringBuilder.push_back(LineFeed);
	this->stringBuilder.push_back(LineFeed);
	this->stringBuilder.append(Localization::GetString(LocId::ExecutionPathChanged));
	ShowMachineExecutionState();
	this->stringBuilder.push_back(LineFeed);
	this->stringBuilder.push_back(LineFeed);
}

void TuringMachineLogfileOutputController::OnError(const std::string& errorMessage)
{
	Console::NewLineDelayed();
	Console::PrintDelayed(Localization::GetString(LocId::Error));
	Console::PrintLine(errorMessage);
	this->stringBuilder.push_back(LineFeed);
	stringBuilder.append(Localization::GetString(LocId::Error));
	stringBuilder.append(errorMessage);
}

void TuringMachineLogfileOutputController::OnAfterMachineExecution()
{
	this->stringBuilder.push_back(LineFeed);
	this->stringBuilder.push_back(LineFeed);
	auto str = Localization::GetString(LocId::TMTerminatedSuccessfully);
	if (!this->machine->IsFinishedSuccessfully())
	{
		str = Localization::GetString(LocId::TMTerminatedNotSuccessfully);
	}

	stringBuilder.append(str);
	if(ts_io::WriteToFile(this->logFilePath, stringBuilder))
	{
		Console::PrintDelayed(str);
		Console::NewLineDelayed();
		Console::PrintDelayed(Localization::GetString(LocId::LogFileCreatedAt));
		Console::Print(ts_io::GetAbsolutePath(this->logFilePath));
		Console::NewLine();
	}
	else
	{
		Console::PrintLine(Localization::GetString(LocId::LogFileGenerationError));
	}

	Console::PrintLine(Localization::GetString(LocId::EnterToContinue));
	Console::AwaitEnter();
}

void TuringMachineLogfileOutputController::InitAndExecuteMachine()
{
	Console::ClearScreen();
	Console::Print(Localization::GetString(LocId::RequestTapeInput));
	auto tapeContent = Console::GetStringInput();
	while (!this->machine->InitMachineForExecution(tapeContent))
	{
		Console::Print(Localization::GetString(LocId::TryAgain));
		tapeContent = Console::GetStringInput();
	}

	AwaitMachineExecution(false);
}