#include "tests.hpp"

#include <map>
#include "../map.hpp"
#include <utility>

void ft_hitchcock(std::map<string, int> &real, ft::map<string, int> &mine){
	real["The Pleasure Garden"] = 1925;
	real["The Lodger"] = 1927;
	real["The Ring"] = 1927;
	real["Downhill"] = 1927;
	real["The Farmer's Wife"] = 1928;
	real["Easy Virtue"] = 1928;
	real["Champagne"] = 1928;
	real["The Manxman"] = 1929;
	real["Blackmail"] = 1929;
	real["Juno and the Paycock"] = 1930;
	real["Murder!"] = 1930;
	real["The Skin Game"] = 1931;
	real["Mary" ]= 1931;
	real["Rich and Strange"] = 1931;
	real["Number Seventeen"] = 1932;
	real["Waltzes from Vienna"] = 1934;
	real["The Man Who Knew Too Much"] = 1934;
	real["The 39 Steps"] = 1935;
	real["Secret Agent"] = 1936;
	real["Sabotage" ]= 1936;
	real["Young and Innocent"] = 1937;
	real["The Lady Vanishes"] = 1938;
	real["Jamaica Inn"] = 1939;
	real["Rebecca"] = 1940;
	real["Foreign Correspondent"] = 1940;
	real["Mr. & Mrs. Smith"] = 1941;
	real["Suspicion"] = 1941;
	real["Saboteur"] = 1942;
	real["Shadow of a Doubt"] = 1943;
	real["Lifeboat"] = 1944;
	real["Spellbound"] = 1945;
	real["Notorious"] = 1946;
	real["The Paradine Case"] = 1947;
	real["Rope"] = 1948;
	real["Under Capricorn"] = 1949;
	real["Stage Fright"] = 1950;
	real["Strangers on a Train"] = 1951;
	real["I Confess"] = 1953;
	real["Dial M for Murder"] = 1954;
	real["Rear Window"] = 1954;
	real["To Catch a Thief"] = 1955;
	real["The Trouble with Harry"] = 1955;
	real["The Man Who Knew Too Much"] = 1956;
	real["The Wrong Man"] = 1956;
	real["Vertigo"] = 1958;
	real["North by Northwest"] = 1959;
	real["Psycho"] = 1960;
	real["The Birds" ]= 1963;
	real["Marnie"] = 1964;
	real["Torn Curtain"] = 1966;
	real["Topaz"] = 1969;
	real["Frenzy"] = 1972;
	real["Family Plot"] = 1976;

	mine["The Pleasure Garden"] = 1925;
	mine["The Lodger"] = 1927;
	mine["The Ring"] = 1927;
	mine["Downhill"] = 1927;
	mine["The Farmer's Wife"] = 1928;
	mine["Easy Virtue"] = 1928;
	mine["Champagne"] = 1928;
	mine["The Manxman"] = 1929;
	mine["Blackmail"] = 1929;
	mine["Juno and the Paycock"] = 1930;
	mine["Murder!"] = 1930;
	mine["The Skin Game"] = 1931;
	mine["Mary" ]= 1931;
	mine["Rich and Strange"] = 1931;
	mine["Number Seventeen"] = 1932;
	mine["Waltzes from Vienna"] = 1934;
	mine["The Man Who Knew Too Much"] = 1934;
	mine["The 39 Steps"] = 1935;
	mine["Secret Agent"] = 1936;
	mine["Sabotage" ]= 1936;
	mine["Young and Innocent"] = 1937;
	mine["The Lady Vanishes"] = 1938;
	mine["Jamaica Inn"] = 1939;
	mine["Rebecca"] = 1940;
	mine["Foreign Correspondent"] = 1940;
	mine["Mr. & Mrs. Smith"] = 1941;
	mine["Suspicion"] = 1941;
	mine["Saboteur"] = 1942;
	mine["Shadow of a Doubt"] = 1943;
	mine["Lifeboat"] = 1944;
	mine["Spellbound"] = 1945;
	mine["Notorious"] = 1946;
	mine["The Paradine Case"] = 1947;
	mine["Rope"] = 1948;
	mine["Under Capricorn"] = 1949;
	mine["Stage Fright"] = 1950;
	mine["Strangers on a Train"] = 1951;
	mine["I Confess"] = 1953;
	mine["Dial M for Murder"] = 1954;
	mine["Rear Window"] = 1954;
	mine["To Catch a Thief"] = 1955;
	mine["The Trouble with Harry"] = 1955;
	mine["The Man Who Knew Too Much"] = 1956;
	mine["The Wrong Man"] = 1956;
	mine["Vertigo"] = 1958;
	mine["North by Northwest"] = 1959;
	mine["Psycho"] = 1960;
	mine["The Birds" ]= 1963;
	mine["Marnie"] = 1964;
	mine["Torn Curtain"] = 1966;
	mine["Topaz"] = 1969;
	mine["Frenzy"] = 1972;
	mine["Family Plot"] = 1976;
}

void ft_kubrick(std::map<string, int> &real, ft::map<string, int> &mine){
	real["Fear and Desire"] = 1952;
	real["Killer's Kiss"] = 1955;
	real["Killing"] = 1956;
	real["Paths of Glory"] = 1957;
	real["Spartacus"] = 1960;
	real["Lolita"] = 1962;
	real["Dr.Strangelove"] = 1964;
	real["2001 : Space Odyssey"] = 1968;
	real["A Clockwork Orange"] = 1971;
	real["Barry Lyndon"] = 1975;
	real["The Shining"] = 1980;
	real["Full Metal Jacket"] = 1987;
	real["Eyes Wide Shut"] = 1999;

	mine["Fear and Desire"] = 1952;
	mine["Killer's Kiss"] = 1955;
	mine["Killing"] = 1956;
	mine["Paths of Glory"] = 1957;
	mine["Spartacus"] = 1960;
	mine["Lolita"] = 1962;
	mine["Dr.Strangelove"] = 1964;
	mine["2001 : Space Odyssey"] = 1968;
	mine["A Clockwork Orange"] = 1971;
	mine["Barry Lyndon"] = 1975;
	mine["The Shining"] = 1980;
	mine["Full Metal Jacket"] = 1987;
	mine["Eyes Wide Shut"] = 1999;

}

template<class Key, class Value>
bool compare(ft::map<Key, Value> mine, std::map<Key, Value> real) {
	if (mine.size() != real.size()) {
		PRINT_KO;
		std::cout << "MYSIZE: " << mine.size() << " / REALSIZE: " << real.size() << std::endl;
		return (false);
	}
	typename ft::map<Key, Value>::iterator	myIt;
	typename std::map<Key, Value>::iterator	realIt = real.begin();
	
	for (myIt = mine.begin(); myIt != mine.end(); myIt++) {
		if (myIt->first != (realIt++)->first) {
			PRINT_KO;
			return (false);
		}
	}
	PRINT_OK;
	return (true);
}

int testMap() {
	clock_t begin, end;
	float	realRes, myRes;
	int		res = 0, count = 0;

	ANNOUNCE1("CONSTRUCTOR TEST");
	
	ANNOUNCE2("Map Constructor Type 1: Default Constructor");

	START_CLOCK;
	std::map<string, int> real;
	END_CLOCK_REAL;
	START_CLOCK;
	ft::map<string, int> mine;
	END_CLOCK_MY;
	CHECK(MAP, ONLY_CLOCK);

	ANNOUNCE2("Map Constructor Type 2: Constructor with iterator");
	std::map<string, int>	realHitchcock;
	ft::map<string, int>	myHitchcock;

	ft_hitchcock(realHitchcock, myHitchcock);
	
	START_CLOCK;
	real = std::map<string, int>(realHitchcock.begin(), realHitchcock.end());
	END_CLOCK_REAL;
	START_CLOCK;
	mine = ft::map<string, int>(myHitchcock.begin(), myHitchcock.end());
	END_CLOCK_MY;
	CHECK(MAP, DO_BOTH);

	ANNOUNCE2("Map Constructor Type 3: Copy Constructor");
	std::map<string, int>	realKubrick;
	ft::map<string, int>	myKubrick;

	ft_kubrick(realKubrick, myKubrick);
	
	START_CLOCK;
	real = std::map<string, int>(realKubrick);
	END_CLOCK_REAL;
	START_CLOCK;
	mine = ft::map<string, int>(myKubrick);
	END_CLOCK_MY;
	CHECK(MAP, DO_BOTH);

	ANNOUNCE2("at");
	try {
		int realResult = real.at("A Clockwork Orange");
		int myResult = mine.at("A Clockwork Orange");
		CHECK_RESULT;
	} catch (std::exception &e) {}

	ANNOUNCE2("operator[]");
	try {
		int realResult = real["The Shining"];
		int myResult = mine["The Shining"];
		CHECK_RESULT;
	} catch (std::exception &e) {}

	ANNOUNCE2("operator[] for a key which doesn't exist");
	try {
		int realResult = real["Iron Man"];
		int myResult = mine["Iron Man"];
		CHECK_RESULT;
	} catch (std::exception &e) {}

	ANNOUNCE2("empty");
	try {
		int realResult = real.empty();
		int myResult = mine.empty();
		CHECK_RESULT;
	} catch (std::exception &e) {}

	ANNOUNCE2("size");
	try {
		int realResult = real.size();
		int myResult = mine.size();
		CHECK_RESULT;
	} catch (std::exception &e) {}

	ANNOUNCE2("clear");
	START_CLOCK;
	real.clear();
	END_CLOCK_REAL;
	START_CLOCK;
	mine.clear();
	END_CLOCK_MY;
	CHECK(MAP, DO_BOTH);

	ANNOUNCE2("insert1: insert a pair");
	START_CLOCK;
	real.insert(std::make_pair("France", 33));
	END_CLOCK_REAL;
	START_CLOCK;
	mine.insert(ft::make_pair("France", 33));
	END_CLOCK_MY;
	CHECK(MAP, DO_BOTH);

	ANNOUNCE2("insert2: insert a pair with a hint");
	START_CLOCK;
	real.insert(real.begin(), std::make_pair("Argentina", 54));
	END_CLOCK_REAL;
	START_CLOCK;
	mine.insert(mine.begin(), ft::make_pair("Argentina", 54));
	END_CLOCK_MY;
	CHECK(MAP, DO_BOTH);

	ANNOUNCE2("insert3: insert with iterator");
	START_CLOCK;
	real.insert(realHitchcock.begin(), realHitchcock.end());
	END_CLOCK_REAL;
	START_CLOCK;
	mine.insert(myHitchcock.begin(), myHitchcock.end());
	END_CLOCK_MY;
	CHECK(MAP, DO_BOTH);

	ANNOUNCE2("erase1: erase with iterator");
	START_CLOCK;
	real.erase(real.begin());
	END_CLOCK_REAL;
	START_CLOCK;
	mine.erase(mine.begin());
	END_CLOCK_MY;
	CHECK(MAP, DO_BOTH);

	ANNOUNCE2("erase2: erase with iteratable");
	std::map<string, int>::iterator realIt = real.find("Paths of Glory");
	ft::map<string, int>::iterator myIt = mine.find("Paths of Glory");
	START_CLOCK;
	real.erase(real.begin(), realIt);
	END_CLOCK_REAL;
	START_CLOCK;
	mine.erase(mine.begin(), myIt);
	END_CLOCK_MY;
	CHECK(MAP, DO_BOTH);

	ANNOUNCE2("erase3: erase with a key");
	START_CLOCK;
	real.erase("Paths of Glory");
	END_CLOCK_REAL;
	START_CLOCK;
	mine.erase("Paths of Glory");
	END_CLOCK_MY;
	CHECK(MAP, DO_BOTH);

	ANNOUNCE2("swap");
	START_CLOCK;
	real.swap(realHitchcock);
	END_CLOCK_REAL;
	START_CLOCK;
	mine.swap(myHitchcock);
	END_CLOCK_MY;
	CHECK(MAP, DO_BOTH);

	ANNOUNCE2("count");
	try {
		int realResult = real.count("Container");
		int myResult = mine.count("Container");
		CHECK_RESULT;
	} catch (std::exception &e) {}

	ANNOUNCE2("find");
	try {
		int realResult = (real.find("The Birds"))->second;
		int myResult = (mine.find("The Birds"))->second;
		CHECK_RESULT;
	} catch (std::exception &e) {}

	ANNOUNCE2("lower_bound");
	try {
		int realResult = real.lower_bound("The Birds")->second;
		int myResult = mine.lower_bound("The Birds")->second;
		CHECK_RESULT;
	} catch (std::exception &e) {}

	ANNOUNCE2("upper_bound");
	try {
		int realResult = real.upper_bound("The Birds")->second;
		int myResult = mine.upper_bound("The Birds")->second;
		CHECK_RESULT;
	} catch (std::exception &e) {}

	ANNOUNCE2("equal_range pair first");
	try {
		int realResult = real.equal_range("Notorious").first->second;
		int myResult = mine.equal_range("Notorious").first->second;
		CHECK_RESULT;
	} catch (std::exception &e) {}

	ANNOUNCE2("equal_range pair second");
	try {
		int realResult = real.equal_range("Notorious").second->second;
		int myResult = mine.equal_range("Notorious").second->second;
		CHECK_RESULT;
	} catch (std::exception &e) {}

	END_TEST(MAP);
}

