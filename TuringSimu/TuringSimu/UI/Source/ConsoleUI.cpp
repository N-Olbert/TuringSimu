#include <iostream>
#include "../../Business/Header/TuringMachine.hpp"

int main(int argc, char* argv[])
{
	ts_common::TuringMachineDefiniton def;
	def.states.insert(ts_common::State{"j"});
		def.states.insert(ts_common::State{"n"});
		def.states.insert(ts_common::State{"j"});
	std::cout << "Hello world, this is a test";
}
