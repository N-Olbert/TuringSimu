#pragma once
#ifndef TM_TRANSITION
#define TM_TRANSITION
#include "../../../TuringSimuCommon/Common/Header/State.hpp"
#include "../../../TuringSimuCommon/Common/Header/HeadDirection.hpp"
#include "../../../TuringSimuCommon/Common/Header/BaseTransition.hpp"
#include <vector>

namespace ts_common
{
	static const char epsilon = '\0';
	class Transition : public BaseTransition, public BaseComparable<Transition>
	{
		private:
			char currentChar;
			char toWrite;
			HeadDirection headDirection;
			Transition() : currentChar(0), toWrite(0), headDirection(Stay) {}

		public:		
			static const Transition Empty;
			Transition(State currentState, char currentChar,
				char toWrite, State nextState, HeadDirection headDirection);

			/**
				* \brief Special constructor needed when reading from a csvFile
				* \param csvLine the line of the .csv representing a Transition
				* \see CSVFormatV0.txt for additional info
				*/
			explicit Transition(std::string csvLine);

			static int countOccurrences(const Transition& t, const std::vector<Transition>& vector);
			char GetCurrentChar() const;
			char GetToWrite() const;
			HeadDirection GetHeadDirection() const;

			void setCurrentChar(char c);
			void setToWrite(char c);
			void setHeadDirection(HeadDirection hd);

			const bool IsEmpty() const override;
			const bool operator==(const BaseTransition& other) const noexcept override;
			const bool operator!=(const BaseTransition& other) const noexcept override;
			const bool operator<(const BaseTransition& other) const noexcept override;
			const bool operator>(const BaseTransition& other) const noexcept override;
			const bool operator==(const Transition& other) const noexcept override;
			const bool operator!=(const Transition& other) const noexcept override;
			const bool operator<(const Transition& other) const noexcept override;
			const bool operator>(const Transition& other) const noexcept override;
			const size_t GetHashCode() const noexcept override;
			std::string ToString() const noexcept override;
	};
}
#endif