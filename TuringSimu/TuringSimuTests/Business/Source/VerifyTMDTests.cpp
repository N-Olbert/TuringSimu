#include <boost/test/unit_test.hpp>
#include "../../../TuringSimu/Business/Header/MachineFactory.hpp"
#include "../../Common/Header/DummyMachineUserInterface.hpp"
using namespace ts_common;
using namespace ts_business;
using namespace boost::unit_test;

BOOST_AUTO_TEST_CASE(NonDeterministicBehaviourInDTM)
{
	auto path = std::string{ "./IO/TestFiles/VerifyTMDTest1.csv" };
	auto ui = std::make_unique<DummyMachineUserInterface>();
	auto machine = MachineFactory::CreateMachineFromFile(DTM, path, ui.get());
	BOOST_REQUIRE(machine == nullptr);
}

BOOST_AUTO_TEST_CASE(BeginStateNotInStates) {
	auto path = std::string{ "./IO/TestFiles/VerifyTMDTest2.csv" };
	auto ui = std::make_unique<DummyMachineUserInterface>();
	auto machine = MachineFactory::CreateMachineFromFile(DTM, path, ui.get());
	BOOST_REQUIRE(machine == nullptr);
}

BOOST_AUTO_TEST_CASE(BlankInAlphabet) {
	auto path = std::string{ "./IO/TestFiles/VerifyTMDTest3.csv" };
	auto ui = std::make_unique<DummyMachineUserInterface>();
	auto machine = MachineFactory::CreateMachineFromFile(DTM, path, ui.get());
	BOOST_REQUIRE(machine == nullptr);
}

BOOST_AUTO_TEST_CASE(UndefinedCurrentState) {
	auto path = std::string{ "./IO/TestFiles/VerifyTMDTest4.csv" };
	auto ui = std::make_unique<DummyMachineUserInterface>();
	auto machine = MachineFactory::CreateMachineFromFile(DTM, path, ui.get());
	BOOST_REQUIRE(machine == nullptr);
}

BOOST_AUTO_TEST_CASE(UndefinedNextState) {
	auto path = std::string{ "./IO/TestFiles/VerifyTMDTest5.csv" };
	auto ui = std::make_unique<DummyMachineUserInterface>();
	auto machine = MachineFactory::CreateMachineFromFile(DTM, path, ui.get());
	BOOST_REQUIRE(machine == nullptr);
}

BOOST_AUTO_TEST_CASE(UndefinedCurrentChar) {
	auto path = std::string{ "./IO/TestFiles/VerifyTMDTest6.csv" };
	auto ui = std::make_unique<DummyMachineUserInterface>();
	auto machine = MachineFactory::CreateMachineFromFile(DTM, path, ui.get());
	BOOST_REQUIRE(machine == nullptr);
}

BOOST_AUTO_TEST_CASE(UndefinedToWrite) {
	auto path = std::string{ "./IO/TestFiles/VerifyTMDTest7.csv" };
	auto ui = std::make_unique<DummyMachineUserInterface>();
	auto machine = MachineFactory::CreateMachineFromFile(DTM, path, ui.get());
	BOOST_REQUIRE(machine == nullptr);
}

BOOST_AUTO_TEST_CASE(UndefinedFinalState) {
	auto path = std::string{ "./IO/TestFiles/VerifyTMDTest8.csv" };
	auto ui = std::make_unique<DummyMachineUserInterface>();
	auto machine = MachineFactory::CreateMachineFromFile(DTM, path, ui.get());
	BOOST_REQUIRE(machine == nullptr);
}

BOOST_AUTO_TEST_CASE(BlankNotOnTape) {
	auto path = std::string{ "./IO/TestFiles/VerifyTMDTest9.csv" };
	auto ui = std::make_unique<DummyMachineUserInterface>();
	auto machine = MachineFactory::CreateMachineFromFile(DTM, path, ui.get());
	BOOST_REQUIRE(machine == nullptr);
}