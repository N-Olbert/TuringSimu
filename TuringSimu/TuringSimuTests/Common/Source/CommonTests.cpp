#define BOOST_TEST_MODULE CommonTests
#include <boost/test/included/unit_test.hpp>
#include "../../../TuringSimu/Business/Header/TuringMachine.hpp"
using namespace ts_common;

BOOST_AUTO_TEST_CASE(BasicHashSetTest)
{
	auto def = std::make_unique<TuringMachineDefiniton>();
	def->states.insert(State{"j"});
	def->states.insert(State{"n"});
	def->states.insert(State{"j"});
	BOOST_TEST(def->states.size() == 2);
}