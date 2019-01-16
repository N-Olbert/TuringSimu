#include "../Header/TuringMachine.hpp"
#include "../../../TuringSimuCommon/UI/Header/Localization.hpp"
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

bool TuringMachine::InitMachineForExecution(std::string& initText)
{
	auto validChars = this->definition.tapeAlphabet;
	for (char c : initText)
	{
		if(!validChars.Contains(c))
		{
			AMU::NotifyError(GetUI(), Localization::GetString(LocId::ErrorInvalidCharOnTape));
			return false;
		}
	}

	this->head->InitWith(initText);
	this->currentState = this->definition.beginState;
	AMU::NotifyInitialized(GetUI());
	auto& transition = GetNextTransition();
	if (!transition.IsEmpty())
	{
		AMU::NotifyTransitionChoosen(GetUI(), transition);
	}

	return true;
}

void TuringMachine::PerformNextStep()
{
	auto& transition = GetNextTransition();
	if(!transition.IsEmpty())
	{
		const auto toWrite = transition.GetToWrite();
		this->head->WriteChar(toWrite);
		AMU::NotifyTapeWritten(GetUI(), toWrite);

		const auto moveDirection = transition.GetHeadDirection();
		this->head->Move(moveDirection);
		AMU::NotifyHeadMoved(GetUI(), moveDirection);

		auto& nextState = transition.GetNextState();
		this->currentState = nextState;
		AMU::NotifyStateChanged(GetUI(), nextState);
		auto& nextTransition = GetNextTransition();
		if (!nextTransition.IsEmpty())
		{
			AMU::NotifyTransitionChoosen(GetUI(), nextTransition);
		}
	}
}

bool TuringMachine::IsFinished() const
{
	//Attention: There are two common theorems about whenever a TM stops: 
	//		1. the Turing machine stops as soon as it reaches any final state
	//		2. the Turing machine stops at the current state if no possible transition can be found anymore
	//We have decided to go for the second definiton, which implies that a final state can also have exits.
	return GetNextTransition().IsEmpty();
}

bool TuringMachine::IsFinishedSuccessfully() const
{
	//Attention: There are two common theorems about whenever a TM stops: 
	//		1. the Turing machine stops as soon as it reaches any final state
	//		2. the Turing machine stops at the current state if no possible transition can be found anymore
	//We have decided to go for the second definiton, which implies that a final state can also have exits.
	return this->definition.finalStates.Contains(this->currentState) && IsFinished();
}

std::unique_ptr<DynamicType> TuringMachine::GetSpecificValue(SpecificMachineValue valueIdentifier) const
{
	using S = SpecificMachineValue;
	switch (valueIdentifier)
	{
		case S::Blank: 
			return std::make_unique<ConcreteDynamicType<char>>(this->definition.blank);
		case S::FileName: 
			return std::make_unique<ConcreteDynamicType<std::string>>(this->definition.fileName);
		case S::Type: 
			return std::make_unique<ConcreteDynamicType<MachineType>>(this->definition.type);
		case S::States: 
			return std::make_unique<ConcreteDynamicType<HashSet<State>>>(this->definition.states);
		case S::FinalStates: 
			return std::make_unique<ConcreteDynamicType<HashSet<State>>>(this->definition.finalStates);
		case S::Alphabet:
			return std::make_unique<ConcreteDynamicType<HashSet<char>>>(this->definition.alphabet);
		case S::TapeAlphabet: 
			return std::make_unique<ConcreteDynamicType<HashSet<char>>>(this->definition.tapeAlphabet);
		case S::Transitions:
			{
				auto result = std::vector<const StringRepresentable*>{};
				for (auto& tmp: this->definition.transitions)
				{
					result.push_back(&tmp);
				}

				return std::make_unique<ConcreteDynamicType<std::vector<const StringRepresentable*>>>(result);
			}
		case S::RawTransitions:
		{
			auto result = std::vector<const BaseTransition*>{};
			for (auto& tmp : this->definition.transitions)
			{
				result.push_back(&tmp);
			}

			return std::make_unique<ConcreteDynamicType<std::vector<const BaseTransition*>>>(result);
		}
		case S::InitialState:
			return std::make_unique<ConcreteDynamicType<State>>(this->definition.beginState);
		case S::TapeContent:
			return std::make_unique<ConcreteDynamicType<std::string>>(this->head->GetCurrentTapeContent());
		case S::CurrentState:
			return std::make_unique<ConcreteDynamicType<State>>(this->currentState);
		case S::CurrentHeadPositon:
			return std::make_unique<ConcreteDynamicType<size_t>>(this->head->GetAdjustedUIPosition());
		default: 
			return nullptr;
	}
}

const Transition& TuringMachine::GetNextTransition() const
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
