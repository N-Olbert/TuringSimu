#ifndef TM_HEADDIRECTION
#define TM_HEADDIRECTION
#include <string>
namespace ts_common
{
	/*
	 * Enumeration of possible head movement directions.
	 */
	enum HeadDirection
	{
		/*
		 * Move head left.
		 */
		Left,

		/*
		 * Move head right.
		 */
		Right,

		/**
		 * Let head stay at position.
		 */
		Stay
	};

	inline HeadDirection getDirection(std::string line) {
		if (line == "R") {
			return Right;
		} else if (line == "L") {
			return Left;
		} else if (line == "S") {
			return Stay;
		}
		//TODO other handling of bad user input
		throw std::logic_error("Parse-Error: Unknown Headdirection");
	}
}

#endif