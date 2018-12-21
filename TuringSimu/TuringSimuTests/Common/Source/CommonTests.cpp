#include <boost/test/unit_test.hpp>
#include "../../../TuringSimu/Business/Header/TuringMachine.hpp"
using namespace ts_common;
using namespace boost::unit_test;

BOOST_AUTO_TEST_CASE(BasicHashSetTest) {
	auto def = std::make_unique<TuringMachineDefinition>();
	def->states.insert(State{ "j" });
	def->states.insert(State{ "n" });
	def->states.insert(State{ "j" });
	BOOST_TEST(def->states.size() == 2);
}

BOOST_AUTO_TEST_CASE(TransitionConstructorFromCSVLineTest) {
	auto t = Transition("q0;0;q0;0;R");
	BOOST_REQUIRE(t.GetCurrentState() == State{ "q0" });
	BOOST_REQUIRE(t.GetCurrentChar() == '0');
	BOOST_REQUIRE(t.GetHeadDirection() == Right);
	BOOST_REQUIRE(t.GetNextState() == State{ "q0" });
	BOOST_REQUIRE(t.GetToWrite() == '0');
}