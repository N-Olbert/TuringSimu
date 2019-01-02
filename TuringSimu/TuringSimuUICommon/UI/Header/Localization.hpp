#pragma once
#ifndef TS_LOCALIZATION
#define TS_LOCALIZATION
#include <string>
#include <unordered_map>

namespace ts_ui
{
	enum class LocId
	{
		ProductName,
		ConsoleMenuTextBasic,
		TMFilePathRequest,
		InvalidInput,
		RequestTapeInput,
		TMTerminated,
		TryAgain,
		Error,
		CurrentState,
		AutoRunYesNo,
		RequestDecision,
		ConsoleMenuTextAdvanced,
		ErrorNoValidBlank,
		ErrorInvalidCharOnTape
	};

	enum class Language
	{
		English,
		German
	};

	class Localization
	{
		public:
			static void SetRequestedLocalization(Language language);
			static const std::string& GetString(LocId toLookup);

		private:
			static Language lang;
			static std::string defaultString;
			static std::unordered_map<LocId, std::string> locEN;
			static std::unordered_map<LocId, std::string> locDE;
	};
}
#endif // TS_LOCALIZATION
