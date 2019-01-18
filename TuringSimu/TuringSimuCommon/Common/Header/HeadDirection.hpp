#ifndef TM_HEADDIRECTION
#define TM_HEADDIRECTION
#include <string>
#include <stdexcept>
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
		 * Let head stay at rawPosition.
		 */
		Stay
	};


	/**
	 * \brief Returns the appropriate enum for the given String
	 * \param line the glorified char (string of length 1) which we want as enum
	 * \return the HeadDirection corresponding to this string
	 */
	inline HeadDirection getDirection(std::string &line) 
	{
		if (line == "R") {
			return Right;
		} else if (line == "L") {
			return Left;
		} else if (line == "S") {
			return Stay;
		}
		throw std::logic_error("Parse-Error: Unknown HeadDirection");
	}

	/**
	 * \brief Returns the appropriate string for the given enum
	 * \param direction The HeadDirection to convert
	 * \return string corresponding to the HeadDirection
	 */
	inline std::string DirectionAsString(HeadDirection direction)
	{
		switch (direction)
		{
			case Left: return "L";
			case Right: return "R";
			case Stay: return "S";
		}

		throw std::logic_error("Parse-Error: Unknown HeadDirection");
	}
}

#endif
