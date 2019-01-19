#include "../Header/TuringMachine.hpp"
#include "../Header/NonDeterministicTuringMachine.hpp"
#include "../Header/MachineFactory.hpp"
#include "../../IO/Header/DiskIO.hpp"
#include <iostream>
using namespace ts_business;
using namespace ts_common;

std::unique_ptr<AbstractMachine> MachineFactory::CreateMachineFromFile(const std::string& path)
{
	return CreateMachineFromFile(path, nullptr);
}

std::unique_ptr<AbstractMachine> MachineFactory::CreateMachineFromFile(const std::string& path,
	AbstractMachineUserinterface* observingUI)
{
	auto definition = ts_io::GetTuringMachineDefinitionFromFile(path);
	switch (definition.type)
	{
		case NTM:
		case NEA:
		case DTM:
		case DEA:
		{
			//DEA and NEA are currently converted to a TM during read in!
			std::string error;
			if (IsValidTuringMachineDefinition(definition, error))
			{
				switch (definition.type)
				{
					case NTM:
					case NEA:
						return std::make_unique<NonDeterministicTuringMachine>(NonDeterministicTuringMachine{observingUI, definition});;
					case DTM:
					case DEA:
						return std::make_unique<TuringMachine>(TuringMachine{observingUI, definition});
				}
			}
			else
			{
				if (observingUI != nullptr) 
				{
					observingUI->OnError(error);
				}
				else
				{
					//Try to show it somewhere
					std::cout << error;
				}
			}
		}
			break;
	}

	return std::unique_ptr<AbstractMachine>(nullptr);
}

bool MachineFactory::IsValidTuringMachineDefinition(TuringMachineDefinition& definition, std::string& errorMessage)
{
	//TODO: Localize (but these are error messages, so it is ok for now)
	//checking that every member of final states was specified as a state
	for (const auto& element : definition.finalStates)
	{
		if (definition.states.find(element) == definition.states.end())
		{
			errorMessage = "ERROR: At least one final state hasn't been specified as state before.";
			return false;
		}
	}

	//Because alphabet is added to tapeAlphabet after parsing, tape must include every 
	//character of the input alphabet.

	//Checking that the blank symbol isn't a member of the input alphabet
	if (definition.alphabet.find(definition.blank) != definition.alphabet.end())
	{
		errorMessage = "ERROR: Blank symbol is part of the input alphabet.";
		return false;
	}

	//Checking that the blanksymbol is a member of the tapeAlphabet
	if (definition.tapeAlphabet.find(definition.blank) == definition.tapeAlphabet.end())
	{
		errorMessage = "ERROR: Blank symbol isn't part of the tape alphabet.";
		return false;
	}

	//the beginState must be a member of states
	if (definition.states.find(definition.beginState) == definition.states.end())
	{
		errorMessage = "ERROR: Begin state is no valid state.";
		return false;
	}

	for (auto& element : definition.transitions)
	{
		//checking that the currentState of the transition is actually a defined state
		if (definition.states.find(element.GetCurrentState()) == definition.states.end())
		{
			errorMessage = "ERROR: At least one transition references an undefined state.";
			return false;
		}
		//checking that the currentChar of the transition can actually appear on the tape
		if (definition.tapeAlphabet.find(element.GetCurrentChar()) == definition.tapeAlphabet.end())
		{
			errorMessage = "ERROR: At least one transition references an undefined char.";
			return false;
		}
		//checking that the nextState of the transition was actually defined
		if (definition.states.find(element.GetNextState()) == definition.states.end())
		{
			errorMessage = "ERROR: At least one transition references an undefined state.";
			return false;
		}
		//checking that the character to write was properly defined
		if (definition.tapeAlphabet.find(element.GetToWrite()) == definition.tapeAlphabet.end())
		{
			errorMessage = "ERROR: At least one transition references an undefined char.";
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
				errorMessage = "ERROR: Non determinism within deterministic machine detected.";
				return false;
			}
		}
	}

	if (definition.error)
	{
		errorMessage = "ERROR: An unknown error occured during file parsing.";
		return false;
	}

	return true;
}
