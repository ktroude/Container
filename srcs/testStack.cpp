#include "tests.hpp"

#include "../Include/stack.hpp"
#include <stack>

template<class T>
void printMine(ft::stack<T> vec) {
	for (int i = 0; i < vec.size(); i++)
		std::cout << i + 1 << ": " << vec[i] << std::endl;
	std::cout << "actual size: " << vec.size() << " capacity: " << vec.capacity() << std::endl;
}

template<class T>
void printReal(std::stack<T> vec) {
	for (int i = 0; i < vec.size(); i++)
		std::cout << i + 1 << ": " << vec[i] << std::endl;
	std::cout << "actual size: " << vec.size() << " capacity: " << vec.capacity() << std::endl;
}

template<class T>
bool compare(ft::stack<T> mine, std::stack<T> real) {
	if (mine.size() != real.size()) {
		PRINT_KO;
		return (false);
	}

	while (mine.size()) {
		if (mine.top() != real.top()) {
			PRINT_KO;
			return (false);
		}
		mine.pop();
		real.pop();
	}
	PRINT_OK;
	return (true);
}

int testStack() {
	ft::stack<int>		mine, testMine;
	std::stack<int>		real, testReal;
	clock_t				begin, end;
	float				realRes, myRes;
	int					res = 0, count = 0;

	ANNOUNCE1("CONSTRUCTOR TEST");
	
	ANNOUNCE2("Stack Constructor Type 1: Default Constructor");
	START_CLOCK;
	real = std::stack<int>();
	END_CLOCK_REAL;
	START_CLOCK;
	mine = ft::stack<int>();
	END_CLOCK_MY;
	CHECK(STACK, ONLY_CLOCK);

	ANNOUNCE2("Stack Constructor Type 1: Copy Constructor");
	testMine.push(5);
	testMine.push(42);
	testMine.push(29);
	testReal.push(5);
	testReal.push(42);
	testReal.push(29);
	START_CLOCK;
	real = std::stack<int>(testReal);
	END_CLOCK_REAL;
	START_CLOCK;
	mine = ft::stack<int>(testMine);
	END_CLOCK_MY;
	CHECK(STACK, ONLY_CLOCK);

	// ANNOUNCE2("top");
	// try {
	// 	int myResult = mine.top();
	// 	int realResult = real.top();
	// 	CHECK_RESULT;
	// } catch (std::exception &e) {}

	// ANNOUNCE2("empty");
	// try {
	// 	bool myResult = mine.empty();
	// 	bool realResult = real.empty();
	// 	CHECK_RESULT;
	// } catch (std::exception &e) {}

	// ANNOUNCE2("size");
	// try {
	// 	size_t myResult = mine.size();
	// 	size_t realResult = real.size();
	// 	CHECK_RESULT;
	// } catch (std::exception &e) {}

	// ANNOUNCE2("push");
	// START_CLOCK;
	// real.push(9473);
	// END_CLOCK_REAL;
	// START_CLOCK;
	// mine.push(9473);
	// END_CLOCK_MY;
	// CHECK(STACK, DO_BOTH);

	// ANNOUNCE2("pop");
	// real.push(335);
	// real.push(194);
	// mine.push(335);
	// mine.push(194);
	// START_CLOCK;
	// real.pop();
	// END_CLOCK_REAL;
	// START_CLOCK;
	// mine.pop();
	// END_CLOCK_MY;
	// CHECK(STACK, DO_BOTH);

	END_TEST(STACK);
}
