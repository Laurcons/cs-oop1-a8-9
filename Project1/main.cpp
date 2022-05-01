#include "base.h"
#include "controller.h"
#include "ui.h"
#include "tests.h"
#include <iostream>

int main() {

	{
		bub::tests t;
		t.test_all();

		auto file_repo = new bub::file_tutorial_repo{ "data.dat" };
		bub::tutorial_controller ctrl{ file_repo };
		bub::ui ui{ ctrl };

		ui.start();

		delete file_repo;
	}

	int res = _CrtDumpMemoryLeaks();
	if (res)
		std::cout << "!!!!!!!!!!!!!!!!\nMEMORY LEAKS FOUND\n";
	else std::cout << "Memory correctly deallocated.";
}