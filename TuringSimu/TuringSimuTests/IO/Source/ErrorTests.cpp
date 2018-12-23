#include <boost/test/unit_test.hpp>
#include "../../../TuringSimu/IO/Header/DiskIO.hpp"
#include <iostream>
#include "../../../TuringSimu/Common/Header/Utility.hpp"
#include "../../../TuringSimu/IO/Header/DiskOutput.hpp"
using namespace ts_common;
using namespace boost::unit_test;

BOOST_AUTO_TEST_CASE(FileNotFound) {
	auto tmd = ts_io::GetTuringMachineDefinitionFromFile("aBSPath.csv");
	BOOST_REQUIRE(tmd.error);
}

BOOST_AUTO_TEST_CASE(UnsupportedFileExtension) {
	auto tmd = ts_io::GetTuringMachineDefinitionFromFile("./../TuringSimu/IO/FormatDefinitions/BinaryFormatV0.txt");
	BOOST_REQUIRE(tmd.error);
}

BOOST_AUTO_TEST_CASE(InvalidDirective) {
	auto tmd = ts_io::GetTuringMachineDefinitionFromFile("./IO/TestFiles/parseFail2.csv");
	BOOST_REQUIRE(tmd.error);
}

BOOST_AUTO_TEST_CASE(InvalidHeadDirection) {
	auto tmd = ts_io::GetTuringMachineDefinitionFromFile("./IO/TestFiles/parseFail3.csv");
	BOOST_REQUIRE(tmd.error);
}

BOOST_AUTO_TEST_CASE(InvalidTMType) {
	auto tmd = ts_io::GetTuringMachineDefinitionFromFile("./IO/TestFiles/parseFail1.csv");
	BOOST_REQUIRE(tmd.error);
}