#include <iostream>
#include "CAVSTL/allocator.h"
int main()
{
	std::cout << "Hello world!";
	CAVSTD::allocator<int> all;
	all.allocate(10);
}