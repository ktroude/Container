#include <iterator>
#include <vector>
#include <algorithm>
#include "vector.hpp"
#include <iostream>
#include <list>
#include <map>
#include <utility>
#include <stack>


int main() {
std::map<std::string, int> m { {"CPU", 10}, {"GPU", 15}, {"RAM", 20}, };
std::pair<int, char>    p(8, 'p');
std::pair<int, char>    pp(8, 'p');

std::stack<int, std::vector<int> > s;
std::stack<int, std::vector<int> > t;

s.push(5);

s == t;
}
