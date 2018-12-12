#pragma once
#include "../../Common/Header/TuringMachineDefinition.hpp"
#include "../../Common/Header/AbstractMachine.hpp"
#ifndef TS_TURINGMACHINE
using namespace ts_common;
namespace ts_business
{
	/*
	 * A class which represents a turing machine
	 */
	class TuringMachine : public AbstractMachine
	{
		private:
			/**
			 * \brief The definition of the machine
			 */
			ts_common::TuringMachineDefinition definition;
		public:
		TuringMachine(AbstactMachineUserinterface* userinterface, ts_common::TuringMachineDefinition definition)
			: AbstractMachine(userinterface)
		{
			this->definition = definition;
		}

		void PerformNextStep() override;
		bool IsFinished() override;
		~TuringMachine() override;
	};
}
#define TS_TURINGMACHINE
#endif