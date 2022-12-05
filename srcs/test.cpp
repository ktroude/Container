#include <iostream>
#include <string>
#include <chrono>

#include "tests.hpp"
#include "testMap.cpp"
#include "testVector.cpp"
#include "testStack.cpp"
#include "testPair.cpp"
#include "testUtils.cpp"

typedef struct results {
	bool vector;
	bool map;
	bool pair;
	bool stack;
	bool set;
} results;

bool printResult(std::string container, bool res) {
	usleep(SLEEP_DURATION);
	std::cout << container << ": ";
	std::cout << ((res) ? "SUCCESS" : "FAILURE") << std::endl;
	return (res) ? true : false;
}

int main() {
	results res;
	int		final = 0;

	std::cout << "Test Starts." << std::endl;

	res.vector = testVector();
	res.pair = testPair();
	res.map = testMap();
	res.stack = testStack();

	usleep(SLEEP_DURATION);
	std::cout << "Test Result:" << std::endl;
	final += printResult("Vector", res.vector);
	final += printResult("Pair", res.pair);
	final += printResult("Map", res.map);
	final += printResult("Stack", res.stack);
	std::cout << "FINAL RESULT: ";
	std::cout << ((final == 4) ? "SUCCESS" : "FAILURE") << std::endl;


	sleep(2);
	std::cout << std::endl << std::endl;
	system("leaks speed_test");
	sleep(2);
	std::cout << std::endl << std::endl;
	system("rm -rf containers_test");
	system("rm -rf Include/containers_test");
	system("git clone https://github.com/mli42/containers_test.git");
	system("mv -f ./containers_test ./Include");
	system("rm -rf containers_test");
	system("cd Include/containers_test && ./do.sh");
	sleep(2);
	system("rm -rf Include/containers_test");


	
	return (0);
}