#pragma once
#ifndef TMS_BASETRANSITION
#define TMS_BASETRANSITION
#include "State.hpp"
#include "StringRepresentable.hpp"
#include "BaseComparable.hpp"
namespace ts_common
{
	/**
	 * \brief The base class for all transitions.
	 */
	class BaseTransition : public StringRepresentable, public BaseComparable<BaseTransition>
	{
		private:
			/**
			 * \brief The current state.
			 */
			State currentState;

			/**
			 * \brief The next state.
			 */
			State nextState;

		protected:
			/**
			 * \brief Sets the current state to the given value.
			 * \param currentState The state to assign.
			 */
			void SetCurrentState(State currentState);

			/**
			 * \brief Sets the next state to the given value.
			 * \param nextState The state to assign.
			 */
			void SetNextState(State nextState);

		public:
			/**
			 * \brief Epsiolon (= any char).
			 */
			static const char Epsilon = '\0';

			/**
			 * \brief Gets the current state.
			 * \return The current state.
			 */
			const State& GetCurrentState() const;

			/**
			 * \brief Gets the next state.
			 * \return The next state.
			 */
			const State& GetNextState() const;

			/**
			 * \brief Gets sequence which must be present to go to the next state.
			 * \return The seqeunce.
			 */
			virtual const std::string GetToRead() const = 0;


			/**
			 * \brief Returns a value indicating whether the current (Base-)Transition is empty or not.
			 */
			const virtual bool IsEmpty() const = 0;

			////Overrides

			const virtual bool operator==(const BaseTransition& other) const noexcept override;
			const virtual bool operator!=(const BaseTransition& other) const noexcept override;
			const virtual bool operator<(const BaseTransition& other) const noexcept override;
			const virtual bool operator>(const BaseTransition& other) const noexcept override;
	};
}
#endif // TMS_BASETRANSITION
