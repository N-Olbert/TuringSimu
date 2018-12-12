#include <boost/test/unit_test.hpp>
#include "../../../TuringSimu/Business/Header/TuringMachine.hpp"
using namespace ts_common;
using namespace boost::unit_test;

BOOST_AUTO_TEST_CASE(BasicHashSetTest)
{
	auto def = std::make_unique<TuringMachineDefinition>();
	def->states.insert(State{"j"});
	def->states.insert(State{"n"});
	def->states.insert(State{"j"});
	BOOST_TEST(def->states.size() == 2);
}