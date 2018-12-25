#include "../Header/State.hpp"
using namespace ts_common;

State::State(std::string identifier)
{
	this->identifier = identifier;
}

std::string& State::GetIdentifier()
{
	return this->identifier;
}

bool State::operator==(const State & other) const noexcept
{
	return this->identifier == other.identifier;
}

bool State::operator!=(const State & other) const noexcept
{
	return !(this->identifier == other.identifier);
}

bool State::operator<(const State& other) const noexcept
{
	return this->identifier.length() < other.identifier.length();
}

bool State::operator>(const State& other) const noexcept
{
	return this->identifier.length() > other.identifier.length();
}

size_t State::GetHashCode() const noexcept
{
	return std::hash<std::string>()(this->identifier);
}
