#include "../base.hpp"
#if !defined(USING_STD)
# include "vector.hpp"
#else
# include <vector>
#endif /* !defined(STD) */

#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

template <typename T>
void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
{
//	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent
;
	// std::cout << "capacity: " << isCapacityOk << std::endl;
	vct.max_size();
	if (print_content)
	{
		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
		// std::cout << std::endl << "Content is:" << std::endl;
		// for (; it != ite; ++it)
			// std::cout << "- " << *it << std::endl;
	}
	// std::cout << "###############################################" << std::endl;
}
