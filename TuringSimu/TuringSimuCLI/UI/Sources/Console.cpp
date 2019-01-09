#include "../Header/Console.hpp"
#include <iostream>
#include <cctype>
#include <string>

//// For ANSI escape sequences see http://ascii-table.com/ansi-escape-sequences-vt-100.php

using namespace ts_ui;
const std::string Console::ESC = std::string{"\x1b"};
const std::string Console::CSI = std::string{"\x1b["};
std::mutex Console::ConsoleMutex;

void Console::Print(const std::string& toPrint)
{
	std::lock_guard<std::mutex> lock(ConsoleMutex);
	std::cout << toPrint << std::flush;
}

void Console::PrintDelayed(const std::string& toPrint)
{
	std::lock_guard<std::mutex> lock(ConsoleMutex);
	std::cout << toPrint;
}

void Console::Print(const char toPrint)
{
	std::lock_guard<std::mutex> lock(ConsoleMutex);
	std::cout << toPrint;
}

void Console::PrintDelayed(const char toPrint)
{
	std::lock_guard<std::mutex> lock(ConsoleMutex);
	std::cout << toPrint;
}

void Console::PrintDelayed(const uint64_t toPrint)
{
	std::lock_guard<std::mutex> lock(ConsoleMutex);
	std::cout << toPrint;
}

void Console::PrintLine(const std::string& toPrint)
{
	PrintDelayed(toPrint);
	NewLine();
}

void Console::PrintLineBlueUnderlinedDelayed(const std::string& toPrint)
{
	PrintDelayed(CSI + "34;1;4m" + toPrint + CSI + "0m");
	NewLineDelayed();
}

void Console::PrintLineRedUnderlinedDelayed(const std::string& toPrint)
{
	PrintDelayed(CSI + "31;1;4m" + toPrint + CSI + "0m");
	NewLineDelayed();
}

void Console::PrintLineDelayed(const std::string& toPrint)
{
	PrintDelayed(toPrint);
	NewLineDelayed();
}


void Console::PrintLine(const StringRepresentable& toPrint)
{
	PrintDelayed(toPrint.ToString());
	NewLine();
}

void Console::PrintLine(const char toPrint)
{
	PrintDelayed(toPrint);
	NewLine();
}

void Console::NewLine()
{
	Print("\n");
}

void Console::NewLineDelayed()
{
	Print("\n");
}

void Console::Flush()
{
	Print("");
}

void Console::LineBack()
{
	Print(ESC + "A\r");
}

void Console::ClearLine()
{
	Print(CSI + "K");
}

void Console::ClearScreen()
{
	// For whatever reason requesting only "Esc[2J" = "Clear entire screen" fails to clear the previous screen contents sometimes
	// Printing "Esc[1J" = "Clear screen from cursor up" before seems to fix this.
	Print(CSI + "1J"); 
	Print(CSI + "2J");
}

void Console::HideCursor()
{
	Print(CSI + "?25l");
}

void Console::ShowCursor()
{
	Print(CSI + "?25h");
}

void Console::AwaitEnter()
{
	std::lock_guard<std::mutex> lock(ConsoleMutex);
	std::cin.get();
}

Result<int16_t> Console::GetIntInput()
{
	auto in = GetInput<std::string>();
	for (char c : in)
	{
		if(!std::isdigit(c))
		{
			return Result<int16_t>{-1, true};
		}
	}

	return Result<int16_t>{static_cast<int16_t>(std::stoi(in)), false};
}

std::string Console::GetStringInput()
{
	return GetInput<std::string>();
}

char Console::GetCharInput()
{
	return GetInput<char>();
}

template<class T> T Console::GetInput()
{
	std::lock_guard<std::mutex> lock(ConsoleMutex);
	T in;
	std::cin >> in;
	std::cin.get(); //Consume \n
	return in;
}
