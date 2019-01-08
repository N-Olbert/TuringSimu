#pragma once
#ifndef  TM_BASEMACHINEDEFINITION
#define  TM_BASEMACHINEDEFINITION
#include "State.hpp"
#include "MachineType.hpp"
#include "Transition.hpp"
#include "HashSet.hpp"
#include <vector>

namespace ts_common
{
	template<class TransitionType> class BaseMachineDefinition
	{
		public:
			std::string fileName;
			MachineType type = UNKNOWN;
			HashSet<State> states;
			HashSet<State> finalStates;
		
			/**
			 * \brief The transitions. Must be a vector (not a map) cause we may encounter
			 * non-determinism which means that we deal with a relation instead of a function
			 */
			std::vector<TransitionType> transitions;
			State beginState;
			bool error = false;
	};
}
#endif