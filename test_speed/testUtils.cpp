#include "tests.hpp"

int	printTimeResult(char *container, double realRes, double myRes) {
	if (realRes * 20 < myRes) {
		printf("real%s: \033[0;31m%f\t\t\033[0;37mmy%s: %f\t\t", container, realRes, container, myRes);
		return (0);
	}
	else if (realRes < myRes) 
		printf("real%s: \033[0;33m%f\t\t\033[0;37mmy%s: %f\t\t", container, realRes, container, myRes);
	else
		printf("real%s: %f\t\tmy%s: \033[0;32m%f\033[0;37m\t\t", container, realRes, container, myRes);
	return (1);
}