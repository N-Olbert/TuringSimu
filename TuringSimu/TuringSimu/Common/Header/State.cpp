#include "State.hpp"

ts_common::State::State()
{
}

ts_common::State::State(std::string identifer)
{
	this->identifier = identifer;
}

std::string ts_common::State::GetIdentifier()
{
	return this->identifier;
}

bool ts_common::State::operator==(const State & other) const noexcept
{
	return this->identifier == other.identifier;
}

bool ts_common::State::operator!=(const State & other) const noexcept
{
	return this->identifier != other.identifier;
}

bool ts_common::State::operator<(const State& other) const noexcept
{
	return this->identifier.length() < other.identifier.length();
}

bool ts_common::State::operator>(const State& other) const noexcept
{
	return this->identifier.length() > other.identifier.length();
}

size_t ts_common::State::GetHashCode() const noexcept
{
	return std::hash<std::string>()(this->identifier);
}
