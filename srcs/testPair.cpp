#include "tests.hpp"

#include <utility>
#include "../Include/iterator/pair.hpp"

template<typename T1, typename T2>
bool compare(ft::pair<T1, T2> mine, std::pair<T1, T2> real) {
	if (mine.first == real.first && mine.second == real.second) {
		PRINT_OK;
		return (true);
	}
	PRINT_KO;
	return (false);
}

int testPair() {
	std::pair<int, string>	real;
	ft::pair<int, string>	mine;
	clock_t					begin, end;
	float					realRes, myRes;
	int						res = 0, count = 0;

	ANNOUNCE2("Pair Constructor Type 1: Default constructor");

	START_CLOCK;
	real = std::pair<int, string>();
	END_CLOCK_REAL;
	START_CLOCK;
	mine = ft::pair<int, string>();
	END_CLOCK_MY;
	CHECK(PAIR, ONLY_CLOCK);

	ANNOUNCE2("Pair Constructor Type 2: Default constructor");
	
	START_CLOCK;
	real = std::pair<int, string>(51, "Absolument");
	END_CLOCK_REAL;
	START_CLOCK;
	mine = ft::pair<int, string>(51, "Absolument");
	END_CLOCK_MY;
	CHECK(PAIR, DO_BOTH);

	ANNOUNCE2("Pair Constructor Type 3: Copy constructor");
	std::pair<int, string>	testReal = std::pair<int, string>(12, "Je");
	ft::pair<int, string>	testMy = ft::pair<int, string>(12, "Je");
	
	START_CLOCK;
	real = std::pair<int, string>(testReal);
	END_CLOCK_REAL;
	START_CLOCK;
	mine = ft::pair<int, string>(testMy);
	END_CLOCK_MY;
	CHECK(PAIR, DO_BOTH);

	ANNOUNCE2("make_pair");
	
	START_CLOCK;
	real = std::make_pair(1, "M");
	END_CLOCK_REAL;
	START_CLOCK;
	mine = ft::make_pair(1, "M");
	END_CLOCK_MY;
	CHECK(PAIR, DO_BOTH);

	END_TEST(PAIR);
}