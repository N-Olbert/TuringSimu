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
	for (const auto &element : definition.finalStates) {
		if (definition.states.find(element) == definition.states.end()) {
			return false;
		}
	}
	//checking if every member of the alphabet is allowed on the tape
	for (const auto &element : definition.alphabet) {
		if (definition.tapeAlphabet.find(element) == definition.tapeAlphabet.end()) {
			return false;
		}
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
		//TODO EPSILON
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

		//checking that every pair of currentState and currentChar is unique if type is deter-
		//ministic
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
