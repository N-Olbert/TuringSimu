#pragma once
#include "TuringMachineTapeHeader.hpp"
#ifndef TS_TURINGMACHINE
#include "../../Common/Header/TuringMachineDefinition.hpp"
#include "../../Common/Header/AbstractMachine.hpp"

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
			TuringMachineDefinition definition;
			std::unique_ptr<TuringMachineTapeHeader> head;
		public:
			TuringMachine(AbstractMachineUserinterface* userinterface, TuringMachineDefinition& definition);
			bool Init(std::string& initText) override;
			void PerformNextStep() override;
			bool IsFinished() override;
			std::string GetSpecificValue(const std::string& valueIdentifier) const override;
			~TuringMachine() override = default;
		protected:
			Transition& GetNextTransition() override;
	};
}

#endif