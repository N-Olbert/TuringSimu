#pragma once
#ifndef TM_ABSTRACTMACHINEUSERINTERFACE
#define TM_ABSTRACTMACHINEUSERINTERFACE
#include <string>
#include "HeadDirection.hpp"
#include "State.hpp"
#include "ErrorDisplayableUserinterface.hpp"
#include "BaseTransition.hpp"

namespace ts_common
{
	/**
	 * \brief Abstract base class for all userinterfaces which should be used to receive events from
	 * machine execution.
	 */
	class AbstractMachineUserinterface : public ErrorDisplayableUserinterface
	{
		public:
		virtual ~AbstractMachineUserinterface() = default;

		/**
		 * \brief Called after the observed machine has been initialized.
		 */
		virtual void OnInitialized() = 0;

		/**
		 * \brief Called after the a transition has been choosen by the machine.
		 */
		virtual void OnTransitionChoosen(const BaseTransition& transition) = 0;

		/**
		 * \brief Called after the observed machine has written a char onto the tape.
		 * \param written The char which has been written.
		 */
		virtual void OnTapeWritten(char written) = 0;

		/**
		 * \brief Called after the observed machine has moved its head.
		 * \param written The direction into which the head has been moved.
		 */
		virtual void OnHeadMoved(HeadDirection direction) = 0; 

		/**
		 * \brief Called after the observed machine has changed its state.
		 * \param written The ne state of the machine.
		 */
		virtual void OnStateChanged(const State& newState) = 0;

		/**
		 * \brief Called after the observed machine has performed a change towards a different execution path (-> backtracking).
		 */
		virtual void OnBacktraceDifferentExecutionPathChosen() = 0;

		/**
		 * \brief Notifies the given AMU that the associated machine has been initalized.
		 * \param toNotify The AMU which should be notified. May be nullptr.
		 */
		static void NotifyInitialized(AbstractMachineUserinterface* toNotify);

		/**
		 * \brief Notifies the given AMU that the associated machine has choosen a transition to execute.
		 * \param toNotify The AMU which should be notified. May be nullptr.
		 */
		static void NotifyTransitionChoosen(AbstractMachineUserinterface* toNotify, const BaseTransition& transition);

		/**
		 * \brief Notifies the given AMU that the associated machine has been written a char onto the tape.
		 * \param toNotify The AMU which should be notified. May be nullptr.
		 * \param written The char which has been written.
		 */
		static void NotifyTapeWritten(AbstractMachineUserinterface* toNotify, char written);

		/**
		 * \brief Notifies the given AMU that the associated machine has moved its head.
		 * \param toNotify The AMU which should be notified. May be nullptr.
		 * \param written The direction into which the machine moved its head.
		 */
		static void NotifyHeadMoved(AbstractMachineUserinterface* toNotify, HeadDirection direction);

		/**
		 * \brief Notifies the given AMU that the associated machine has changed its state.
		 * \param toNotify The AMU which should be notified. May be nullptr.
		 * \param newState The new state of the machine.
		 */
		static void NotifyStateChanged(AbstractMachineUserinterface* toNotify, const State& newState);

		/**
		 * \brief Notifies the given AMU that the associated machine has changed its execution path.
		 * \param toNotify The AMU which should be notified. May be nullptr.
		 */
		static void NotifyBacktraceDifferentExecutionPathChosen(AbstractMachineUserinterface* toNotify);
	};
}
#endif // TM_ABSTRACTMACHINEUSERINTERFACE
