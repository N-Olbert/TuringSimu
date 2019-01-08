#pragma once
#ifndef TMS_BASETRANSITION
#define TMS_BASETRANSITION
#include "State.hpp"
#include "StringRepresentable.hpp"
#include "BaseComparable.hpp"
namespace ts_common
{
	class BaseTransition : public StringRepresentable, public BaseComparable<BaseTransition>
	{
		private:
			State currentState;
			State nextState;
		protected:
			void SetCurrentState(State currentState);
			void SetNextState(State nextState);
		public:
			virtual ~BaseTransition() = default;
			const State& GetCurrentState() const;
			const State& GetNextState() const;
			const virtual bool IsEmpty() const = 0;
			const virtual bool operator==(const BaseTransition& other) const noexcept override;
			const virtual bool operator!=(const BaseTransition& other) const noexcept override;
			const virtual bool operator<(const BaseTransition& other) const noexcept override;
			const virtual bool operator>(const BaseTransition& other) const noexcept override;
	};
}
#endif // TMS_BASETRANSITION
