#include "common.hpp"
#include <list>

#define TESTED_TYPE foo<int>
typedef std::list<TESTED_TYPE> container_type;
#define t_stack_ TESTED_NAMESPACE::stack<TESTED_TYPE, container_type>

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

	// std::cout << "Added some elements" << std::endl;

	stck.empty();
	printSize(stck);
	system("leaks a.out");

	return (0);
}
