#pragma once
#ifndef  TM_TMDEFINITION
#define  TM_TMDEFINITION
#include "Transition.hpp"
#include "../../../TuringSimuCommon/Common/Header/BaseMachineDefinition.hpp"

namespace ts_common
{
	class TuringMachineDefinition : public BaseMachineDefinition<Transition>
	{
		public:
			HashSet<char> alphabet;
			HashSet<char> tapeAlphabet;
			char blank = 0;
	};
}
#endif