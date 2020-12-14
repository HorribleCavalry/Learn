#include <iostream>
#include <new>

//This function will run when called std::set_new_handler(handler) and memory allocation failed.
void handler()
{
	std::cout << "Memory allocation failed, terminating\n";
	std::set_new_handler(nullptr);
}

int main()
{
	std::cout << "Hello world!";

	std::set_new_handler(handler);

	try
	{
		while (true)
		{
			new int[100000000ul];
		}
	}
	catch (const std::bad_alloc& e)
	{
		std::cout << e.what();
	}

}