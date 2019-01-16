#ifndef TM_STRINGREPRESENTABLE
#define TM_STRINGREPRESENTABLE
#include <string>
namespace ts_common
{
	/*
	 * \brief An interface for all classes which can be displayed as string.
	 */
	class StringRepresentable
	{
		public:
			virtual ~StringRepresentable() = default;

			/*
			 * \brief Gets the string representation of the current instance.
			 * \returns The string which represents the current instance.
			 */
			virtual std::string ToString() const noexcept { return std::string{}; };
	};
}
#endif // TM_STRINGREPRESENTABLE
