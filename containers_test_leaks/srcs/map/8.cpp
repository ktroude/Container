#include "common.hpp"

#define T1 int
#define T2 std::string

TESTED_NAMESPACE::map<T1, T2> mp;
TESTED_NAMESPACE::map<T1, T2>::iterator it = mp.end();

void	ft_find(T1 const &k)
{
	TESTED_NAMESPACE::map<T1, T2>::iterator ret = mp.find(k);

	if (ret != it)
		printPair(ret);
//	else
//		std::cout << "map::find(" << k << ") returned end()" << std::endl;
}

void	ft_count(T1 const &k)
{
	mp.count(k);
}

int		main(void)
{
	mp[42] = "fgzgxfn";
	mp[25] = "funny";
	mp[80] = "hey";
	mp[12] = "no";
	mp[27] = "bee";
	mp[90] = "8";
	printSize(mp);

	// std::cout << "\t-- FIND --" << std::endl;
	ft_find(12);
	ft_find(3);
	ft_find(35);
	ft_find(90);
	ft_find(100);

	// std::cout << "\t-- COUNT --" << std::endl;
	ft_count(-3);
	ft_count(12);
	ft_count(3);
	ft_count(35);
	ft_count(90);
	ft_count(100);

	mp.find(27)->second = "newly inserted mapped_value";

	printSize(mp);

	TESTED_NAMESPACE::map<T1, T2> const c_map(mp.begin(), mp.end());
	c_map.find(42);
	c_map.count(80);
	system("leaks a.out");
	return (0);
}
