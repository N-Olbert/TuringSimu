#pragma once
#ifndef TS_TURINGMACHINE
#include "TuringMachineTapeHeader.hpp"
#include "../../../TuringSimuCommon/Common/Header/DynamicType.hpp"
#include "../../Common/Header/TuringMachineDefinition.hpp"
#include "../../../TuringSimuCommon/Common/Header/AbstractMachine.hpp"
#include "../../../TuringSimuCommon/Common/Header/AbstractMachineUserinterface.hpp"
#include "TuringMachine.hpp"

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
			TuringMachine(TuringMachineDefinition& definition) : TuringMachine(nullptr, definition) {};
			bool InitMachineForExecution(std::string& initText) override;
			void PerformNextStep() override;
			bool IsFinished() override;
			bool IsFinishedSuccessfully() override;
			std::unique_ptr<DynamicType> GetSpecificValue(SpecificMachineValue valueIdentifier) const override;
			~TuringMachine() override = default;
		protected:
			const Transition& GetNextTransition() override;
		private:

			/**
			 * \brief A private class which allows us to store a unique pointer of a concrete type (because a unique_ptr
			 * cant be created for a void pointer). Anyways from outside the concrete type will never be visible. 
			 * \tparam T Concrete type of stored object.
			 */
			template<class T> class ConcreteDynamicType : public DynamicType
			{
				private:
					std::unique_ptr<T> value;
				protected:
					const void* GetValue() override
					{
						return static_cast<void*>(this->value.get());
					}

				public:
					ConcreteDynamicType(const T& instanceToCarry)
					{
						this->value = std::unique_ptr<T>(new T{ instanceToCarry });
					}
			};
	};
}

#endif