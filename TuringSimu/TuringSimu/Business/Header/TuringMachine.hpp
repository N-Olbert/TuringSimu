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
	 * A class which represents a turing machine \n
	 * \n
	 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!   ATTENTION   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! \n
	 * !!!!	There are two common theorems about whenever a (N)TM stops:												!!!! \n
	 * !!!!		1. the Turing machine stops as soon as it reaches any final state									!!!! \n
	 * !!!!		2. the Turing machine stops at the current state if no possible transition can be found anymore.	!!!! \n
	 * !!!! We have decided to go for the second definiton, which implies that a final state can also have exits.	!!!! \n
	 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! \n
	 */
	class TuringMachine : public AbstractMachine
	{
		protected:
			/**
			 * \brief The definition of the machine
			 */
			TuringMachineDefinition definition;

			/**
			 * \brief The head of the turing machine (ptr as we dont know how large the tape will become)
			 */
			std::unique_ptr<TuringMachineTapeHeader> head;
			
		public:
			/**
			 * \brief Creates a new instance of the TuringMachine class.
			 * \param userinterface Observing UI (may be nullptr)
			 * \param definition The definiton for use within the machine
			 */
			TuringMachine(AbstractMachineUserinterface* userinterface, TuringMachineDefinition& definition);

			/**
			 * \brief Creates a new instance of the TuringMachine class with no observing ui.
			 * \param definition The definiton for use within the machine
			 */
			TuringMachine(TuringMachineDefinition& definition) : TuringMachine(nullptr, definition) {};

			/**
			 * \brief Initializes the machine using the given parameters
			 * \param params The initialization parameters.
			 * \n !!! NOTE: threated as inital tape content!!!
			 * \return false if input was invalid; true otherwise.
			 */
			bool InitMachineForExecution(std::string& params) override;

			/**
			 * \brief Instructs the machine to perform the next step (if possible).
			 */
			void PerformNextStep() override;

			/**
			 * \brief Gets a value indicating whether the current machine my not perform any more
			 *			actions.
			 * \return true if the current machine may not perform any more actions.
			 */
			virtual bool IsFinished() const override;

			/**
			 * \brief Gets a value indicating whether the current machine has finished successfully.
			 * \return true if the current machine has finished successfully.
			 */
			bool IsFinishedSuccessfully() const override;

			/**
			 * \brief Returnes a wrapper around a machine specific value
			 * \param valueIdentifier The id of the requested machine specific value.
			 * NOTE: Not all machines must support all SpecificMachineValue's
			 * \return Wrapper around requested machine specific value; nullptr if not supported request.
			 */
			std::unique_ptr<DynamicType> GetSpecificValue(SpecificMachineValue valueIdentifier) const override;

		protected:
			/**
			 * \brief Gets the next transition based on the current machine state.
			 * \returns The next transition
			 */
			const Transition& GetNextTransition() const override;

		protected:
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