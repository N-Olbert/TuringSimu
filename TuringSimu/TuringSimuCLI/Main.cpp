#include <cstdio>
#ifdef _WIN32
#include <Windows.h>
#endif
#include "Business/Header/ConsoleController.hpp"

bool EnableVTMode(void);
int main()
{
	if(!EnableVTMode())
	{
		
	}

	ts_cliui_business::ConsoleController controller;
	controller.Start();
	return 0; 
}

bool EnableVTMode(void)
{
	#ifdef _WIN32
	//Based on https://docs.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences#samples
	// Set output mode to handle virtual terminal sequences     
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hOut != INVALID_HANDLE_VALUE)
	{
		DWORD dwMode = 0;
		if (GetConsoleMode(hOut, &dwMode))
		{
			dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
			if (SetConsoleMode(hOut, dwMode))
			{
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
