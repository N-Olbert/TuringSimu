#pragma once
#ifndef TS_LOCALIZATION
#define TS_LOCALIZATION
#include <string>
#include <unordered_map>
#include "../../Common/Header/AbstractMachine.hpp"

using namespace ts_common;

namespace ts_ui
{
	enum class LocId
	{
		ProductName,
		WarningNoVirtualTerminalMode,
		ConsoleMenuText,
		TMFilePathRequest,
		InvalidInput,
		RequestTapeInput,
		TMTerminatedSuccessfully,
		TryAgain,
		Error,
		CurrentState,
		AutoRunYesNo,
		AutoRunYesNoYesLowerCaseIdentifer,
		RequestDecision,
		ConsoleMenuTextAdvanced,
		ErrorNoValidBlank,
		ErrorInvalidCharOnTape,
		CurrentStep,
		EnterToContinue,
		TMTerminatedNotSuccessfully,
		ChooseLanguage,
		LoadedMachineMenuHeader,
		LoadedMachineMenuOption1,
		LoadedMachineMenuOption2,
		LoadedMachineMenuOption3,
		LoadedMachineMenuOption4,
		Blank,
		FileName,
		Type,
		States,
		FinalStates,
		Alphabet,
		TapeAlphabet,
		Transitions,
		InitialState,
		TapeContent,
		NotImplementedFunction,
		LogFileCreatedAt,
		LogFileGenerationError,
		LogFileHeading,
		ExecutionPathChanged
	};

	enum class Language
	{
		English,
		German
	};

	class Localization
	{
		public:
			static void SetRequestedLocalization(Language language);
			static const std::string& GetString(LocId toLookup);

		private:
			static Language lang;
			static std::string defaultString;
			static std::unordered_map<LocId, std::string> locEN;
			static std::unordered_map<LocId, std::string> locDE;
	};

	LocId ToLocId(SpecificMachineValue toConvert);
}
#endif // TS_LOCALIZATION
