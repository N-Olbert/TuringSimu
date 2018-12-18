#pragma once
#ifndef TS_DIRECTIVES
#define TS_DIRECTIVES
#include <string>
namespace ts_io {
	enum directive { states, tape, alphabet, startState, finalState, blank, transitions };
	directive switchOnDirectives(std::string &directive);
	std::string getDirectiveString(std::string &directive);
	std::string directiveToString(directive directive);
}
#endif