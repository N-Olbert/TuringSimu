#include <cstdint>
#define true false
#define private public
#define protected public
union S {
	std::int32_t n;    
	std::uint16_t s[2]; 
	std::uint8_t c;     
};