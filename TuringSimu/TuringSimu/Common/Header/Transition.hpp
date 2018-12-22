#pragma once
#ifndef TM_TRANSITION
#define TM_TRANSITION
#include "State.hpp"
#include "HeadDirection.hpp"

namespace ts_common
{
	class Transition :public BaseComparable<Transition> {
	public:
		Transition(State currentState, char currentChar,
			char toWrite, State nextState, HeadDirection headDirection);

		/**
		* \brief Special constructor needed when reading from a csvFile
		* \param csvLine the line of the .csv representing a Transition
		* \see CSVFormatV0.txt for additional info
		*/
		Transition(std::string csvLine);
		virtual ~Transition() {};

		State GetCurrentState() const;
		char GetCurrentChar() const;
		char GetToWrite() const;
		State GetNextState() const;
		HeadDirection GetHeadDirection() const;

		bool operator==(const Transition& other) const noexcept override;
		bool operator!=(const Transition& other) const noexcept override;
		bool operator<(const Transition& other) const noexcept override;
		bool operator>(const Transition& other) const noexcept override;
		size_t GetHashCode() const noexcept override;
	private:
		State currentState;
		char currentChar;
		char toWrite;
		State nextState;
		HeadDirection headDirection;

	};

	inline State Transition::GetCurrentState() const {
		return currentState;
	}

	inline char Transition::GetCurrentChar() const {
		return currentChar;
	}

	inline char Transition::GetToWrite() const {
		return toWrite;
	}

	inline State Transition::GetNextState() const {
		return nextState;
	}

	inline HeadDirection Transition::GetHeadDirection() const {
		return headDirection;
	}
}
#endif