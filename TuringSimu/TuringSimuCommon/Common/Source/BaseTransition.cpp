#include "../../Common/Header/BaseTransition.hpp"
#include "../../Common/Header/State.hpp"

using namespace ts_common;

void ts_common::BaseTransition::SetCurrentState(State currentState)
{
	this->currentState = currentState;
}

void ts_common::BaseTransition::SetNextState(State nextState)
{
	this->nextState = nextState;
}

const State& BaseTransition::GetCurrentState() const
{
	return currentState;
}

const State& BaseTransition::GetNextState() const
{
	return nextState;
}

const bool ts_common::BaseTransition::operator==(const BaseTransition & other) const noexcept
{
	return this->currentState == other.currentState && this->nextState == other.nextState;
}

const bool ts_common::BaseTransition::operator!=(const BaseTransition & other) const noexcept
{
	return !(*this == other);
}

const bool ts_common::BaseTransition::operator<(const BaseTransition & other) const noexcept
{
	return this->currentState > other.currentState;
}

const bool ts_common::BaseTransition::operator>(const BaseTransition & other) const noexcept
{
	return !(*this < other);
}
