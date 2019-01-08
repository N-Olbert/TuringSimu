#include <boost/test/unit_test.hpp>
#include "../../../TuringSimu/IO/Header/DiskIO.hpp"
#include "../../../TuringSimuCommon/Common/Header/Utility.hpp"
#include "../../../TuringSimu/IO/Header/DiskOutput.hpp"
using namespace ts_common;
using namespace boost::unit_test;

BOOST_AUTO_TEST_CASE(ParseStateMachine) {
	auto tmd = ts_io::GetTuringMachineDefinitionFromFile("./IO/TestFiles/parseTest4.csv");

	BOOST_REQUIRE(tmd.type == DEA);

	BOOST_REQUIRE(tmd.states.find(State{ "qs" }) != tmd.states.end());
	BOOST_REQUIRE(tmd.states.find(State{ "q0" }) != tmd.states.end());
	BOOST_REQUIRE(tmd.states.find(State{ "q1" }) != tmd.states.end());
	BOOST_REQUIRE(tmd.states.find(State{ "q00" }) != tmd.states.end());
	BOOST_REQUIRE(tmd.states.find(State{ "q11" }) != tmd.states.end());
	BOOST_REQUIRE(tmd.states.find(State{ "qf" }) != tmd.states.end());
	BOOST_REQUIRE(tmd.states.size() == 6);

	BOOST_REQUIRE(tmd.beginState == State{ "qs" });

	BOOST_REQUIRE(tmd.finalStates.find(State{ "q0" }) != tmd.finalStates.end());
	BOOST_REQUIRE(tmd.finalStates.find(State{ "q00" }) != tmd.finalStates.end());
	BOOST_REQUIRE(tmd.finalStates.find(State{ "q1" }) != tmd.finalStates.end());
	BOOST_REQUIRE(tmd.finalStates.find(State{ "q11" }) != tmd.finalStates.end());
	BOOST_REQUIRE(tmd.finalStates.size() == 4);

	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "qs;0;q0;0;R" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "qs;1;q1;1;R" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "q0;0;q00;0;R" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "q0;1;q1;1;R" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "q1;0;q0;0;R" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "q1;1;q11;1;R" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "q00;0;qf;0;R" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "q00;1;q1;1;R" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "q11;0;q0;0;R" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "q11;1;qf;1;R" }));
	BOOST_REQUIRE(tmd.transitions.size() == 10);

	BOOST_REQUIRE(tmd.alphabet.find('1') != tmd.alphabet.end());
	BOOST_REQUIRE(tmd.alphabet.find('0') != tmd.alphabet.end());
	BOOST_REQUIRE(tmd.alphabet.size() == 2);

	BOOST_REQUIRE(tmd.tapeAlphabet.find('1') != tmd.tapeAlphabet.end());
	BOOST_REQUIRE(tmd.tapeAlphabet.find('0') != tmd.tapeAlphabet.end());
	BOOST_REQUIRE(tmd.tapeAlphabet.find('#') != tmd.tapeAlphabet.end());
	BOOST_REQUIRE(tmd.tapeAlphabet.size() == 3);

	BOOST_REQUIRE(tmd.blank == '#');

	ts_io::saveAsCSV("./parseTest4Saved.csv", tmd);
	ts_io::saveAsBinary("./bin4.tmsim", tmd);
}

BOOST_AUTO_TEST_CASE(ParseEpsilon) {
	auto tmd = ts_io::GetTuringMachineDefinitionFromFile("./IO/TestFiles/parseTest5.csv");

	BOOST_REQUIRE(tmd.type == NEA);

	BOOST_REQUIRE(tmd.states.find(State{ "qs" }) != tmd.states.end());
	BOOST_REQUIRE(tmd.states.find(State{ "q0" }) != tmd.states.end());
	BOOST_REQUIRE(tmd.states.find(State{ "q1" }) != tmd.states.end());
	BOOST_REQUIRE(tmd.states.find(State{ "q00" }) != tmd.states.end());
	BOOST_REQUIRE(tmd.states.find(State{ "q11" }) != tmd.states.end());
	BOOST_REQUIRE(tmd.states.find(State{ "qf" }) != tmd.states.end());
	BOOST_REQUIRE(tmd.states.find(State{ "qu" }) != tmd.states.end());
	BOOST_REQUIRE(tmd.states.size() == 7);

	BOOST_REQUIRE(tmd.beginState == State{ "qs" });

	BOOST_REQUIRE(tmd.finalStates.find(State{ "q0" }) != tmd.finalStates.end());
	BOOST_REQUIRE(tmd.finalStates.find(State{ "q00" }) != tmd.finalStates.end());
	BOOST_REQUIRE(tmd.finalStates.find(State{ "q1" }) != tmd.finalStates.end());
	BOOST_REQUIRE(tmd.finalStates.find(State{ "q11" }) != tmd.finalStates.end());
	BOOST_REQUIRE(tmd.finalStates.size() == 4);

	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "qs;0;q0;0;R" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "qs;1;q1;1;R" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "q0;0;q00;0;R" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "q0;1;q1;1;R" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "q1;0;q0;0;R" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "q1;1;q11;1;R" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "q00;0;qf;0;R" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "q00;1;q1;1;R" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "q11;0;q0;0;R" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "q11;1;qf;1;R" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "qu;1;qs;1;S" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "qu;0;qs;0;S" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "qu;#;qs;#;S" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "qs;1;qu;1;S" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "qs;0;qu;0;S" }));
	BOOST_REQUIRE(vectorContains(tmd.transitions, Transition{ "qs;#;qu;#;S" }));
	BOOST_REQUIRE(tmd.transitions.size() == 16);

	BOOST_REQUIRE(tmd.alphabet.find('1') != tmd.alphabet.end());
	BOOST_REQUIRE(tmd.alphabet.find('0') != tmd.alphabet.end());
	BOOST_REQUIRE(tmd.alphabet.size() == 2);

	BOOST_REQUIRE(tmd.tapeAlphabet.find('1') != tmd.tapeAlphabet.end());
	BOOST_REQUIRE(tmd.tapeAlphabet.find('0') != tmd.tapeAlphabet.end());
	BOOST_REQUIRE(tmd.tapeAlphabet.find('#') != tmd.tapeAlphabet.end());
	BOOST_REQUIRE(tmd.tapeAlphabet.size() == 3);

	BOOST_REQUIRE(tmd.blank == '#');

	ts_io::saveAsCSV("./parseTest5Saved.csv", tmd);
	ts_io::saveAsBinary("./bin5.tmsim", tmd);
}
