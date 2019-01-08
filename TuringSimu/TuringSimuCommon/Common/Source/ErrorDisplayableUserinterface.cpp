#include <string>
#include "../Header/ErrorDisplayableUserinterface.hpp"

void ErrorDisplayableUserinterface::NotifyError(ErrorDisplayableUserinterface* toNotify, const std::string& errorMessage)
{
	if (toNotify != nullptr)toNotify->OnError(errorMessage);
}
