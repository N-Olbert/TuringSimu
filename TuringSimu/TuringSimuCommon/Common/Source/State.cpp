#include "../Header/State.hpp"
using namespace ts_common;

State::State(std::string identifier)
{
	this->identifier = identifier;
}

const std::string& State::GetIdentifier() const
{
	return this->identifier;
}

const bool State::operator==(const State & other) const noexcept
{
	return this->identifier == other.identifier;
}

const bool State::operator!=(const State & other) const noexcept
{
	return !(this->identifier == other.identifier);
}

const bool State::operator<(const State& other) const noexcept
{
	return this->identifier.length() < other.identifier.length();
}

const bool State::operator>(const State& other) const noexcept
{
	return this->identifier.length() > other.identifier.length();
}

const size_t State::GetHashCode() const noexcept
{
	return std::hash<std::string>()(this->identifier);
}

std::string State::ToString() const noexcept
{
	return GetIdentifier();
}
