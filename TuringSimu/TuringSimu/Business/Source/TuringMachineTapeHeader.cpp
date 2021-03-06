#include "../Header/TuringMachineTapeHeader.hpp"
using namespace ts_business;
void TuringMachineTapeHeader::Move(HeadDirection direction)
{
	switch (direction) 
	{ 
		case Left:
			this->rawPosition--;
			break;
		case Right:
			this->rawPosition++;
			break;
		case Stay: 
			break;
	}
}

char TuringMachineTapeHeader::GetChar()
{
	const auto pos = GetAdjustedPosition();
	auto toLookup = GetVector();
	if (toLookup.size() > pos)
	{
		return toLookup.at(pos);
	}

	return this->blankSymbol;
}

void TuringMachineTapeHeader::WriteChar(const char toWrite)
{
	const auto pos = GetAdjustedPosition();
	auto& toModify = GetVector();
	while(toModify.size() <= pos)
	{
		toModify.push_back(this->blankSymbol);
	}

	toModify[pos] = toWrite;
}

void TuringMachineTapeHeader::InitWith(const std::string& input)
{
	this->inputPositiveDirection.clear();
	this->inputNegativeDirection.clear();
	for (char c : input)
	{
		this->inputPositiveDirection.push_back(c);
	}

	this->rawPosition = 0;
}

std::string TuringMachineTapeHeader::GetCurrentTapeContent()
{
	std::string result;
	for (auto c : this->inputNegativeDirection)
	{
		result.push_back(c);
	}

	for (auto c : this->inputPositiveDirection)
	{
		result.push_back(c);
	}

	return result;
}

std::vector<char>& TuringMachineTapeHeader::GetVector() noexcept
{
	return this->rawPosition >= 0 ? 
		   this->inputPositiveDirection : this->inputNegativeDirection;
}

size_t TuringMachineTapeHeader::GetAdjustedPosition() const noexcept
{
	return this->rawPosition >= 0 ? this->rawPosition : (this->rawPosition * -1) - 1;
}

size_t TuringMachineTapeHeader::GetAdjustedUIPosition() const noexcept
{
	return this->rawPosition >= 0 ? this->rawPosition : (this->inputNegativeDirection.size() - (this->rawPosition * -1));
}
