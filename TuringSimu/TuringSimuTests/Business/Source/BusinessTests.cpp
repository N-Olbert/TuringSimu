#include <boost/test/unit_test.hpp>
#include "../../../TuringSimu/Business/Header/TuringMachine.hpp"
#include "../../../TuringSimu/Business/Header/MachineFactory.hpp"
#include "../../Common/Header/DummyMachineUserInterface.hpp"
#include "../../../TuringSimu/Common/Header/Transition.hpp"
using namespace ts_common;
using namespace ts_business;
using namespace boost::unit_test;

BOOST_AUTO_TEST_CASE(TestPalindromGeratorTuringMachine) {
	auto dummy = Transition::Empty;
	auto path = std::string{"./IO/TestFiles/parseTest1.csv"};
	auto ui = std::make_unique<DummyMachineUserInterface>();
	auto machine = MachineFactory::CreateMachineFromFile(path, ui.get());
	BOOST_REQUIRE(machine != nullptr);
	AbstractMachine* val = machine.get();
	auto tm = dynamic_cast<TuringMachine*>(val);
	BOOST_REQUIRE(tm);
	auto toParse = std::string{"001"};
	tm->InitMachineForExecution(toParse);
	while (!tm->IsFinished())
	{
		tm->PerformNextStep();
	}

	BOOST_REQUIRE(ui->StateChanges == 26);
}
