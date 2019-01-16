#pragma once
#ifndef TS_LOCALIZATION
#define TS_LOCALIZATION
#include <string>
#include <unordered_map>
#include "../../Common/Header/AbstractMachine.hpp"

using namespace ts_common;

namespace ts_ui
{
	/**
	 * \brief Enumeration of identifiers of localized strings.
	 */
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

	/**
	 * \brief Enumeration of supported languages.
	 */
	enum class Language
	{
		English,
		German
	};

	/**
	 * \brief Class which manages localized resources.
	 */
	class Localization
	{
		public:
			/**
			 * \brief Sets the requested language.
			 * \param language The requested range.
			 */
			static void SetRequestedLocalization(Language language);
			
			/**
			 * \brief Retrieves a localized string.
			 * \param toLookup The id of the requested string.
			 * \return The requested localized string.
			 */
			static const std::string& GetString(LocId toLookup);

		private:
			/**
			 * \brief The current language which is used to obtain localized strings.
			 */
			static Language lang;

			/**
			 * \brief The default string (returned if no localized string found)
			 */
			static std::string defaultString;
			
			/**
			 * \brief Mapping of loc ids to english strings
			 */
			static std::unordered_map<LocId, std::string> locEN;
			
			/**
			 * \brief Mapping of loc ids to german strings
			 */
			static std::unordered_map<LocId, std::string> locDE;
	};

	/**
	 * \brief Converts the given SpecificMachineValue to the belonging LocId
	 * \param toConvert The SpecificMachineValue to convert.
	 * \return The corresponding LocId.
	 */
	LocId ToLocId(SpecificMachineValue toConvert);
}
#endif // TS_LOCALIZATION
