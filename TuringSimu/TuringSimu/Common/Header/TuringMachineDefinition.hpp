#pragma once
#ifndef  TM_TMDEFINITION
#define  TM_TMDEFINITION
#include <unordered_set>
#include <unordered_map>
#include "State.hpp"
#include "MachineType.hpp"
#include "Transition.hpp"
namespace ts_common
{
	class TuringMachineDefiniton
	{
		MachineType type;
		std::unordered_set<State> states;
		std::unordered_set<State> finalStates;
		std::unordered_set<char> alphabet;
		std::unordered_set<char> tapeAlphabet;
		char blank;
		std::unordered_map<std::pair<State, char>, Transition> transitions;
		State beginState;
	};
}
#endif