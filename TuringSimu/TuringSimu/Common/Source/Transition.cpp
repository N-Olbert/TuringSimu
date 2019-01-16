#include "../Header/Transition.hpp"
#include "../../../TuringSimuCommon/Common/Header/Utility.hpp"

using namespace ts_common;
const Transition Transition::Empty = Transition{};
Transition::Transition(State currentState, char currentChar,
					   char toWrite, State nextState, HeadDirection headDirection)
{
	this->SetCurrentState(currentState);
	this->currentChar = currentChar;
	this->toWrite = toWrite;
	this->SetNextState(nextState);
	this->headDirection = headDirection;
}

Transition::Transition(std::string csvLine)
{
	auto rawData = split(csvLine);
	if (!rawData[1].empty()) {
		this->currentChar = rawData[1].at(0);
	} else {
		this->currentChar = BaseTransition::Epsilon;
	}
	this->SetCurrentState(State{ rawData[0] });
	this->SetNextState(State{ rawData[2] });
	this->toWrite = rawData[3].at(0);
	this->headDirection = getDirection(rawData[4]);
}

char Transition::GetCurrentChar() const
{
	return currentChar;
}

char Transition::GetToWrite() const
{
	return toWrite;
}

HeadDirection Transition::GetHeadDirection() const 
{
	return headDirection;
}

const std::string ts_common::Transition::GetToRead() const
{
	return std::string{ currentChar };
}

int Transition::countOccurrences(const Transition& t, const std::vector<Transition>& vector) 
{
	int count = 0;
	for (const auto& element : vector) 
	{
		if (element.GetCurrentState() == t.GetCurrentState() && element.currentChar == t.currentChar) 
		{
			count++;
		}
	}
	return count;
}

const bool Transition::IsEmpty() const
{
	return Empty == *this;
}

const bool Transition::operator==(const BaseTransition & other) const noexcept
{
	try
	{
		const auto& casted = dynamic_cast<const Transition&>(other);
		return Transition::operator==(casted);
	}
	catch (const std::bad_cast&)
	{
		return false;
	}
}

const bool Transition::operator!=(const BaseTransition & other) const noexcept
{
	try
	{
		const auto& casted = dynamic_cast<const Transition&>(other);
		return !Transition::operator==(casted);
	}
	catch (const std::bad_cast&)
	{
		return false;
	}
}

const bool Transition::operator<(const BaseTransition & other) const noexcept
{
	try
	{
		const auto& casted = dynamic_cast<const Transition&>(other);
		return Transition::operator<(casted);
	}
	catch (const std::bad_cast&)
	{
		return false;
	}
}

const bool Transition::operator>(const BaseTransition & other) const noexcept
{
	try
	{
		const auto& casted = dynamic_cast<const Transition&>(other);
		return !Transition::operator<(casted);
	}
	catch (const std::bad_cast&)
	{
		return false;
	}
}

const bool Transition::operator==(const Transition& other) const noexcept 
{
	return BaseTransition::operator==(other) &&
		   this->toWrite == other.toWrite&& this->currentChar == other.currentChar &&this->headDirection == other.headDirection;
}

/**
 * \brief Compares two transitions for inequaltity (by checking for their equality)
 * \param other the Transition to compare against
 * \return True if their unqual, false otherwise
 */
const bool Transition::operator!=(const Transition& other) const noexcept
{
	return !(*this == other);
}

/**
 * \brief Compares order, you shouldnt really be doing that tho
 * \param other the Transition to compare against
 * \return True if the currentState of this is greater than the currentState of other, false otherwise
 */
const bool Transition::operator<(const Transition& other) const noexcept 
{
	return BaseTransition::operator<(other);
}

const bool Transition::operator>(const Transition& other) const noexcept 
{
	return BaseTransition::operator>(other);
}

const size_t Transition::GetHashCode() const noexcept 
{
	return (this->GetCurrentState().GetHashCode()) + std::hash<char>()(this->currentChar)
		+ std::hash<char>()(this->toWrite) + this->headDirection + this->GetNextState().GetHashCode();
}

std::string Transition::ToString() const noexcept
{
	std::string r;
	r.append(GetCurrentState().ToString());
	r.push_back('/');
	r.push_back(GetCurrentChar());
	r.push_back('/');
	r.push_back(GetToWrite());
	r.push_back('/');
	r.append(GetNextState().ToString());
	r.push_back('/');
	r.append(DirectionAsString(this->headDirection));
	return r;
}