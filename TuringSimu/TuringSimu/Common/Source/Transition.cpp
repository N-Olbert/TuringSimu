#include "../Header/Transition.hpp"
#include "../Header/Utility.hpp"

using namespace ts_common;
Transition::Transition(State currentState, char currentChar,
					   char toWrite, State nextState, HeadDirection headDirection)
{
	this->currentState = State{currentState};
	this->currentChar = currentChar;
	this->toWrite = toWrite;
	this->nextState = State{nextState};
	this->headDirection = headDirection;
}
Transition::Transition(std::string csvLine)
{
	auto rawData = split(csvLine);
	this->currentChar = rawData[1].at(0);
	this->currentState = State{ rawData[0] };
	this->nextState = State{ rawData[2] };
	this->toWrite = rawData[3].at(0);
	this->headDirection = getDirection(rawData[4]);
};


