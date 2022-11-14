#include "common.hpp"

#define TESTED_TYPE foo<int>
#define t_stack_ TESTED_NAMESPACE::stack
typedef t_stack_<TESTED_TYPE>::container_type container_type;

int		main(void)
{
	TESTED_NAMESPACE::stack<TESTED_TYPE> stck;

stck.empty();
stck.size();

	stck.push(41);
	stck.push(29);
	stck.push(10);
	stck.push(42);

stck.empty();
	printSize(stck);
	system("leaks a.out");

	return (0);
}
