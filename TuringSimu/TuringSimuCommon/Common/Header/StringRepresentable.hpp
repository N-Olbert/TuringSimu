#ifndef TM_STRINGREPRESENTABLE
#define TM_STRINGREPRESENTABLE
#include <string>
class StringRepresentable
{
	public:
		virtual ~StringRepresentable() = default;
		virtual std::string ToString() const noexcept { return std::string{}; };
};
#endif // TM_STRINGREPRESENTABLE
