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
			std::unordered_map<std::pair<State, char>, Transition, Hasher<std::pair<State, char>>> transitions;
			State beginState;
	};
}
#endif