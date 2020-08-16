#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <thread>

void do_something(int& i)
{
	++i;
}

struct func
{
	int& i;

	func(int& _i) : i(_i) {}

	void operator()()
	{
		std::cout << "Now called a func, it's referenced i is: " << i << std::endl;
		for (unsigned j = 0; j < 10000; j++)
		{
			do_something(i);
		}
	}
};

void do_something_in_current_thread()
{
	std::cout << "Now called do_something_in_current_thread!" << std::endl;
}

void f()
{
	int some_local_state = 0;
	func my_func(some_local_state);
	std::thread t(my_func);
	try
	{
		do_something_in_current_thread();
	}
	catch (...)
	{
		t.join();
		throw;
	}
	t.join();
}

int main()
{
	f();

	return 0;
}