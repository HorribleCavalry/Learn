#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <thread>

class thread_guard
{
	std::thread& t;
public:
	//referenced parameter can not use constant perfixion.
	explicit thread_guard(std::thread& _t) : t(_t) {}

	~thread_guard()
	{
		if (t.joinable())
		{
			t.join();
		}
	}
	thread_guard(thread_guard const&) = delete;
	//thread_guard(thread_guard &&) = delete;
	thread_guard& operator=(thread_guard const&) = delete;
};

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
		for (unsigned j = 0; j < 10000; j++)
		{
			do_something(i);
		}
	}
};

void do_something_in_current_thread()
{}

int main()
{
	int some_local_state;
	func my_func(some_local_state);
	std::thread t(my_func);
	thread_guard g(t);

	do_something_in_current_thread();

}