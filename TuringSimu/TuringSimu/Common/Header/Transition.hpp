#pragma once
#include "State.hpp"
#include "HeadDirection.hpp"
#ifndef TSTMTRANSITION
namespace ts_common
{
	class Transition
	{
		public:
			State GetCurrentState() const;
			char GetCurrentChar() const;
			char GetToWrite() const;
			State GetNextState() const;
			HeadDirection GetHeadDirection() const;

		private:
			State currentState;
			char currentChar;
			char toWrite;
			State nextState;
			HeadDirection headDirection;

		public:
			Transition(State currentState, char currentChar, 
					   char toWrite, State nextState, HeadDirection headDirection);
			virtual ~Transition() {};
	};

	inline State Transition::GetCurrentState() const
	{
		return currentState;
	}

	inline char Transition::GetCurrentChar() const
	{
		return currentChar;
	}

	inline char Transition::GetToWrite() const
	{
		return toWrite;
	}

	inline State Transition::GetNextState() const
	{
		return nextState;
	}

	inline HeadDirection Transition::GetHeadDirection() const
	{
		return headDirection;
	}
}
#define TSTMTRANSITION
#endif