#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <thread>
#include <string>

void some_function()
{
	static int n = 0;
	std::cout << "some_function's n is: " << n << std::endl;
	++n;
}

void some_other_function(int n)
{

}

std::thread f()
{
	//void some_function();
	return std::thread(some_function);
}

std::thread g()
{
	//void some_other_function(int);
	std::thread t(some_other_function, 42);
	return t;
}

int main()
{
	std::thread t1 = f();
	t1.join();

	std::thread t2 = g();
	t2.join();
}