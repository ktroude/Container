#include <iostream>
#include <set>
#include "./RedBlackTree.hpp"

#define T1 std::string

typedef std::set<T1>::iterator iterator;

static int iter = 0;

#define _pair std::pair

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "value: " << *iterator;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_SET>
void	printSize(T_SET const &st, bool print_content = 1)
{
//	std::cout << "size: " << st.size() << std::endl;
//	std::cout << "max_size: " << st.max_size() << std::endl;
	if (print_content)
	{
		iterator it = st.begin(), ite = st.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}


template <typename SET, typename U>
void	ft_insert(SET &st, U param)
{
	std::pair<iterator, bool> tmp;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	tmp = st.insert(param);
	std::cout << "insert return: " << printPair(tmp.first);
	std::cout << "Created new node: " << tmp.second << std::endl;
	printSize(st);
}

template <typename SET, typename U, typename V>
void	ft_insert(SET &st, U param, V param2)
{
	iterator tst;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	tst = st.insert(param, param2);
	std::cout << "insert return: " << printPair(tst);
	printSize(st);
}

int		main(void)
{
	// std::set<T1> st, st2;
	RBTree<T1, T1, T1> st, st2;

	ft_insert(st, "lol");
	ft_insert(st, "mdr");

	ft_insert(st, "mdr");
	ft_insert(st, "funny");

	ft_insert(st, "bunny");
	ft_insert(st, "fizz");
	ft_insert(st, "buzz");
}