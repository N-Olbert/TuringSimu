#ifndef TM_TURINGMACHINETAPEHEADER
#define TM_TURINGMACHINETAPEHEADER
#include <vector>
#include "../../../TuringSimuCommon/Common/Header/HeadDirection.hpp"

using namespace ts_common;
namespace ts_business
{
	/**
	 * \brief A class which simulates the behaviour of the tape header of a turing machine
	 */
	class TuringMachineTapeHeader
	{
		private:
			/**
			 * \brief Tape content in positive direction (0 - 99999)
			 */
			std::vector<char> inputPositiveDirection;

			/**
			 * \brief Tape content in negative direction (-99999 - -1)
			 */
			std::vector<char> inputNegativeDirection;

			/**
			 * \brief The blank symbol of the tape.
			 */
			char blankSymbol;

			/**
			 * \brief The raw position on the tape. Consider calling GetAdjustedPosition in combination with
			 * GetVector for tape access.
			 */
			int32_t rawPosition;

		public:
			TuringMachineTapeHeader(char blankSymbol) noexcept : blankSymbol(blankSymbol), rawPosition(0) {};

			/**
			 * \brief Handles the given move action.
			 */
			void Move(HeadDirection direction);
			
			
			/**
			 * \brief Returns the current char
			 * \return The current char
			 */
			char GetChar();

			/**
			 * \brief Writes the given char at the current position.
			 * \param toWrite The char to write.
			 */
			void WriteChar(char toWrite);

			/**
			 * \brief Resets the tape an places the given content on this.
			 * After this action the head points to the first (= 0th) element
			 * \param input The content to initalize the tape with.
			 */
			void InitWith(const std::string& input);

			/**
			 * \brief Gets the currently relevant content of the tape. Note: some blanks may be included. 
			 * \return The currently relevant content of the tape.
			 */
			std::string GetCurrentTapeContent();

			/**
			 * \brief Gets the currently relevant vector for the index which has been determined by GetAdjustedPosition.
			 * \return The currently relevant vector.
			 */
		    std::vector<char>& GetVector() noexcept;

			/**
			 * \brief Converts the raw index into an unsigned one for vector access using GetVector().
			 * \return The determined index.
			 */
			size_t GetAdjustedPosition() const noexcept;
			
			/**
			 * \brief Converts the raw index into an unsigned one which corresponds to the postion of the string 
			 * which is returned by GetCurrentTapeContent()
			 * \return The determined index.
			 */
			size_t GetAdjustedUIPosition() const noexcept;
	};
}
#endif // TM_TURINGMACHINETAPEHEADER
