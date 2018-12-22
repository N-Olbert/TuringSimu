#pragma once
#ifndef TS_DIRECTIVES
#define TS_DIRECTIVES
#include <string>
namespace ts_io {
	enum directive { states, tape, alphabet, startState, finalState, blank, transitions };


	/**
	 * \brief Since you cannot use a switch-case statement on strings, this method exists
	 * \param directive The string to switch on
	 * \return The enum corresponding to the string
	 * \throws std::logic_error if the string doesnt represent a directive
	 */
	directive switchOnDirectives(std::string &directive);


	/**
	 * \brief Removes the '%' at both ends of the string
	 * \param directive The string from which the '%' should be removed
	 * \return The string without its first and last character
	 */
	std::string getDirectiveString(std::string &directive);


	/**
	 * \brief To save a TMD we need to be able to convert a directive enum to its corresponding string
	 * \param directive The enum to stringify
	 * \return The string representation of the enum
	 */
	std::string directiveToString(directive directive);
}
#endif