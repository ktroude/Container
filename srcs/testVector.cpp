#include "tests.hpp"

#include "../Include/vector.hpp"
#include <vector>

template<class T>
void printMine(ft::vector<T> vec) {
	for (int i = 0; i < vec.size(); i++)
		std::cout << i + 1 << ": " << vec[i] << std::endl;
	std::cout << "actual size: " << vec.size() << " capacity: " << vec.capacity() << std::endl;
}

template<class T>
void printReal(std::vector<T> vec) {
	for (int i = 0; i < vec.size(); i++)
		std::cout << i + 1 << ": " << vec[i] << std::endl;
	std::cout << "actual size: " << vec.size() << " capacity: " << vec.capacity() << std::endl;
}

template<class T>
bool compare(ft::vector<T> mine, std::vector<T> real) {
	if (mine.size() != real.size()) {
		PRINT_KO;
		std::cout << "SIZE IS DIFFERENT: " << mine.size() << " / " << real.size() << std::endl;
		return (false);
	}

	for (int i = 0; i < mine.size(); i++) {
		if (mine[i] != real[i]) {
			PRINT_KO;
			return (false);
		}
	}
	PRINT_OK;
	return (true);
}

int testVector() {
	ft::vector<int>		mine;
	std::vector<int>	real;
	clock_t				begin, end;
	float				realRes, myRes;
	int					res = 0, count = 0;

	ANNOUNCE1("CONSTRUCTOR TEST");
	
	ANNOUNCE2("Vector Constructor Type 1: Default Constructor");
	START_CLOCK;
	real = std::vector<int>();
	END_CLOCK_REAL;
	START_CLOCK;
	mine = ft::vector<int>();
	END_CLOCK_MY;
	CHECK(VECTOR, ONLY_CLOCK);

	ANNOUNCE2("Vector Constructor Type 2-1: Constructor with count copies of elements with value (small size value)");
	size_t n = 10;
	START_CLOCK;
	real = std::vector<int>(n, 15);
	END_CLOCK_REAL;
	START_CLOCK;
	mine = ft::vector<int>(n, 15);
	END_CLOCK_MY;
	CHECK(VECTOR, DO_BOTH);

	ANNOUNCE2("Vector Constructor Type 2-2: Constructor with count copies of elements with value (big size value)");
	n = 1000;
	START_CLOCK;
	real = std::vector<int>(n, 125);
	END_CLOCK_REAL;
	START_CLOCK;
	mine = ft::vector<int>(n, 125);
	END_CLOCK_MY;
	CHECK(VECTOR, DO_BOTH);

	ANNOUNCE2("Vector Constructor Type 3-1: Constructor with count copies of elements with value (small size value)");
	n = 10;
	std::vector<int> testVec = std::vector<int>(n, 3000, std::allocator<int>());
	START_CLOCK;
	real = std::vector<int>(testVec.begin(), testVec.end(), std::allocator<int>());
	END_CLOCK_REAL;
	START_CLOCK;
	mine = ft::vector<int>(testVec.begin(), testVec.end(), std::allocator<int>());
	END_CLOCK_MY;
	CHECK(VECTOR, DO_BOTH);

	ANNOUNCE2("Vector Constructor Type 3-2: Constructor with count copies of elements with value (big size value)");
	n = 1500;
	testVec = std::vector<int>(n, 3000, std::allocator<int>());
	START_CLOCK;
	real = std::vector<int>(testVec.begin(), testVec.end(), std::allocator<int>());
	END_CLOCK_REAL;
	START_CLOCK;
	mine = ft::vector<int>(testVec.begin(), testVec.end(), std::allocator<int>());
	END_CLOCK_MY;
	CHECK(VECTOR, DO_BOTH);

	ANNOUNCE2("Vector Constructor Type 4: Copy Constructor");
	ft::vector<int> testMyVec = ft::vector<int>(n, 3000, std::allocator<int>());
	START_CLOCK;
	real = std::vector<int>(testVec);
	END_CLOCK_REAL;
	START_CLOCK;
	mine = ft::vector<int>(testMyVec);
	END_CLOCK_MY;
	CHECK(VECTOR, DO_BOTH);

	ANNOUNCE1("CAPACITY TEST");

	ANNOUNCE2("reserve");
	START_CLOCK;
	real.resize(500);
	END_CLOCK_REAL;
	START_CLOCK;
	mine.resize(500);
	END_CLOCK_MY;
	CHECK(VECTOR, ONLY_CLOCK);

	ANNOUNCE1("MODIFIER TEST");

	ANNOUNCE2("clear");
	START_CLOCK;
	real.clear();
	END_CLOCK_REAL;
	START_CLOCK;
	mine.clear();
	END_CLOCK_MY;
	CHECK(VECTOR, DO_BOTH);

	ANNOUNCE2("insert 1");
	n = 15;
	real = std::vector<int>(n, 15, std::allocator<int>());
	mine = ft::vector<int>(n, 15, std::allocator<int>());
	START_CLOCK;
	real.insert(real.begin() + 12, 35);
	END_CLOCK_REAL;
	START_CLOCK;
	mine.insert(mine.begin() + 12, 35);
	END_CLOCK_MY;
	CHECK(VECTOR, DO_BOTH);

	ANNOUNCE2("insert 2");
	n = 4;
	START_CLOCK;
	real.insert(real.begin() + 7, n, 99);
	END_CLOCK_REAL;
	START_CLOCK;
	mine.insert(mine.begin() + 7, n, 99);
	END_CLOCK_MY;
	CHECK(VECTOR, DO_BOTH);

	ANNOUNCE2("insert 3");
	n = 7;
	testVec = std::vector<int>(n, 777, std::allocator<int>());
	testMyVec = ft::vector<int>(n, 777, std::allocator<int>());
	START_CLOCK;
	real.insert(real.begin() + 5, testVec.begin(), testVec.end());
	END_CLOCK_REAL;
	START_CLOCK;
	mine.insert(mine.begin() + 5, testMyVec.begin(), testMyVec.end());
	END_CLOCK_MY;
	CHECK(VECTOR, DO_BOTH);

	ANNOUNCE2("erase 1");
	START_CLOCK;
	real.erase(real.begin() + 15);
	END_CLOCK_REAL;
	START_CLOCK;
	mine.erase(mine.begin() + 15);
	END_CLOCK_MY;
	CHECK(VECTOR, DO_BOTH);

	ANNOUNCE2("erase 2");
	START_CLOCK;
	real.erase(real.begin() + 2, real.begin() + 8);
	END_CLOCK_REAL;
	START_CLOCK;
	mine.erase(mine.begin() + 2, mine.begin() + 8);
	END_CLOCK_MY;
	CHECK(VECTOR, DO_BOTH);

	ANNOUNCE2("push_back");
	START_CLOCK;
	real.push_back(71359);
	END_CLOCK_REAL;
	START_CLOCK;
	mine.push_back(71359);
	END_CLOCK_MY;
	CHECK(VECTOR, DO_BOTH);

	ANNOUNCE2("pop_back");
	START_CLOCK;
	real.pop_back();
	END_CLOCK_REAL;
	START_CLOCK;
	mine.pop_back();
	END_CLOCK_MY;
	CHECK(VECTOR, DO_BOTH);

	ANNOUNCE2("resize");
	START_CLOCK;
	real.resize(40, 9);
	END_CLOCK_REAL;
	START_CLOCK;
	mine.resize(40, 9);
	END_CLOCK_MY;
	CHECK(VECTOR, DO_BOTH);

	ANNOUNCE2("swap");
	testVec = std::vector<int>(n, 777, std::allocator<int>());
	testMyVec = ft::vector<int>(n, 777, std::allocator<int>());
	START_CLOCK;
	real.swap(testVec);
	END_CLOCK_REAL;
	START_CLOCK;
	mine.swap(testMyVec);
	END_CLOCK_MY;
	CHECK(VECTOR, ONLY_CLOCK);

	END_TEST(VECTOR);
}
