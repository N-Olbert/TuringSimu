#pragma once
#include "../../Common/Header/TuringMachineDefinition.hpp"
#ifndef TS_TURINGMACHINE
namespace ts_business
{
	/*
	 * A class which represents a turing machine
	 */
	class TuringMachine
	{
		private:
			/**
			 * \brief The definition of the machine
			 */
			ts_common::TuringMachineDefiniton definition;
	};
}
#define TS_TURINGMACHINE
#endif