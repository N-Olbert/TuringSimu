#include <cstdio>
#ifdef _WIN32
#include <Windows.h>
#endif
#include "Business/Header/BaseConsoleController.hpp"
#include "../TuringSimuCommon/UI/Header/Localization.hpp"
#include <iostream>
#include "../TuringSimu/IO/Header/DiskIO.hpp"
#include "../TuringSimu/IO/Header/DiskOutput.hpp"

bool EnableVTMode(void);
int main(int argc, char** argv) {
	//we only support usage without flags or with the -c flag and a corresponding path
	if (argc != 3 && argc != 1) {
		std::cout << "Invalid usage of this binary" << std::endl
			<< "Use " << argv[0] << " or " << argv[0] << " -c PATHTOASUPPORTEDFILE" << std::endl;
		return 1;
	}
	//flag handling
	if (argc == 3) {
		const std::string flag = argv[1];
		if (flag == "-c") {
			const std::string path = argv[2];
			auto const index = path.find_last_of('.');
			auto const fileExtension = path.substr(index + 1, path.length() - index);
			auto fileName = path.substr(0, index);
			auto tmd = ts_io::GetTuringMachineDefinitionFromFile(path);
			if (tmd.error) {
				std::cout << "Could not parse the given file" << std::endl;
				return 1;
			}
			if (fileExtension == "csv") {
				fileName.append(".tmsim");
				ts_io::saveAsBinary(fileName, tmd);
			} else if (fileExtension == "tmsim") {
				fileName.append(".csv");
				ts_io::saveAsCSV(fileName, tmd);
			} else {
				std::cout <<
					"Cannot convert this file. Supported extensions are \"csv\" and \"tmsim\""
					<< std::endl;
				return 1;
			}
			return 0;
		} else {
			std::cout << "Unrecognized flag, did you perhaps mean \"-c\"?" << std::endl;
			return 1;
		}
	}

	if (!EnableVTMode()) {
		Console::PrintDelayed(Localization::GetString(LocId::WarningNoVirtualTerminalMode));
		Console::NewLineDelayed();
		Console::PrintLine(Localization::GetString(LocId::EnterToContinue));
		Console::AwaitEnter();
	}

	ts_ui_business::BaseConsoleController::Start();
	return 0;
}

bool EnableVTMode(void) {
#ifdef _WIN32
	//Based on https://docs.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences#samples
	// Set output mode to handle virtual terminal sequences     
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hOut != INVALID_HANDLE_VALUE) {
		DWORD dwMode = 0;
		if (GetConsoleMode(hOut, &dwMode)) {
			dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
			if (SetConsoleMode(hOut, dwMode)) {
				return true;
			}
		}
	}


	return false;
#else

	//Nearly all Linux/Unix-systems support VT-commands by default
	return true;
#endif
	}
