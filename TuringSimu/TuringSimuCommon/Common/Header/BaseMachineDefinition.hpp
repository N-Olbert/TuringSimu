#pragma once
#ifndef  TM_BASEMACHINEDEFINITION
#define  TM_BASEMACHINEDEFINITION
#include "State.hpp"
#include "MachineType.hpp"
#include "HashSet.hpp"
#include <vector>

namespace ts_common
{
	/**
	 * \brief The base machine definition for all kind of machines.
	 */
	template<class TransitionType> class BaseMachineDefinition
	{
		public:
			/**
			 * \brief The file name of the represented machine.
			 */
			std::string fileName;

			/**
			 * \brief The machine type.
			 */
			MachineType type = UNKNOWN;

			/**
			 * \brief The states of the machine.
			 */
			HashSet<State> states;

			/**
			 * \brief The final states of the machine.
			 */
			HashSet<State> finalStates;
		
			/**
			 * \brief The transitions. Must be a vector (not a map) cause we may encounter
			 * non-determinism which means that we deal with a relation instead of a function
			 */
			std::vector<TransitionType> transitions;

			/**
			 * \brief The inital state of the machine.
			 */
			State beginState;

			/**
			 * \brief Error flag
			 */
			bool error = false;
	};
}
#endif