#include "../base.hpp"
#if !defined(USING_STD)
# include "stack.hpp"
#else
# include <stack>
#endif /* !defined(STD) */

template <typename T_STACK>
void	printSize(T_STACK &stck, bool print_content = 1)
{
	stck.size();
	if (print_content)
	{
		// std::cout << std::endl << "Content was:" << std::endl;
		while (stck.size() != 0) {
			stck.top();
			stck.pop();
		}
	}
	// std::cout << "###############################################" << std::endl;
}
