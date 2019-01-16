#ifndef TM_ERRORDISPLAYABLEUSERINTERFACE
#define TM_ERRORDISPLAYABLEUSERINTERFACE
#include <string>
namespace ts_common
{
	/**
	 * \brief Interface for any UI which is able to display error messages.
	 */
	class ErrorDisplayableUserinterface
	{
		public:
			virtual ~ErrorDisplayableUserinterface() = default;

			/**
			 * \brief Called after an error occured.
			 * \param errorMessage The error message to display.
			 */
			virtual void OnError(const std::string& errorMessage) = 0;

			/**
			 * \brief Notfies the given EDU about an occured error.
			 * \param toNotify The EDU to notify.
			 * \param errorMessage The message of the occured error.
			 */
			static void NotifyError(ErrorDisplayableUserinterface* toNotify, const std::string& errorMessage);
	};
}
#endif // TM_ERRORDISPLAYABLEUSERINTERFACE
