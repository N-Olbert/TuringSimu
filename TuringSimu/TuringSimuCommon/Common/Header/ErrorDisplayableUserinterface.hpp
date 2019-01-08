#ifndef TM_ERRORDISPLAYABLEUSERINTERFACE
#define TM_ERRORDISPLAYABLEUSERINTERFACE
#include <string>

class ErrorDisplayableUserinterface
{
	public:
		virtual ~ErrorDisplayableUserinterface() = default;
		virtual void OnError(const std::string& errorMessage) = 0;
		static void NotifyError(ErrorDisplayableUserinterface* toNotify, const std::string& errorMessage);
};
#endif // TM_ERRORDISPLAYABLEUSERINTERFACE
