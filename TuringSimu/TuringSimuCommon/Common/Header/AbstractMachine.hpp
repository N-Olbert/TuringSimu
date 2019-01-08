#pragma once
#ifndef TM_ABSTRACTMACHINE
#define TM_ABSTRACTMACHINE
#include "AbstractMachineUserinterface.hpp"
#include "State.hpp"
#include "BaseTransition.hpp"
#include "DynamicType.hpp"

namespace ts_common
{
	enum class SpecificMachineValue;

	/**
	 * \brief The base class for all machines
	 */
	class AbstractMachine
	{
		private:
			/**
		     * \brief Pointer to the UI which observes the execution of the machine
		     */
		    AbstractMachineUserinterface* ui;

		protected:
			/**
			 * \brief The current state of the machine
			 */
			State currentState;

			/**
			 * \brief Gets the UI which observes the current machine.
			 * \returns The UI.
			 */
			AbstractMachineUserinterface* GetUI() const { return this->ui;}

			/**
			 * \brief Gets the next transition based on the current state.
			 * \returns The next transition
			 */
			const virtual BaseTransition& GetNextTransition() = 0;

		public:			
			/**
			 * \brief Creates a new instance of the AbstractMachine class.
			 * \param userinterface The observer of the current machine.
			 */
			AbstractMachine(AbstractMachineUserinterface*  userinterface)
			{
				this->ui = userinterface;
			};

			/**
			 * \brief Sets/Replaces the observing UI.
			 * \param observer The userinterface which should observe the current machine.
			 */
			void SetObservingUI(AbstractMachineUserinterface* observer)
			{
				this->ui = observer;
			}

			/**
			 * \brief Initializes the machine using the given parameters
			 * \param params The initialization parameters.
			 * \return false if input was invalid; true otherwise. 
			 */
			virtual bool InitMachineForExecution(std::string& params) = 0;

			/**
			 * \brief Returnes a wrapper around a machine specific value
			 * \param valueIdentifier The id of the requested machine specific value.
			 * NOTE: Not all machines must support all SpecificMachineValue's
			 * \return Wrapper around requested machine specific value; nullptr if not supported.
			 */
			virtual std::unique_ptr<DynamicType> GetSpecificValue(SpecificMachineValue valueIdentifier) const = 0;
			
			/**
			 * \brief Instructs the machine to perform the next step (if possible).
			 */
			virtual void PerformNextStep() = 0;

			/**
			 * \brief Gets a value indicating whether the current machine my not perform any more 
			 *			actions.
			 * \return true if the current machine may not perform any more actions.
			 */
			virtual bool IsFinished() = 0;

			/**
			 * \brief Gets a value indicating whether the current machine has finished successfully.
			 * \return true if the current machine has finished successfully.
			 */
			virtual bool IsFinishedSuccessfully() = 0;

			virtual ~AbstractMachine() = default;
	};

	/**
	 * \brief Enumeration of all possible specific machine values for usage within
	 *  the AbstractMachine::GetSpecificValue-Method.
	 * \nNote: Not all machines must support all values.
	 * \n(For example a plain NEA doesn't know a tape and therefore may not support
	 * tape related enum values (like SpecificMachineValue::Alphabet))
	 */
	enum class SpecificMachineValue
	{
		Blank,
		FileName,
		Type,
		States,
		FinalStates,
		Alphabet,
		TapeAlphabet,
		Transitions,
		InitialState,
		TapeContent
	};
}
#endif // TM_ABSTRACTMACHINE
