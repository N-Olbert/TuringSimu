#include <string>
#include "../Header/Directives.hpp"
#include "../../Common/Header/HeadDirection.hpp"
using namespace ts_io;
using namespace ts_common;
//method to simulate a switch on strings. Throws exception if default case is reached
directive ts_io::switchOnDirectives(std::string &directive) {
	directive = getDirectiveString(directive);

	if (directive == "tape") {
		return tape;
	} else if (directive == "alphabet") {
		return alphabet;
	} else if (directive == "states") {
		return states;
	} else if (directive == "startState") {
		return startState;
	} else if (directive == "blank") {
		return blank;
	} else if (directive == "transitions") {
		return transitions;
	} else throw std::exception("Not a valid directive");
}

std::string ts_io::getDirectiveString(std::string &directive) {
	return directive.substr(1, directive.length() - 2);
}

std::string ts_io::directiveToString(directive directive) {
	switch (directive) {

	case blank:
		return "%blank%\n";
	case alphabet:
		return "%alphabet%\n";
	case states:
		return "%states%\n";
	case tape:
		return "%tape%\n";
	case startState:
		return "%startState%\n";
	case transitions:
		return "%transitions%\n";
		//should never be reached
	default: return "";
	}
}