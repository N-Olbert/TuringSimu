#include "../Header/Transition.hpp"
#include "../Header/State.hpp"

using namespace ts_common;
Transition::Transition(State currentState, char currentChar,
					   char toWrite, State nextState, HeadDirection headDirection)
{
	this->currentState = currentState;
	this->currentChar = currentChar;
	this->toWrite = toWrite;
	this->nextState = nextState;
	this->headDirection = headDirection;
}


