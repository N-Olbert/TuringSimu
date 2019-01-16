#include <string>
#include "../Header/ErrorDisplayableUserinterface.hpp"

using namespace ts_common;
void ErrorDisplayableUserinterface::NotifyError(ErrorDisplayableUserinterface* toNotify, const std::string& errorMessage)
{
	if (toNotify != nullptr)toNotify->OnError(errorMessage);
}
