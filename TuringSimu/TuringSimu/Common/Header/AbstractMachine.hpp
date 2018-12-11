#pragma once
#ifndef TM_ABSTRACTMACHINE
#define TM_ABSTRACTMACHINE
#include "AbstractMachineUserinterface.hpp"
#include <stdexcept>
namespace ts_common
{
	/**
	 * \brief The base class for all machines
	 */
	class AbstractMachine
	{
		private:
			/**
		     * \brief Pointer to the UI which observes the execution of the machine
		     */
		    AbstactMachineUserinterface* ui;

		protected:
			/**
			 * \brief Gets the UI which observes the current machine.
			 * \returns The UI.
			 */
			AbstactMachineUserinterface GetUI(){ return *this->ui;}

		public:
			/**
			 * \brief Creates a new instance of the AbstractMachine class.
			 * \param userinterface The observer of the current machine.
			 */
			AbstractMachine(AbstactMachineUserinterface*  userinterface)
			{
				if(userinterface == nullptr)
				{
					throw std::logic_error("No valid userinterface given.");
				}
				this->ui = userinterface;
			};

			
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
			virtual ~AbstractMachine() = default;
	};
}
#endif // TM_ABSTRACTMACHINE
