//This is the only file where boost/test/included/unit_test.hpp should be included
#include <boost/test/included/unit_test.hpp>

boost::unit_test::test_suite* init_unit_test_suite( int /*argc*/, char* /*argv*/[] )
{
	//Dummy method. In theory you could define own test cases here
	return 0;
}
