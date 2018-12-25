#include "../Header/TuringMachine.hpp"
#include "../Header/MachineFactory.hpp"
#include "../../IO/Header/DiskIO.hpp"
using namespace ts_business;
using namespace ts_common;

std::unique_ptr<AbstractMachine> MachineFactory::CreateMachineFromFile(std::string& path,
	AbstractMachineUserinterface* observingUI) {
	auto definition = ts_io::GetTuringMachineDefinitionFromFile(path);
	if (IsValidMachineDefinition(definition)) {
		auto result = std::unique_ptr<AbstractMachine>(new TuringMachine{ observingUI, definition });
		return result;
	}

	return std::unique_ptr<AbstractMachine>(nullptr);
}

bool MachineFactory::IsValidMachineDefinition(TuringMachineDefinition & definition) {
	if (definition.error) {
		return false;
	}
	//no need to check finalStates and States. There is no way for States to be wrong and 
	//final states are also defined during the %states% directive and thus are automatically
	//added to States. So you cant have a State that is included in finalStates but not in
	//states

	//Because alphabet is added to tape in the end, tape must include every character of
	//the input alphabet.

	//The blank symbol can only be a member of the tapeAlphabet
	if (definition.alphabet.find(definition.blank) != definition.alphabet.end()) {
		return false;
	}

	//the beginState must be a member of states
	if (definition.states.find(definition.beginState) == definition.states.end()) {
		return false;
	}

	for (auto & element : definition.transitions) {
		//checking that the currentState of the transition is actually a defined state
		if (definition.states.find(element.GetCurrentState()) == definition.states.end()) {
			return false;
		}
		//checking that the currentChar of the transition can actually appear on the tape
		if (definition.tapeAlphabet.find(element.GetCurrentChar()) == definition.tapeAlphabet.end()) {
			return false;
		}
		//checking that the nextState of the transition was actually defined
		if (definition.states.find(element.GetNextState()) == definition.states.end()) {
			return false;
		}
		//checking that the character to write was properly defined
		if (definition.tapeAlphabet.find(element.GetToWrite()) == definition.tapeAlphabet.end()) {
			return false;
		}

		//HeadDirection cannot be wrong since that throws an exception during parsing which
		//would reflect in the previously checked error bit

		//checking that every pair of currentState and currentChar is unique if type is 
		//deterministic
		if (definition.type == DEA || definition.type == DTM) {
			if (Transition::countOccurrences(element, definition.transitions) > 1) {
				return false;
			}
		}
	}

	//TODO
	//AbstractMachineUserinterface::NotifyInvalidMachineDefinition(observingUI, std::string);
	return true;
}
