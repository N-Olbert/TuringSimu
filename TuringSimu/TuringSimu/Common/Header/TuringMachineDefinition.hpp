#pragma once
#ifndef  TM_TMDEFINITION
#define  TM_TMDEFINITION
#include <unordered_set>
#include <unordered_map>
#include "State.hpp"
#include "MachineType.hpp"
#include "Transition.hpp"
#include <map>
#include "ComparableHelpers.hpp"
#include "HashSet.hpp"

namespace ts_common
{
	class TuringMachineDefiniton
	{
		public:
			MachineType type;
			HashSet<State> states;
			HashSet<State> finalStates;
			HashSet<char> alphabet;
			HashSet<char> tapeAlphabet;
			char blank;
    
			/**
			 * \brief The transitions. Must be a vector (not a map) cause we may encounter
			 * non-determinism which means that we deal with a relation instead of a function
			 */
			std::vector<Transition> transitions
			State beginState;
	};
}
#endif