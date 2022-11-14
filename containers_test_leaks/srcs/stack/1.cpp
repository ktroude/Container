#include "common.hpp"

#define TESTED_TYPE foo<int>
#define t_stack_ TESTED_NAMESPACE::stack<TESTED_TYPE>
typedef t_stack_::container_type container_type;

int		main(void)
{
	container_type	ctnr;

	ctnr.push_back(21);
	ctnr.push_back(42);
	ctnr.push_back(1337);
	ctnr.push_back(19);
	ctnr.push_back(0);
	ctnr.push_back(183792);

	t_stack_		stck(ctnr);

stck.empty();
stck.size();

	stck.push(1);
	stck.push(2);
	stck.push(3);
	stck.push(4);
	stck.push(5);
	stck.push(6);


	std::cout << "empty: " << stck.empty() << std::endl;
	printSize(stck);
system("leaks a.out");
	return (0);
}
