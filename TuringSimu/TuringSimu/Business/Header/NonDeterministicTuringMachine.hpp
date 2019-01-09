#pragma once
#include "../Header/TuringMachine.hpp"
using namespace ts_common;

namespace ts_business
{
	class NonDeterministicTuringMachine : public TuringMachine
	{
	private:
		const std::vector<const Transition*> GetNextTransitions() const;
	public:
		NonDeterministicTuringMachine(AbstractMachineUserinterface* userinterface, TuringMachineDefinition& definition) : TuringMachine(userinterface, definition) {};

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

	private:
		struct TraceData
		{
			std::unique_ptr<TuringMachineTapeHeader> Header;
			const Transition* Transiton;
		};

		std::vector<NonDeterministicTuringMachine::TraceData> backtraceList;
	};
}