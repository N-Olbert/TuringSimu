#ifndef TM_CONSOLE
#define TM_CONSOLE
#include <string>
#include "../../../TuringSimuUICommon/UI/Header/Result.hpp"
#include <mutex>

namespace ts_ui
{
	/**
	 * \brief A thread safe wrapper around methods for CLI interaction.
	 */
	class Console
	{
		private:
			static const std::string ESC;
			static const std::string CSI;
			static const std::string AnsiLineUp;
			static const std::string AnsiClearLine;
			static const std::string CarriageReturn;
			static std::mutex ConsoleMutex;
		public:
			static void Print(const std::string& toPrint);
			static void PrintDelayed(const std::string& toPrint);
			static void Print(char toPrint);
			static void PrintDelayed(char toPrint);
			static void PrintLine(const std::string& toPrint);
			static void NewLine();
			static void LineBack();
			static void ClearLine();
			static void ClearScreen();
			static void HideCursor();
			static void ShowCursor();
			static void AwaitEnter();
			static Result<int16_t> GetIntInput();
			static std::string GetStringInput();
			static char GetCharInput();
			template<class T> static T GetInput();
	};
}
#endif // TM_CONSOLE
