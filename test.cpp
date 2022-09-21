#include "map.hpp"
#include <map>
#include <iostream>

#define T1 int
#define T2 std::string
#define TESTED_NAMESPACE ft

typedef TESTED_NAMESPACE::map<T1, T2>::value_type T3;
typedef TESTED_NAMESPACE::map<T1, T2>::iterator iterator;

#define _pair TESTED_NAMESPACE::pair

template <typename T>
std::string	printPair(T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator.first << " | value: " << iterator.second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
//	std::cout << "size: " << mp.size() << std::endl;
//	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

// void	printReverse(TESTED_NAMESPACE::map<T1, T2> &mp)
// {
// 	iterator it = mp.end(), ite = mp.begin();

// 	std::cout << "printReverse:" << std::endl;
// 	while (it != ite) {
// 		it--;
// 		std::cout << "-> " << printPair(it, false) << std::endl;
// 	}
// 	std::cout << "_______________________________________________" << std::endl;
// }

static int iter = 0;

template <typename MAP, typename U>
void	ft_insert(MAP &mp, U param)
{
	_pair<iterator, bool> tmp;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	tmp = mp.insert(param);
	std::cout << "insert return: " << printPair(tmp.first);
	std::cout << "Created new node: " << tmp.second << std::endl;
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_insert(MAP &mp, U param, V param2)
{
	iterator tmp;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	tmp = mp.insert(param, param2);
	std::cout << "insert return: " << printPair(tmp);
	printSize(mp);
}

int		main(void)
{
	std::map<T1, T2> mp, mp2;
	std::pair<int, char>
	ft_insert(mp, T3(42, "lol"));
	ft_insert(mp, T3(42, "mdr"));

	ft_insert(mp, T3(50, "mdr"));
	ft_insert(mp, T3(35, "funny"));

	ft_insert(mp, T3(45, "bunny"));
	ft_insert(mp, T3(21, "fizz"));
	ft_insert(mp, T3(38, "buzz"));

	return (0);
}
