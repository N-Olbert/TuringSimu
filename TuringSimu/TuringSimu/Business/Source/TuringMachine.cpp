#include "../Header/TuringMachine.hpp"
#include "../../../TuringSimuUICommon/UI/Header/Localization.hpp"
using namespace ts_common;
using namespace ts_business;
using namespace ts_ui;
using AMU = AbstractMachineUserinterface;

TuringMachine::TuringMachine(AbstractMachineUserinterface* userinterface, TuringMachineDefinition& definition)
			: AbstractMachine(userinterface)
{
	this->definition = definition;
	this->head = std::make_unique<TuringMachineTapeHeader>(this->definition.blank);
}

bool TuringMachine::Init(std::string& initText)
{
	auto validChars = this->definition.tapeAlphabet;
	for (char c : initText)
	{
		if(!validChars.Contains(c))
		{
			AMU::NotifyInvalidMachineDefinition(GetUI(), Localization::GetString(LocId::ErrorInvalidCharOnTape));
			return false;
		}
	}

	this->head->InitWith(initText);
	this->currentState = this->definition.beginState;
	AMU::NotifyInitialized(GetUI(), initText, this->currentState.GetIdentifier());
	return true;
}

void TuringMachine::PerformNextStep()
{
	auto& transition = GetNextTransition();
	if(transition != Transition::Empty)
	{
		const auto toWrite = transition.GetToWrite();
		this->head->WriteChar(toWrite);
		AMU::NotifyTapeWritten(GetUI(), toWrite);

		const auto moveDirection = transition.GetHeadDirection();
		this->head->Move(moveDirection);
		AMU::NotifyHeadMoved(GetUI(), moveDirection);

		auto& nextState = transition.GetNextState();
		this->currentState = nextState;
		AMU::NotifyStateChanged(GetUI(), nextState.GetIdentifier());
	}
}

bool TuringMachine::IsFinished()
{
	if(this->definition.finalStates.Contains(this->currentState))
	{
		return GetNextTransition() == Transition::Empty;
	}

	return false;
}

std::string TuringMachine::GetSpecificValue(const std::string& valueIdentifier) const
{
	if (valueIdentifier == "BLANK")
	{
		return std::string{ this->definition.blank };
	}

	return UnknownSpecificValue;
}

Transition& TuringMachine::GetNextTransition()
{
	const auto currentChar = this->head->GetChar();
	auto& transitions = this->definition.transitions;
	for (auto& transition : transitions)
	{
		if(transition.GetCurrentState() == this->currentState &&
		    transition.GetCurrentChar() == currentChar)
		{
			return transition;
		}
	}

	return Transition::Empty;
}
