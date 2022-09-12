#include <iterator>
#include <vector>
#include "vector.hpp"
#include <iostream>

// #define TESTED_NAMESPACE ft
#define TESTED_NAMESPACE std

#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

template <typename T>
void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

#define TESTED_TYPE foo<int>

template <typename Ite_1, typename Ite_2>
void ft_eq_ope(const Ite_1 &first, const Ite_2 &second, const bool redo = 1)
{
	std::cout << (first < second) << std::endl;
	std::cout << (first <= second) << std::endl;
	std::cout << (first > second) << std::endl;
	std::cout << (first >= second) << std::endl;
	if (redo)
		ft_eq_ope(second, first, 0);
}

int		main(void)
{
	const int size = 5;
	TESTED_NAMESPACE::vector<int> vct(size);
	TESTED_NAMESPACE::vector<int>::reverse_iterator it_0(vct.rbegin());
	TESTED_NAMESPACE::vector<int>::reverse_iterator it_1(vct.rend());
	TESTED_NAMESPACE::vector<int>::reverse_iterator it_mid;

	TESTED_NAMESPACE::vector<int>::const_reverse_iterator cit_0 = vct.rbegin();
	TESTED_NAMESPACE::vector<int>::const_reverse_iterator cit_1;
	TESTED_NAMESPACE::vector<int>::const_reverse_iterator cit_mid;

	for (int i = size; it_0 != it_1; --i)
		*it_0++ = i;
	printSize(vct, 1);
	it_0 = vct.rbegin();
	cit_1 = vct.rend();
	it_mid = it_0 + 3;
	cit_mid = it_0 + 3; cit_mid = cit_0 + 3; cit_mid = it_mid;

	std::cout << std::boolalpha;
	std::cout << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << std::endl;

	std::cout << "\t\tft_eq_ope:" << std::endl;
	// regular it
	ft_eq_ope(it_0 + 3, it_mid);
	std::cout << "---------------------------------------------\n";
	ft_eq_ope(it_0, it_1);
	std::cout << (it_0 < it_1) << std::endl;
	std::cout << "---------------------------------------------\n";
	ft_eq_ope(it_1 - 3, it_mid);
	std::cout << "---------------------------------------------\n";
	// const it
	// ft_eq_ope(cit_0 + 3, cit_mid);
	// ft_eq_ope(cit_0, cit_1);
	// ft_eq_ope(cit_1 - 3, cit_mid);
	// std::cout << "---------------------------------------------\n";
	// // both it
	// ft_eq_ope(it_0 + 3, cit_mid);
	// ft_eq_ope(it_mid, cit_0 + 3);
	// ft_eq_ope(it_0, cit_1);
	// ft_eq_ope(it_1, cit_0);
	// ft_eq_ope(it_1 - 3, cit_mid);
	// ft_eq_ope(it_mid, cit_1 - 3);

	return (0);
}