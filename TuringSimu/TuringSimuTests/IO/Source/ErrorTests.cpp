#include <boost/test/unit_test.hpp>
#include "../../../TuringSimu/IO/Header/DiskIO.hpp"
#include "../../../TuringSimu/IO/Header/DiskOutput.hpp"
using namespace ts_common;
using namespace boost::unit_test;

BOOST_AUTO_TEST_CASE(FileNotFound) {
	const auto tmd = ts_io::GetTuringMachineDefinitionFromFile("aBSPath.csv");
	BOOST_REQUIRE(tmd.error);
}

BOOST_AUTO_TEST_CASE(UnsupportedFileExtension) {
	const auto tmd = ts_io::GetTuringMachineDefinitionFromFile("./../TuringSimu/IO/FormatDefinitions/BinaryFormatV0.txt");
	BOOST_REQUIRE(tmd.error);
}

BOOST_AUTO_TEST_CASE(InvalidDirective) {
	const auto tmd = ts_io::GetTuringMachineDefinitionFromFile("./IO/TestFiles/parseFail2.csv");
	BOOST_REQUIRE(tmd.error);
}

BOOST_AUTO_TEST_CASE(InvalidHeadDirection) {
	const auto tmd = ts_io::GetTuringMachineDefinitionFromFile("./IO/TestFiles/parseFail3.csv");
	BOOST_REQUIRE(tmd.error);
}

BOOST_AUTO_TEST_CASE(InvalidTMType) {
	const auto tmd = ts_io::GetTuringMachineDefinitionFromFile("./IO/TestFiles/parseFail1.csv");
	BOOST_REQUIRE(tmd.error);
}

BOOST_AUTO_TEST_CASE(EpsilonOutOfPlace)
{
	const auto tmd = ts_io::GetTuringMachineDefinitionFromFile("./IO/TestFiles/parseFail4.csv");
	BOOST_REQUIRE(tmd.error);
}

BOOST_AUTO_TEST_CASE(TapeDirectiveForStateMachine)
{
	const auto tmd = ts_io::GetTuringMachineDefinitionFromFile("./IO/TestFiles/parseFail5.csv");
	BOOST_REQUIRE(tmd.error);
}