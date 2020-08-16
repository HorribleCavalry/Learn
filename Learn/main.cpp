#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <thread>
#include <string>
#include <utility>


class scoped_thread
{
	std::thread t;
public:
	explicit scoped_thread(std::thread _t)
		:t(std::move(_t))
	{
		if (!t.joinable())
		{
			throw std::logic_error("No thread");
		}
	}
	~scoped_thread()
	{
		t.join();
	}

	scoped_thread(scoped_thread const&) = delete;
	scoped_thread& operator=(scoped_thread const&) = delete;


};

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