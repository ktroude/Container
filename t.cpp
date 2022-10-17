#include "map.hpp"
#include <map>
#include <iostream>
#include <list>

int main()
{
    ft::map<int, int>   a;

    for (int i = 0; i < 10; i++)
        a.insert(ft::make_pair(i, i * 3));
    
    for (ft::map<int, int>::iterator it = a.begin(); it != a.end(); it++)
        std::cout << "key = " << it->first << " |   value = " << it->second << std::endl;

    a.clear();

}