#include "tests.h"
#include <vector>
#include <iostream>
#include <crtdbg.h>

int main() {
	laur::test_all();

	if (_CrtDumpMemoryLeaks()) {
		std::cout << "MEMORY LEAKS DETECTED!!!!";
	}
	else {
		std::cout << "No memory leaks! :)";
	}
}