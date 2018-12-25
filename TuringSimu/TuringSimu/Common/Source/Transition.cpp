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
	if (!rawData[1].empty()) {
		this->currentChar = rawData[1].at(0);
	} else {
		this->currentChar = epsilon;
	}
	this->currentState = State{ rawData[0] };
	this->nextState = State{ rawData[2] };
	this->toWrite = rawData[3].at(0);
	this->headDirection = getDirection(rawData[4]);
}
ts_common::Transition::~Transition() {
}

/**
 * \brief Counts the number of transitions with the same currentChar and currentState fields
 * \param t The Transition determining the parameters to check
 * \param vector The vector to search
 * \return The count of transitions having the same currentChar and currentState field as the given Transition
 */
int Transition::countOccurrences(Transition& t, std::vector<Transition> vector) {
	int count = 0;
	for (const auto& element : vector) {
		if (element.currentState == t.currentState && element.currentChar == t.currentChar) {
			count++;
		}
	}
	return count;
}
;

void Transition::setCurrentChar(char c) {
	this->currentChar = c;
}

void Transition::setToWrite(char c) {
	this->toWrite = c;
}

void Transition::setHeadDirection(HeadDirection hd) {
	this->headDirection = hd;
}

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
	return !(*this == other);
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

