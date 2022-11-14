#include "tests.hpp"

#include <set>
#include "set.hpp"

using std::string;

void ft_countries(std::set<string> &real, ft::set<string> &mine){
	real.insert("Afghanistan");
	real.insert("Albania");
	real.insert("Algeria");
	real.insert("Andorra");
	real.insert("Angola");
	real.insert("Antigua et Barbuda");
	real.insert("Argentina");
	real.insert("Armenia");
	real.insert("Austria");
	real.insert("Azerbaijan");
	real.insert("Bahrain");
	real.insert("Bangladesh");
	real.insert("Barbados");
	real.insert("Belarus");
	real.insert("Belgium");
	real.insert("Belize");
	real.insert("Benin");
	real.insert("Bhutan");
	real.insert("Bolivia");
	real.insert("Bosnia and Herzegovina");
	real.insert("Botswana");
	real.insert("Brazil");
	real.insert("Brunei");
	real.insert("Bulgaria");
	real.insert("Burkina Faso");
	real.insert("Burundi");
	real.insert("Cabo Verde");
	real.insert("Cambodia");
	real.insert("Cameroon");
	real.insert("Canada");
	real.insert("Central African Republic");
	real.insert("Chad");
	real.insert("Channel Islands");
	real.insert("Chile");
	real.insert("China");
	real.insert("Colombia");
	real.insert("Comoros");
	real.insert("Congo");
	real.insert("Costa Rica");
	real.insert("Côte d'Ivoire");
	real.insert("Croatia");
	real.insert("Cuba");
	real.insert("Cyprus");
	real.insert("Czech Republic");
	real.insert("Denmark");
	real.insert("Djibouti");
	real.insert("Dominica");
	real.insert("Dominican Republic");
	real.insert("DR Congo");
	real.insert("Ecuador");
	real.insert("Egypt");
	real.insert("El Salvador");
	real.insert("Equatorial Guinea");
	real.insert("Eritrea");
	real.insert("Estonia");
	real.insert("Eswatini");
	real.insert("Ethiopia");
	real.insert("Faeroe Islands");
	real.insert("Finland");
	real.insert("France");
	real.insert("French Guiana");
	real.insert("Gabon");
	real.insert("Gambia");
	real.insert("Georgia");
	real.insert("Germany");
	real.insert("Ghana");
	real.insert("Gibraltar");
	real.insert("Greece");
	real.insert("Grenada");
	real.insert("Guatemala");
	real.insert("Guinea");
	real.insert("Guinea-Bissau");
	real.insert("Guyana");
	real.insert("Haiti");
	real.insert("Holy See");
	real.insert("Honduras");
	real.insert("Hong Kong");
	real.insert("Hungary");
	real.insert("Iceland");
	real.insert("India");
	real.insert("Indonesia");
	real.insert("Iran");
	real.insert("Iraq");
	real.insert("Ireland");
	real.insert("Isle of Man");
	real.insert("Israel");
	real.insert("Italy");
	real.insert("Jamaica");
	real.insert("Japan");
	real.insert("Jordan");
	real.insert("Kazakhstan");
	real.insert("Kenya");
	real.insert("Kuwait");
	real.insert("Kyrgyzstan");
	real.insert("Laos");
	real.insert("Latvia");
	real.insert("Lebanon");
	real.insert("Lesotho");
	real.insert("Liberia");
	real.insert("Libya");
	real.insert("Liechtenstein");
	real.insert("Lithuania");
	real.insert("Luxembourg");
	real.insert("Macao");
	real.insert("Madagascar");
	real.insert("Malawi");
	real.insert("Malaysia");
	real.insert("Maldives");
	real.insert("Mali");
	real.insert("Malta");
	real.insert("Mauritania");
	real.insert("Mauritius");
	real.insert("Mayotte");
	real.insert("Mexico");
	real.insert("Moldova");
	real.insert("Monaco");
	real.insert("Mongolia");
	real.insert("Montenegro");
	real.insert("Morocco");
	real.insert("Mozambique");
	real.insert("Myanmar");
	real.insert("Namibia");
	real.insert("Nepal");
	real.insert("Netherlands");
	real.insert("Nicaragua");
	real.insert("Niger");
	real.insert("Nigeria");
	real.insert("North Korea");
	real.insert("North Macedonia");
	real.insert("Norway");
	real.insert("Oman");
	real.insert("Pakistan");
	real.insert("Panama");
	real.insert("Paraguay");
	real.insert("Peru");
	real.insert("Philippines");
	real.insert("Poland");
	real.insert("Portugal");
	real.insert("Qatar");
	real.insert("Réunion");
	real.insert("Romania");
	real.insert("Russia");
	real.insert("Rwanda");
	real.insert("Saint Helena");
	real.insert("Saint Kitts et Nevis");
	real.insert("Saint Lucia");
	real.insert("Saint Vincent et the Grenadines");
	real.insert("San Marino");
	real.insert("Sao Tome et Principe");
	real.insert("Saudi Arabia");
	real.insert("Senegal");
	real.insert("Serbia");
	real.insert("Seychelles");
	real.insert("Sierra Leone");
	real.insert("Singapore");
	real.insert("Slovakia");
	real.insert("Slovenia");
	real.insert("Somalia");
	real.insert("South Africa");
	real.insert("South Korea");
	real.insert("South Sudan");
	real.insert("Spain");
	real.insert("Sri Lanka");
	real.insert("State of Palestine");
	real.insert("Sudan");
	real.insert("Suriname");
	real.insert("Sweden");
	real.insert("Switzerland");
	real.insert("Syria");
	real.insert("Taiwan");
	real.insert("Tajikistan");
	real.insert("Tanzania");
	real.insert("Thailand");
	real.insert("The Bahamas");
	real.insert("Timor-Leste");
	real.insert("Togo");
	real.insert("Trinidad et Tobago");
	real.insert("Tunisia");
	real.insert("Turkey");
	real.insert("Turkmenistan");
	real.insert("Uganda");
	real.insert("Ukraine");
	real.insert("United Arab Emirates");
	real.insert("United Kingdom");
	real.insert("United States");
	real.insert("Uruguay");
	real.insert("Uzbekistan");
	real.insert("Venezuela");
	real.insert("Vietnam");
	real.insert("Western Sahara");
	real.insert("Yemen");
	real.insert("Zambia");
	real.insert("Zimbabwe");

	mine.insert("Afghanistan");
	mine.insert("Albania");
	mine.insert("Algeria");
	mine.insert("Andorra");
	mine.insert("Angola");
	mine.insert("Antigua et Barbuda");
	mine.insert("Argentina");
	mine.insert("Armenia");
	mine.insert("Austria");
	mine.insert("Azerbaijan");
	mine.insert("Bahrain");
	mine.insert("Bangladesh");
	mine.insert("Barbados");
	mine.insert("Belarus");
	mine.insert("Belgium");
	mine.insert("Belize");
	mine.insert("Benin");
	mine.insert("Bhutan");
	mine.insert("Bolivia");
	mine.insert("Bosnia and Herzegovina");
	mine.insert("Botswana");
	mine.insert("Brazil");
	mine.insert("Brunei");
	mine.insert("Bulgaria");
	mine.insert("Burkina Faso");
	mine.insert("Burundi");
	mine.insert("Cabo Verde");
	mine.insert("Cambodia");
	mine.insert("Cameroon");
	mine.insert("Canada");
	mine.insert("Central African Republic");
	mine.insert("Chad");
	mine.insert("Channel Islands");
	mine.insert("Chile");
	mine.insert("China");
	mine.insert("Colombia");
	mine.insert("Comoros");
	mine.insert("Congo");
	mine.insert("Costa Rica");
	mine.insert("Côte d'Ivoire");
	mine.insert("Croatia");
	mine.insert("Cuba");
	mine.insert("Cyprus");
	mine.insert("Czech Republic");
	mine.insert("Denmark");
	mine.insert("Djibouti");
	mine.insert("Dominica");
	mine.insert("Dominican Republic");
	mine.insert("DR Congo");
	mine.insert("Ecuador");
	mine.insert("Egypt");
	mine.insert("El Salvador");
	mine.insert("Equatorial Guinea");
	mine.insert("Eritrea");
	mine.insert("Estonia");
	mine.insert("Eswatini");
	mine.insert("Ethiopia");
	mine.insert("Faeroe Islands");
	mine.insert("Finland");
	mine.insert("France");
	mine.insert("French Guiana");
	mine.insert("Gabon");
	mine.insert("Gambia");
	mine.insert("Georgia");
	mine.insert("Germany");
	mine.insert("Ghana");
	mine.insert("Gibraltar");
	mine.insert("Greece");
	mine.insert("Grenada");
	mine.insert("Guatemala");
	mine.insert("Guinea");
	mine.insert("Guinea-Bissau");
	mine.insert("Guyana");
	mine.insert("Haiti");
	mine.insert("Holy See");
	mine.insert("Honduras");
	mine.insert("Hong Kong");
	mine.insert("Hungary");
	mine.insert("Iceland");
	mine.insert("India");
	mine.insert("Indonesia");
	mine.insert("Iran");
	mine.insert("Iraq");
	mine.insert("Ireland");
	mine.insert("Isle of Man");
	mine.insert("Israel");
	mine.insert("Italy");
	mine.insert("Jamaica");
	mine.insert("Japan");
	mine.insert("Jordan");
	mine.insert("Kazakhstan");
	mine.insert("Kenya");
	mine.insert("Kuwait");
	mine.insert("Kyrgyzstan");
	mine.insert("Laos");
	mine.insert("Latvia");
	mine.insert("Lebanon");
	mine.insert("Lesotho");
	mine.insert("Liberia");
	mine.insert("Libya");
	mine.insert("Liechtenstein");
	mine.insert("Lithuania");
	mine.insert("Luxembourg");
	mine.insert("Macao");
	mine.insert("Madagascar");
	mine.insert("Malawi");
	mine.insert("Malaysia");
	mine.insert("Maldives");
	mine.insert("Mali");
	mine.insert("Malta");
	mine.insert("Mauritania");
	mine.insert("Mauritius");
	mine.insert("Mayotte");
	mine.insert("Mexico");
	mine.insert("Moldova");
	mine.insert("Monaco");
	mine.insert("Mongolia");
	mine.insert("Montenegro");
	mine.insert("Morocco");
	mine.insert("Mozambique");
	mine.insert("Myanmar");
	mine.insert("Namibia");
	mine.insert("Nepal");
	mine.insert("Netherlands");
	mine.insert("Nicaragua");
	mine.insert("Niger");
	mine.insert("Nigeria");
	mine.insert("North Korea");
	mine.insert("North Macedonia");
	mine.insert("Norway");
	mine.insert("Oman");
	mine.insert("Pakistan");
	mine.insert("Panama");
	mine.insert("Paraguay");
	mine.insert("Peru");
	mine.insert("Philippines");
	mine.insert("Poland");
	mine.insert("Portugal");
	mine.insert("Qatar");
	mine.insert("Réunion");
	mine.insert("Romania");
	mine.insert("Russia");
	mine.insert("Rwanda");
	mine.insert("Saint Helena");
	mine.insert("Saint Kitts et Nevis");
	mine.insert("Saint Lucia");
	mine.insert("Saint Vincent et the Grenadines");
	mine.insert("San Marino");
	mine.insert("Sao Tome et Principe");
	mine.insert("Saudi Arabia");
	mine.insert("Senegal");
	mine.insert("Serbia");
	mine.insert("Seychelles");
	mine.insert("Sierra Leone");
	mine.insert("Singapore");
	mine.insert("Slovakia");
	mine.insert("Slovenia");
	mine.insert("Somalia");
	mine.insert("South Africa");
	mine.insert("South Korea");
	mine.insert("South Sudan");
	mine.insert("Spain");
	mine.insert("Sri Lanka");
	mine.insert("State of Palestine");
	mine.insert("Sudan");
	mine.insert("Suriname");
	mine.insert("Sweden");
	mine.insert("Switzerland");
	mine.insert("Syria");
	mine.insert("Taiwan");
	mine.insert("Tajikistan");
	mine.insert("Tanzania");
	mine.insert("Thailand");
	mine.insert("The Bahamas");
	mine.insert("Timor-Leste");
	mine.insert("Togo");
	mine.insert("Trinidad et Tobago");
	mine.insert("Tunisia");
	mine.insert("Turkey");
	mine.insert("Turkmenistan");
	mine.insert("Uganda");
	mine.insert("Ukraine");
	mine.insert("United Arab Emirates");
	mine.insert("United Kingdom");
	mine.insert("United States");
	mine.insert("Uruguay");
	mine.insert("Uzbekistan");
	mine.insert("Venezuela");
	mine.insert("Vietnam");
	mine.insert("Western Sahara");
	mine.insert("Yemen");
	mine.insert("Zambia");
	mine.insert("Zimbabwe");
}

template<class Key, class Value>
bool compare(ft::set<Key, Value> mine, std::set<Key, Value> real) {
	if (mine.size() != real.size()) {
		PRINT_KO;
		std::cout << "MYSIZE: " << mine.size() << " / REALSIZE: " << real.size() << std::endl;
		return (false);
	}

	typename ft::set<Key, Value>::iterator	myIt;
	typename std::set<Key, Value>::iterator	realIt = real.begin();
	
	for (myIt = mine.begin(); myIt != mine.end(); myIt++) {
		if (*myIt != *realIt++) {
			PRINT_KO;
			return (false);
		}
	}
	PRINT_OK;
	return (true);
}

int testSet() {
	clock_t begin, end;
	float	realRes, myRes;
	int		res = 0, count = 0;

	ANNOUNCE1("CONSTRUCTOR TEST");

	ANNOUNCE2("Set Constructor Type 1: Default Constructor with compare");

	START_CLOCK;
	std::set<string> real;
	END_CLOCK_REAL;
	START_CLOCK;
	ft::set<string> mine;
	END_CLOCK_MY;
	CHECK(SET, ONLY_CLOCK);

	ANNOUNCE2("Set Constructor Type 2: Default Constructor with compare");
	START_CLOCK;
	real = std::set<string>(std::less<string>());
	END_CLOCK_REAL;
	START_CLOCK;
	mine = ft::set<string>(std::less<string>());
	END_CLOCK_MY;
	CHECK(SET, ONLY_CLOCK);

	ANNOUNCE2("Set Constructor Type 3: Constructor with iterator");
	std::set<string> realCountries;
	ft::set<string> myCountries;
	ft_countries(realCountries, myCountries);
	START_CLOCK;
	real = std::set<string>(realCountries.begin(), realCountries.end());
	END_CLOCK_REAL;
	START_CLOCK;
	mine = ft::set<string>(myCountries.begin(), myCountries.end());
	END_CLOCK_MY;
	CHECK(SET, DO_BOTH);

	ANNOUNCE2("Set Constructor Type 4: Copy constructor");
	START_CLOCK;
	real = std::set<string>(realCountries);
	END_CLOCK_REAL;
	START_CLOCK;
	mine = ft::set<string>(myCountries);
	END_CLOCK_MY;
	CHECK(SET, DO_BOTH);

	ANNOUNCE2("empty");
	try {
		bool realResult = real.empty();
		bool myResult = mine.empty();
		CHECK_RESULT;
	} catch (std::exception &e) {}

	ANNOUNCE2("size");
	try {
		bool realResult = real.size();
		bool myResult = mine.size();
		CHECK_RESULT;
	} catch (std::exception &e) {}

	ANNOUNCE2("clear");
	START_CLOCK;
	real.clear();
	END_CLOCK_REAL;
	START_CLOCK;
	mine.clear();
	END_CLOCK_MY;
	CHECK(SET, DO_BOTH);

	ANNOUNCE2("insert1: insert a pair");
	START_CLOCK;
	real.insert("Gondor");
	END_CLOCK_REAL;
	START_CLOCK;
	mine.insert("Gondor");
	END_CLOCK_MY;
	CHECK(SET, DO_BOTH);

	ANNOUNCE2("insert2: insert a pair with a hint");
	START_CLOCK;
	real.insert(real.begin(), "Rohan");
	END_CLOCK_REAL;
	START_CLOCK;
	mine.insert(mine.begin(), "Rohan");
	END_CLOCK_MY;
	CHECK(SET, DO_BOTH);

	ANNOUNCE2("insert3: insert with iterator");
	std::set<string> testReal;
	ft::set<string> testMine;
	testReal.insert("Castle Rock");
	testReal.insert("Winterfell");
	testMine.insert("Castle Rock");
	testMine.insert("Winterfell");
	START_CLOCK;
	real.insert(testReal.begin(), testReal.end());
	END_CLOCK_REAL;
	START_CLOCK;
	mine.insert(testMine.begin(), testMine.end());
	END_CLOCK_MY;
	CHECK(SET, DO_BOTH);

	ANNOUNCE2("erase1: erase with iterator");
	START_CLOCK;
	real.erase(real.begin());
	END_CLOCK_REAL;
	START_CLOCK;
	mine.erase(mine.begin());
	END_CLOCK_MY;
	CHECK(SET, DO_BOTH);

	ANNOUNCE2("erase2: erase with iteratable");
	std::set<string>::iterator realIt = real.find("Japan");
	ft::set<string>::iterator myIt = mine.find("Japan");
	START_CLOCK;
	real.erase(real.begin(), realIt);
	END_CLOCK_REAL;
	START_CLOCK;
	mine.erase(mine.begin(), myIt);
	END_CLOCK_MY;
	CHECK(SET, DO_BOTH);

	ANNOUNCE2("erase3: erase with a key");
	START_CLOCK;
	real.erase("Thailand");
	END_CLOCK_REAL;
	START_CLOCK;
	mine.erase("Thailand");
	END_CLOCK_MY;
	CHECK(SET, DO_BOTH);

	ANNOUNCE2("swap");
	START_CLOCK;
	real.swap(testReal);
	END_CLOCK_REAL;
	START_CLOCK;
	mine.swap(testMine);
	END_CLOCK_MY;
	CHECK(SET, DO_BOTH);

	ANNOUNCE2("count");
	try {
		size_t realResult = real.count("South Africa");
		size_t myResult = mine.count("South Africa");
		CHECK_RESULT;
	} catch (std::exception &e) {}

	ANNOUNCE2("find");
	try {
		real.insert("yoyo");
		mine.insert("yoyo");
		string realResult = *real.find("yoyo");
		string myResult = *mine.find("yoyo");
		CHECK_RESULT;
	} catch (std::exception &e) {}

	ANNOUNCE2("lower_bound");
	try {
		string realResult = *real.lower_bound("yoyo");
		string myResult = *mine.lower_bound("yoyo");
		CHECK_RESULT;
	} catch (std::exception &e) {}

	ANNOUNCE2("upper_bound");
	try {
		real.insert("bonbon");
		mine.insert("bonbon");

		string realResult = *real.upper_bound("bonbon");
		string myResult = *mine.upper_bound("bonbon");
		CHECK_RESULT;
	} catch (std::exception &e) {}

	ANNOUNCE2("equal_range pair first");
	try {
		string realResult = *real.equal_range("bonbon").first;
		string myResult = *mine.equal_range("bonbon").first;
		CHECK_RESULT;
	} catch (std::exception &e) {}

	ANNOUNCE2("equal_range pair second");
	try {
		string realResult = *real.equal_range("bonbon").second;
		string myResult = *mine.equal_range("bonbon").second;
		CHECK_RESULT;
	} catch (std::exception &e) {}


	END_TEST(SET);

}