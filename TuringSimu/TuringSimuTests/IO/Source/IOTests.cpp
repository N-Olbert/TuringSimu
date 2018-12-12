#include <boost/test/unit_test.hpp>
#include "../../../TuringSimu/IO/Header/DiskIO.hpp"
using namespace ts_common;
using namespace boost::unit_test;
BOOST_AUTO_TEST_CASE(TestGetTuringMachineDefinitionFromFile)
{
	ts_io::DiskIO::GetTuringMachineDefinitionFromFile("../Testfiles/parseTest1.csv");
	BOOST_TEST(false);
}