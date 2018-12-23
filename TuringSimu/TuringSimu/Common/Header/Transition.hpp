#pragma once
#ifndef TM_TRANSITION
#define TM_TRANSITION
#include "State.hpp"
#include "HeadDirection.hpp"
#include "BaseTransition.hpp"

namespace ts_common
{
	class Transition:public BaseComparable<Transition>, public BaseTransition
	{
		public:
			static Transition Empty;
			Transition(State currentState, char currentChar,
				char toWrite, State nextState, HeadDirection headDirection);
      
      /**
		  * \brief Special constructor needed when reading from a csvFile
		  * \param csvLine the line of the .csv representing a Transition
		  * \see CSVFormatV0.txt for additional info
		  */
			Transition(std::string csvLine);
			~Transition() override;

			State& GetCurrentState();
			char GetCurrentChar() const;
			char GetToWrite() const;
			State& GetNextState();
			HeadDirection GetHeadDirection() const;

			bool operator==(const Transition& other) const noexcept override;
			bool operator!=(const Transition& other) const noexcept override;
			bool operator<(const Transition& other) const noexcept override;
			bool operator>(const Transition& other) const noexcept override;
			size_t GetHashCode() const noexcept override;
		private:
			Transition(): currentChar(0), toWrite(0), headDirection(Stay){};
			State currentState;
			char currentChar;
			char toWrite;
			State nextState;
			HeadDirection headDirection;

	};

	inline State& Transition::GetCurrentState()
	{
		return currentState;
	}

	inline char Transition::GetCurrentChar() const {
		return currentChar;
	}

	inline char Transition::GetToWrite() const {
		return toWrite;
	}

	inline State& Transition::GetNextState()
	{
		return nextState;
	}

	inline HeadDirection Transition::GetHeadDirection() const {
		return headDirection;
	}
}
#endif