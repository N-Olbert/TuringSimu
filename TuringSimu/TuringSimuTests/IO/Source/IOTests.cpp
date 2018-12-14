#include <boost/test/unit_test.hpp>
#include "../../../TuringSimu/IO/Header/DiskIO.hpp"
#include <iostream>
#include "../../../TuringSimu/Common/Header/Utility.hpp"
using namespace ts_common;
using namespace boost::unit_test;
BOOST_AUTO_TEST_CASE(TestGetTuringMachineDefinitionFromFile) {
	//working directory for VisualStudio is the directory in which the .vcxproj lies. So your relative path has
	//to start there

	auto tmd = ts_io::DiskIO::GetTuringMachineDefinitionFromFile("./IO/TestFiles/parseTest1.csv");

	BOOST_REQUIRE(tmd.type == DTM);

	BOOST_REQUIRE(tmd.states.find(State{ "q0" }) != tmd.states.end());
	BOOST_REQUIRE(tmd.states.find(State{ "q1" }) != tmd.states.end());
	BOOST_REQUIRE(tmd.states.find(State{ "qa" }) != tmd.states.end());
	BOOST_REQUIRE(tmd.states.find(State{ "qb" }) != tmd.states.end());
	BOOST_REQUIRE(tmd.states.find(State{ "qe" }) != tmd.states.end());

	BOOST_REQUIRE(tmd.finalStates.find(State{ "qe" }) != tmd.finalStates.end());

	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "q0;0;q0;0;R" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "q0;1;q0;1;R" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "q0;#;q1;#;L" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "q1;0;qa;a;R" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "qa;a;qa;a;R" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "qa;b;qa;b;R" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "qa;#;q1;a;L" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "q1;1;qb;b;R" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "qb;a;qb;a;R" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "qb;b;qb;b;R" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "qb;#;q1;b;L" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "q1;a;q1;a;L" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "q1;b;q1;b;L" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "q1;#;qe;#;S" }));

	BOOST_REQUIRE(tmd.alphabet.find('1') != tmd.alphabet.end());
	BOOST_REQUIRE(tmd.alphabet.find('0') != tmd.alphabet.end());

	BOOST_REQUIRE(tmd.tapeAlphabet.find('1') != tmd.tapeAlphabet.end());
	BOOST_REQUIRE(tmd.tapeAlphabet.find('0') != tmd.tapeAlphabet.end());
	BOOST_REQUIRE(tmd.tapeAlphabet.find('a') != tmd.tapeAlphabet.end());
	BOOST_REQUIRE(tmd.tapeAlphabet.find('#') != tmd.tapeAlphabet.end());
	BOOST_REQUIRE(tmd.tapeAlphabet.find('b') != tmd.tapeAlphabet.end());

	BOOST_REQUIRE(tmd.beginState == State{ "q0" });

	BOOST_REQUIRE(tmd.blank == '#');
}