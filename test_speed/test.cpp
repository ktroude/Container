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

	// res.vector = testVector();
	// res.pair = testPair();
	res.map = testMap();
	while (1)
	;
	res.stack = testStack();
	// res.set = testSet();

	usleep(SLEEP_DURATION);
	std::cout << "Test Result:" << std::endl;
	final += printResult("Vector", res.vector);
	final += printResult("Pair", res.pair);
	final += printResult("Map", res.map);
	final += printResult("Stack", res.stack);
	std::cout << "FINAL RESULT: ";
	std::cout << ((final == 4) ? "SUCCESS" : "FAILURE") << std::endl;

system("leaks a.out");
	while (1);

	
	return (0);
}