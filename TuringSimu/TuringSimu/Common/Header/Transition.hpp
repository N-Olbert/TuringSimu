#pragma once
#ifndef TM_TRANSITION
#define TM_TRANSITION
#include "../../../TuringSimuCommon/Common/Header/State.hpp"
#include "../../../TuringSimuCommon/Common/Header/HeadDirection.hpp"
#include "../../../TuringSimuCommon/Common/Header/BaseTransition.hpp"
#include <vector>

namespace ts_common
{
	/**
	 * \brief The definition of a transition for a turing machine.
	 */
	class Transition : public BaseTransition, public BaseComparable<Transition>
	{
		private:
			/**
			 * \brief The current char we read
			 */
			char currentChar;

			/**
			 * \brief The char which should be written
			 */
			char toWrite;

			/**
			 * \brief The direction in which we should move the head
			 */
			HeadDirection headDirection;

			/**
			 * \brief Private constructor. Only used for creation of emtpy objects.
			 */
			Transition() : currentChar(0), toWrite(0), headDirection(Stay) {}

		public:	
			/**
			 * \brief An empty transition.
			 */
			static const Transition Empty;

			/**
			 * \brief Constructor
			 */
			Transition(State currentState, char currentChar, char toWrite, State nextState, HeadDirection headDirection);

			/**
			 * \brief Special constructor needed when reading from a csvFile
			 * \param csvLine the line of the .csv representing a Transition
			 * \see CSVFormatV0.txt for additional info
			 */
			explicit Transition(std::string csvLine);

			/**
			 * \brief Gets the current char
			 */
			char GetCurrentChar() const;

			/**
			 * \brief Gets the char to write
			 */
			char GetToWrite() const;

			/**
			 * \brief Gets the heads moving direction
			 */
			HeadDirection GetHeadDirection() const;

			/**
			 * \brief Gets sequence which must be present to go to the next state.
			 * \return The seqeunce.
			 */
			virtual const std::string GetToRead() const override;

			/**
			 * \brief Counts the number of transitions with the same currentChar and currentState fields
			 * \param t The Transition determining the parameters to check
			 * \param vector The vector to search
			 * \return The count of transitions having the same currentChar and currentState field as the given Transition
			 */
			static int countOccurrences(const Transition& t, const std::vector<Transition>& vector);

			//Interface implementations
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