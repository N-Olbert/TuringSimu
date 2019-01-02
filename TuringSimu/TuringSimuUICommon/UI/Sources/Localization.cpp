#include "../Header/Localization.hpp"
using namespace ts_ui;

std::string Localization::defaultString = std::string{""};
Language Localization::lang = Language::English;
std::unordered_map<LocId, std::string> Localization::locEN = 	
			{
				{ LocId::ProductName, "TuringSimu" },
				{ LocId::ConsoleMenuTextBasic, "TuringSimu CLI\nOptions:\n1) Load turing machine from file\n88) Change language/Sprache aendern\n99) Exit\n"   },
				{ LocId::ConsoleMenuTextAdvanced, "TuringSimu CLI\nOptions:\n1) Load turing machine from file\n2) Parse another string using the current TM\n88) Change language/Sprache aendern\n99) Exit\n"   },
				{ LocId::RequestDecision, "\nPlease choose...\n"   },
				{ LocId::TMFilePathRequest, "Please specify the file path of the turing machine which should be loaded:\n"},
				{ LocId::InvalidInput, "Invalid input. Please try again...\n"},
				{ LocId::RequestTapeInput, "Please specify the initial content of the tape: "},
				{ LocId::TMTerminated, "Machine terminated. Press enter to continue..." },
				{ LocId::TryAgain, "Please try again: " },
				{ LocId::Error, "Error: " },
				{ LocId::CurrentState, "Current state: " },
				{ LocId::AutoRunYesNo, "Would you like to execute the machine manually by pressing enter after each step? If you choose not to do so the machine will execute automatically. (Y/N): "},
				{ LocId::ErrorNoValidBlank, "Fatal error: no valid blank returned from machine." },
				{ LocId::ErrorInvalidCharOnTape, "Invalid char within tape." }
			};

std::unordered_map<LocId, std::string> Localization::locDE = 	
			{
				{ LocId::ProductName, "TuringSimu" },
				{ LocId::ConsoleMenuTextBasic, "TuringSimu CLI\Optionen:\n1) Turingmaschine aus Datei laden...\n88) Sprache aendern/Change language\n99) Beenden\n"   },
				{ LocId::ConsoleMenuTextAdvanced, "TuringSimu CLI\Optionen:\n1) Turingmaschine aus Datei laden...\n2) Eine weitere Zeichenkette parsen...\n88) Sprache aendern/Change language\n99) Beenden\n"    },
				{ LocId::RequestDecision, "\nBitte w�hlen Sie...\n"   },
				{ LocId::TMFilePathRequest, "Bitte geben Sie den Pfad der zu ladenen Turingmaschine an:\n"},
				{ LocId::InvalidInput, "Ung�ltige Eingabe. Bitte versuchen Sie es erneut...\n"},
				{ LocId::RequestTapeInput, "Bitte geben Sie die Zeichenfolge an, welche inital auf dem Band stehen soll: "},
				{ LocId::TMTerminated, "Turingmaschine h�lt. Dr�cken Sie Enter um zum Menu zur�ckzukehren..." },
				{ LocId::TryAgain, "Bitte versuchen Sie es erneut: " },
				{ LocId::Error, "Fehler: " },
				{ LocId::CurrentState, "Aktueller Zustand: " },
				{ LocId::AutoRunYesNo, "M�chten Sie die Turingmaschine manuell - durch bet�tigen der Entertaste - ausf�hren? Wenn Sie dies nicht w�nschen wird die Turingmaschine automatisch abgearbeitet. (Y/N): "},
				{ LocId::ErrorNoValidBlank, "Schwerwiegender Fehler: Es wurde kein g�ltiges Leerzeichen von der Turingmaschine zur�ckgegeben." },
				{ LocId::ErrorInvalidCharOnTape, "Ung�ltiges Zeichen auf Band." }
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
			return locDE.at(toLookup);
		case Language::English:
		default:
			return locEN.at(toLookup);
	}

	return defaultString;
}
