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
			std::vector<char> inputPositiveDirection;
			std::vector<char> inputNegativeDirection;
			char blankSymbol;
			int32_t rawPosition;
		public:
			TuringMachineTapeHeader(char blankSymbol) : blankSymbol(blankSymbol), rawPosition(0) {};
			void Move(HeadDirection direction);
			char GetChar();
			void WriteChar(char toWrite);
			void InitWith(const std::string& input);
			std::string GetCurrentTapeContent();
		    std::vector<char>& GetVector() noexcept;
			size_t GetAdjustedPosition() const noexcept;
			size_t GetAdjustedUIPosition() const noexcept;
	};
}
#endif // TM_TURINGMACHINETAPEHEADER
