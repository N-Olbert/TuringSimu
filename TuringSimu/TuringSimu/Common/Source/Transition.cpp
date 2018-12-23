#include "../Header/Transition.hpp"
#include "../Header/Utility.hpp"

using namespace ts_common;
Transition Transition::Empty;
Transition::Transition(State currentState, char currentChar,
	char toWrite, State nextState, HeadDirection headDirection) {
	this->currentState = State{ currentState };
	this->currentChar = currentChar;
	this->toWrite = toWrite;
	this->nextState = State{ nextState };
	this->headDirection = headDirection;
}
Transition::Transition(std::string csvLine) {
	auto rawData = split(csvLine);
	this->currentChar = rawData[1].at(0);
	this->currentState = State{ rawData[0] };
	this->nextState = State{ rawData[2] };
	this->toWrite = rawData[3].at(0);
	this->headDirection = getDirection(rawData[4]);
}
ts_common::Transition::~Transition()
{
}
;

bool Transition::operator==(const Transition& other) const noexcept {
	return this->toWrite == other.toWrite&& this->currentChar == other.currentChar
		&&this->currentState == other.currentState &&this->headDirection == other.headDirection
		&&this->nextState == other.nextState;
}


/**
 * \brief Compares two transitions for inequaltity (by checking for their equality)
 * \param other the Transition to compare against
 * \return True if their unqual, false otherwise
 */
bool Transition::operator!=(const Transition& other) const noexcept {
	return !(*this==other);
}


/**
 * \brief Compares order, you shouldnt really be doing that tho
 * \param other the Transition to compare against
 * \return True if the currentState of this is greater than the currentState of other, false otherwise
 */
bool Transition::operator<(const Transition& other) const noexcept {
	return this->currentState > other.currentState;
}
bool Transition::operator>(const Transition& other) const noexcept {
	return !(*this > other);
}

size_t Transition::GetHashCode() const noexcept {
	return (this->currentState.GetHashCode()) + std::hash<char>()(this->currentChar)
		+ std::hash<char>()(this->toWrite) + this->headDirection + this->nextState.GetHashCode();
}

