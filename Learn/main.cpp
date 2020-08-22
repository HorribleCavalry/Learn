#include <iostream>
#include <new>
#include <cstdlib>//for exit();

struct Big
{
	double stuff[20000];
};

int main()
{
	Big* pb = nullptr;
	try
	{
		pb = new Big[1000];
	}
	catch (const std::exception& e)
	{
		e.what();
		exit(EXIT_FAILURE);
	}
	if (pb)
		delete[] pb;
	exit(EXIT_SUCCESS);

}
