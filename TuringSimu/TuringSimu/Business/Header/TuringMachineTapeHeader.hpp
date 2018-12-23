#ifndef TM_TURINGMACHINETAPEHEADER
#define TM_TURINGMACHINETAPEHEADER
#include <vector>
#include <deque> 
#include "../../Common/Header/HeadDirection.hpp"

using namespace ts_common;
namespace ts_business
{
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
			void InitWith(std::string& input);
		    std::vector<char>& GetVector() noexcept;
			size_t GetAdjustedPosition() const noexcept;
	};
}
#endif // TM_TURINGMACHINETAPEHEADER
