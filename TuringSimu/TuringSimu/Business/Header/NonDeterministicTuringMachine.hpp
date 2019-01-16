#pragma once
#ifndef NONDETERMINISTICTURINGMACHINE_HPP
#define NONDETERMINISTICTURINGMACHINE_HPP
#include "../Header/TuringMachine.hpp"
using namespace ts_common;

namespace ts_business
{
	/*
	 * A class which represents a non deterministic turing machine \n
	 * \n
	 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!   ATTENTION   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! \n
	 * !!!!	There are two common theorems about whenever a (N)TM stops:												!!!! \n
	 * !!!!		1. the Turing machine stops as soon as it reaches any final state									!!!! \n
	 * !!!!		2. the Turing machine stops at the current state if no possible transition can be found anymore.	!!!! \n
	 * !!!! We have decided to go for the second definiton, which implies that a final state can also have exits.	!!!! \n
	 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! \n
	 */
	class NonDeterministicTuringMachine : public TuringMachine
	{
		private:
			/**
			 * \brief Gets all transitions which colud be choosen with the current machine state.
			 * \return Vector of possible transitions.
			 */
			const std::vector<const Transition*> GetNextTransitions() const;

		public:
			NonDeterministicTuringMachine(AbstractMachineUserinterface* userinterface, TuringMachineDefinition& definition) : TuringMachine(userinterface, definition) {};

			/**
			 * \brief Instructs the machine to perform the next step (if possible).
			 */
			void PerformNextStep() override;

			/**
			 * \brief Gets a value indicating whether the current machine my not perform any more
			 *			actions.
			 * \return true if the current machine may not perform any more actions.
			 */
			virtual bool IsFinished() const override;

			/**
			 * \brief Gets a value indicating whether the current machine has finished successfully.
			 * \return true if the current machine has finished successfully.
			 */
			bool IsFinishedSuccessfully() const override;

		private:
			/**
			 * \brief A snapshot of the current machine state.
			 */
			struct StateSnapshot
			{
				/**
				 * \brief The current header
				 */
				std::unique_ptr<TuringMachineTapeHeader> Header;

				/**
				 * \brief The next transition (containing the current machines state)
				 */
				const Transition* NextTransiton;
			};

			/**
			 * \brief A vector of possible crossroads we haven't choosen (yet).
			 * \n Used to backtrace them later on.
			 */
			std::vector<NonDeterministicTuringMachine::StateSnapshot> backtraceList;
	};
}
#endif // NONDETERMINISTICTURINGMACHINE_HPP
