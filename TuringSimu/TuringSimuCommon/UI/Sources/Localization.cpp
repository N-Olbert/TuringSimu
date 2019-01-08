#include "../Header/Localization.hpp"
using namespace ts_ui;

std::string Localization::defaultString = std::string{""};
Language Localization::lang = Language::English;
std::unordered_map<LocId, std::string> Localization::locEN = 	
{
	{ LocId::ProductName, "TuringSimu" },
	{ LocId::ConsoleMenuText, "TuringSimu CLI\nOptions:\n1) Load turing machine from file\n88) Change language/Sprache aendern\n99) Exit\n"   },
	{ LocId::ConsoleMenuTextAdvanced, "TuringSimu CLI\nOptions:\n1) Load turing machine from file\n2) Parse another string using the current TM\n88) Change language/Sprache aendern\n99) Exit\n"   },
	{ LocId::RequestDecision, "\nPlease choose...\n"   },
	{ LocId::TMFilePathRequest, "Please specify the file path of the turing machine which should be loaded:\n"},
	{ LocId::InvalidInput, "Invalid input. Please try again...\n"},
	{ LocId::RequestTapeInput, "Please specify the initial content of the tape: "},
	{ LocId::TMTerminatedSuccessfully, "Machine terminated successfully." },
	{ LocId::TMTerminatedNotSuccessfully, "Machine terminated with failure." },
	{ LocId::TryAgain, "Please try again: " },
	{ LocId::Error, "Error: " },
	{ LocId::CurrentState, "Current state: " },
	{ LocId::AutoRunYesNo, "Would you like to execute the machine manually by pressing enter after each step?\nIf you choose not to do so the machine will execute automatically. (Y/N): "},
	{ LocId::AutoRunYesNoYesLowerCaseIdentifer, "y" },
	{ LocId::ErrorNoValidBlank, "Fatal error: no valid blank returned from machine." },
	{ LocId::ErrorInvalidCharOnTape, "Invalid char within tape." },
	{ LocId::CurrentStep, "Current step: "},
	{ LocId::EnterToContinue, "Press enter to continue..."},
	{ LocId::ChooseLanguage, "Please choose your language... / Bitte waehlen Sie ihre Sprache..."},
	{ LocId::WarningNoVirtualTerminalMode, "WARNING: It seems that your terminal doesnt support VT100-ANSI-Escapesequebces. The application will work, but you might notice some cryptic output symbols and less comfort." },
	{ LocId::LoadedMachineMenuHeader, "### Loaded machine: " },
	{ LocId::LoadedMachineMenuOption1, "1) Parse input (visually)" },
	{ LocId::LoadedMachineMenuOption2, "2) Parse input (to log file)" },
	{ LocId::LoadedMachineMenuOption3, "3) Show machine definition" },
	{ LocId::LoadedMachineMenuOption4, "4) Go back to main menu" },
	{ LocId::Blank, "Blank Symbol" },
	{ LocId::FileName, "File name" },
	{ LocId::Type, "Machine type" },
	{ LocId::States, "Machine states" },
	{ LocId::FinalStates, "Machine final states" },
	{ LocId::Alphabet, "Alphabet" },
	{ LocId::TapeAlphabet, "Tape alphabet" },
	{ LocId::Transitions, "Transitions" },
	{ LocId::InitialState, "Initial state" },
	{ LocId::TapeContent, "Tape content" },
	{ LocId::NotImplementedFunction, "Not implemented function called." },
	{ LocId::LogFileCreatedAt, "Logfile can be found at: " },
	{ LocId::LogFileGenerationError, "Error during log file creation." },
	{ LocId::LogFileHeading, "Execution log of machine: " }
};

std::unordered_map<LocId, std::string> Localization::locDE =
{
	{ LocId::ProductName, "TuringSimu" },
	{ LocId::ConsoleMenuText, "TuringSimu CLI\nOptionen:\n1) Turingmaschine aus Datei laden...\n88) Sprache aendern/Change language\n99) Beenden\n"   },
	{ LocId::ConsoleMenuTextAdvanced, "TuringSimu CLI\nOptionen:\n1) Turingmaschine aus Datei laden...\n2) Eine weitere Zeichenkette parsen...\n88) Sprache aendern/Change language\n99) Beenden\n"    },
	{ LocId::RequestDecision, "\nBitte waehlen Sie...\n"   },
	{ LocId::TMFilePathRequest, "Bitte geben Sie den Pfad der zu ladenen Turingmaschine an:\n"},
	{ LocId::InvalidInput, "Ungueltige Eingabe. Bitte versuchen Sie es erneut...\n"},
	{ LocId::RequestTapeInput, "Bitte geben Sie die Zeichenfolge an, welche inital auf dem Band stehen soll: "},
	{ LocId::TMTerminatedSuccessfully, "Turingmaschine haelt. Druecken Sie Enter um zum Menu zurueckzukehren..." },
	{ LocId::TryAgain, "Bitte versuchen Sie es erneut: " },
	{ LocId::Error, "Fehler: " },
	{ LocId::CurrentState, "Aktueller Zustand: " },
	{ LocId::AutoRunYesNo, "Moechten Sie die Turingmaschine manuell - durch betaetigen der Entertaste - ausfuehren?\n Wenn Sie dies nicht wuenschen wird die Turingmaschine automatisch abgearbeitet. (J/N): "},
	{ LocId::AutoRunYesNoYesLowerCaseIdentifer, "j" },
	{ LocId::ErrorNoValidBlank, "Schwerwiegender Fehler: Es wurde kein gueltiges Leerzeichen von der Turingmaschine zurueckgegeben." },
	{ LocId::ErrorInvalidCharOnTape, "Ungueltiges Zeichen auf Band." },
	{ LocId::CurrentStep, "Schritt: "},
};


void Localization::SetRequestedLocalization(Language language)
{
	lang = language;
}

const std::string& Localization::GetString(LocId toLookup)
{
	switch (lang)
	{
		case Language::German:
			if(locDE.count(toLookup) > 0)
			{
				return locDE.at(toLookup);
			}

		case Language::English:
		default:
			return locEN.at(toLookup);
	}

	return defaultString;
}

LocId ts_ui::ToLocId(SpecificMachineValue toConvert)
{
	switch (toConvert)
	{
		case SpecificMachineValue::Blank: return LocId::Blank;
		case SpecificMachineValue::FileName: return LocId::FileName;
		case SpecificMachineValue::Type: return LocId::Type;
		case SpecificMachineValue::States: return LocId::States;
		case SpecificMachineValue::FinalStates: return LocId::FinalStates;
		case SpecificMachineValue::Alphabet: return LocId::Alphabet;
		case SpecificMachineValue::TapeAlphabet: return LocId::TapeAlphabet;
		case SpecificMachineValue::Transitions: return LocId::Transitions;
		case SpecificMachineValue::InitialState: return LocId::InitialState;
		case SpecificMachineValue::TapeContent: return LocId::TapeContent;
		default: return LocId::Error;
	}
}
