#ifndef TM_CONSOLE
#define TM_CONSOLE
#include <string>
#include "../../../TuringSimuCommon/UI/Header/Result.hpp"
#include <mutex>
#include <iterator>
#include "../../../TuringSimuCommon/Common/Header/StringRepresentable.hpp"

using namespace ts_common;
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
			static std::mutex ConsoleMutex;
		public:
			static void Print(const std::string& toPrint);
			static void PrintDelayed(const std::string& toPrint);
			static void Print(char toPrint);
			static void PrintDelayed(char toPrint);
			static void PrintDelayed(uint64_t toPrint);
			static void PrintLine(const std::string& toPrint);
			static void PrintLineDelayed(const std::string & toPrint);
			static void PrintLineBlueUnderlinedDelayed(const std::string & toPrint);
			static void PrintLineRedUnderlinedDelayed(const std::string & toPrint);
			static void PrintLine(const StringRepresentable& toPrint);
			static void PrintLine(char toPrint);
			static void NewLine();
			static void NewLineDelayed();
			static void Flush();
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
			template<class CollectionType, class ValueType> static void PrintEnumerable(const CollectionType iterable)
			{
				for (const ValueType& elem : iterable)
				{
					PrintDelayed(elem);
					NewLineDelayed();
				}

				Flush();
			};

			template<class CollectionType> static void PrintEnumerable(const CollectionType iterable)
			{
				for (const StringRepresentable& elem : iterable)
				{
					PrintDelayed(elem.ToString());
					NewLineDelayed();
				}

				Flush();
			}

			template<class PtrCollection> static void PrintEnumerablePointer(PtrCollection iterable)
			{
				for (const StringRepresentable* elem : iterable)
				{
					PrintDelayed(elem->ToString());
					NewLineDelayed();
				}

				Flush();
			}
	};
}
#endif // TM_CONSOLE
