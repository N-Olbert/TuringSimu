#include "..\Header\Console.hpp"
#include <iostream>
#include <cctype>
#include <string>

using namespace ts_ui;
const std::string Console::ESC = std::string{"\x1b"};
const std::string Console::CSI = std::string{"\x1b["};
const std::string Console::AnsiLineUp = std::string{"A"};
const std::string Console::AnsiClearLine = std::string{"K"};
const std::string Console::CarriageReturn = std::string{"\r"};
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

void Console::PrintLine(const std::string& toPrint)
{
	Print(toPrint);
	NewLine();
}

void Console::NewLine()
{
	Print("\n");
}

void Console::LineBack()
{
	const auto command = ESC + AnsiLineUp + CarriageReturn;
	Print(command);
}

void Console::ClearLine()
{
	const auto command = CSI + AnsiClearLine;
	Print(command);
}

void Console::ClearScreen()
{
	const auto command = CSI + "2J";
	Print(command);
}

void Console::HideCursor()
{
	const auto command = CSI + "?25l";
	Print(command);
}

void Console::ShowCursor()
{
	const auto command = CSI + "?25h";
	Print(command);
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
