#pragma once
#ifndef  TM_TMDEFINITION
#define  TM_TMDEFINITION
#include "Transition.hpp"
#include "../../../TuringSimuCommon/Common/Header/BaseMachineDefinition.hpp"

namespace ts_common
{
	/**
	 * \brief Definiton of a turing machine (DTM/NTM)
	 */
	class TuringMachineDefinition : public BaseMachineDefinition<Transition>
	{
		public:

			/**
			 * \brief The alphabet
			 */
			HashSet<char> alphabet;

			/**
			 * \brief The tape alphabet (superset of alphabet)
			 */
			HashSet<char> tapeAlphabet;

			/**
			 * \brief The blank symbol
			 */
			char blank = 0;
	};
}
#endif