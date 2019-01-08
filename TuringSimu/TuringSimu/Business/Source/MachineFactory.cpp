#include "../Header/TuringMachine.hpp"
#include "../Header/MachineFactory.hpp"
#include "../../IO/Header/DiskIO.hpp"
using namespace ts_business;
using namespace ts_common;

std::unique_ptr<AbstractMachine> MachineFactory::CreateMachineFromFile(MachineType requestedMachineType, const std::string& path)
{
	return CreateMachineFromFile(requestedMachineType, path, nullptr);
}

std::unique_ptr<AbstractMachine> MachineFactory::CreateMachineFromFile(MachineType requestedMachineType, const std::string& path,
	AbstractMachineUserinterface* observingUI)
{
	switch (requestedMachineType)
	{
		case DTM:
		case NTM:
		case DEA:
		case NEA:
			{
				auto definition = ts_io::GetTuringMachineDefinitionFromFile(path);
				if (IsValidTuringMachineDefinition(definition))
				{
					auto result = std::unique_ptr<TuringMachine>(new TuringMachine{ observingUI, definition });
					return result;
				}
			}
			break;
	}

	return std::unique_ptr<AbstractMachine>(nullptr);
}

bool MachineFactory::IsValidTuringMachineDefinition(TuringMachineDefinition& definition)
{
	if (definition.error)
	{
		return false;
	}

	//checking that every member of final states was specified as a state
	for (const auto& element : definition.finalStates)
	{
		if (definition.states.find(element) == definition.states.end())
		{
			return false;
		}
	}

	//Because alphabet is added to tapeAlphabet after parsing, tape must include every 
	//character of the input alphabet.

	//Checking that the blank symbol isn't a member of the input alphabet
	if (definition.alphabet.find(definition.blank) != definition.alphabet.end())
	{
		return false;
	}

	//Checking that the blanksymbol is a member of the tapeAlphabet
	if (definition.tapeAlphabet.find(definition.blank) == definition.tapeAlphabet.end())
	{
		return false;
	}

	//the beginState must be a member of states
	if (definition.states.find(definition.beginState) == definition.states.end())
	{
		return false;
	}

	for (auto& element : definition.transitions)
	{
		//checking that the currentState of the transition is actually a defined state
		if (definition.states.find(element.GetCurrentState()) == definition.states.end())
		{
			return false;
		}
		//checking that the currentChar of the transition can actually appear on the tape
		if (definition.tapeAlphabet.find(element.GetCurrentChar()) == definition.tapeAlphabet.end())
		{
			return false;
		}
		//checking that the nextState of the transition was actually defined
		if (definition.states.find(element.GetNextState()) == definition.states.end())
		{
			return false;
		}
		//checking that the character to write was properly defined
		if (definition.tapeAlphabet.find(element.GetToWrite()) == definition.tapeAlphabet.end())
		{
			return false;
		}

		//HeadDirection cannot be wrong since that throws an exception during parsing which
		//would reflect in the previously checked error bit

		//checking that every pair of currentState and currentChar is unique if type is 
		//deterministic
		if (definition.type == DEA || definition.type == DTM)
		{
			if (Transition::countOccurrences(element, definition.transitions) > 1)
			{
				return false;
			}
		}
	}

	//TODO
	//AbstractMachineUserinterface::NotifyInvalidMachineDefinition(observingUI, std::string);
	return true;
}
