#include <boost/test/unit_test.hpp>
#include "../../../TuringSimu/IO/Header/DiskIO.hpp"
#include "../../../TuringSimu/Common/Header/Utility.hpp"
#include "../../../TuringSimu/IO/Header/DiskOutput.hpp"
using namespace ts_common;
using namespace boost::unit_test;

BOOST_AUTO_TEST_CASE(SaveAsCSVTest) {
	TuringMachineDefinition tmd;
	tmd.states.insert(State{ "q0" });
	tmd.states.insert(State{ "q1" });
	tmd.states.insert(State{ "q2" });
	tmd.states.insert(State{ "q3" });

	tmd.alphabet.insert('a');
	tmd.alphabet.insert('b');

	tmd.finalStates.insert(State{ "q3" });

	tmd.tapeAlphabet.insert('a');
	tmd.tapeAlphabet.insert('b');
	tmd.tapeAlphabet.insert('c');

	tmd.blank = 'c';

	tmd.beginState = State{ "q0" };

	tmd.transitions.emplace_back(Transition{ "q0;a;q1;a;R" });
	tmd.transitions.emplace_back(Transition{ "q1;a;q2;a;R" });
	tmd.transitions.emplace_back(Transition{ "q2;a;q3;a;R" });
	tmd.transitions.emplace_back(Transition{ "q3;b;q0;b;R" });
	tmd.transitions.emplace_back(Transition{ "q0;b;q0;b;R" });

	tmd.type = DTM;

	ts_io::saveAsCSV("./SaveAsCSVTest.csv", tmd);

	auto result = ts_io::GetTuringMachineDefinitionFromFile("./SaveAsCSVTest.csv");

	BOOST_REQUIRE(result.states.find(State{ "q0" }) != result.states.end());
	BOOST_REQUIRE(result.states.find(State{ "q1" }) != result.states.end());
	BOOST_REQUIRE(result.states.find(State{ "q2" }) != result.states.end());
	BOOST_REQUIRE(result.states.find(State{ "q3" }) != result.states.end());
	BOOST_REQUIRE(result.states.size() == 4);

	BOOST_REQUIRE(result.finalStates.find(State{ "q3" }) != result.finalStates.end());
	BOOST_REQUIRE(result.finalStates.size() == 1);

	BOOST_REQUIRE(result.blank == 'c');
	BOOST_REQUIRE(result.beginState == State{ "q0" });

	BOOST_REQUIRE(vectorContains(result.transitions, Transition{ "q0;a;q1;a;R" }));
	BOOST_REQUIRE(vectorContains(result.transitions, Transition{ "q1;a;q2;a;R" }));
	BOOST_REQUIRE(vectorContains(result.transitions, Transition{ "q2;a;q3;a;R" }));
	BOOST_REQUIRE(vectorContains(result.transitions, Transition{ "q3;b;q0;b;R" }));
	BOOST_REQUIRE(vectorContains(result.transitions, Transition{ "q0;b;q0;b;R" }));
	BOOST_REQUIRE(result.transitions.size() == 5);

	BOOST_REQUIRE(result.type == DTM);
}

BOOST_AUTO_TEST_CASE(SaveAsBinaryTest) {
	TuringMachineDefinition tmd;
	tmd.states.insert(State{ "q0" });
	tmd.states.insert(State{ "q1" });
	tmd.states.insert(State{ "q2" });
	tmd.states.insert(State{ "q3" });

	tmd.alphabet.insert('a');
	tmd.alphabet.insert('b');

	tmd.finalStates.insert(State{ "q3" });

	tmd.tapeAlphabet.insert('a');
	tmd.tapeAlphabet.insert('b');
	tmd.tapeAlphabet.insert('c');

	tmd.blank = 'c';

	tmd.beginState = State{ "q0" };

	tmd.transitions.emplace_back(Transition{ "q0;a;q1;a;R" });
	tmd.transitions.emplace_back(Transition{ "q1;a;q2;a;R" });
	tmd.transitions.emplace_back(Transition{ "q2;a;q3;a;R" });
	tmd.transitions.emplace_back(Transition{ "q3;b;q0;b;R" });
	tmd.transitions.emplace_back(Transition{ "q0;b;q0;b;R" });

	tmd.type = DTM;

	ts_io::saveAsBinary("./SaveAsBinaryTest.tmsim", tmd);

	auto result = ts_io::GetTuringMachineDefinitionFromFile("./SaveAsBinaryTest.tmsim");

	BOOST_REQUIRE(result.states.find(State{ "q0" }) != result.states.end());
	BOOST_REQUIRE(result.states.find(State{ "q1" }) != result.states.end());
	BOOST_REQUIRE(result.states.find(State{ "q2" }) != result.states.end());
	BOOST_REQUIRE(result.states.find(State{ "q3" }) != result.states.end());
	BOOST_REQUIRE(result.states.size() == 4);

	BOOST_REQUIRE(result.finalStates.find(State{ "q3" }) != result.finalStates.end());
	BOOST_REQUIRE(result.finalStates.size() == 1);

	BOOST_REQUIRE(result.blank == 'c');
	BOOST_REQUIRE(result.beginState == State{ "q0" });

	BOOST_REQUIRE(vectorContains(result.transitions, Transition{ "q0;a;q1;a;R" }));
	BOOST_REQUIRE(vectorContains(result.transitions, Transition{ "q1;a;q2;a;R" }));
	BOOST_REQUIRE(vectorContains(result.transitions, Transition{ "q2;a;q3;a;R" }));
	BOOST_REQUIRE(vectorContains(result.transitions, Transition{ "q3;b;q0;b;R" }));
	BOOST_REQUIRE(vectorContains(result.transitions, Transition{ "q0;b;q0;b;R" }));
	BOOST_REQUIRE(result.transitions.size() == 5);

	BOOST_REQUIRE(result.type == DTM);
}