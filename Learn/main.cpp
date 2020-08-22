﻿#include <iostream>
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

	scoped_thread() = delete;
	scoped_thread(scoped_thread const&) = delete;
	scoped_thread& operator=(scoped_thread const&) = delete;

};

void do_something(int& i)
{
	++i;
}

struct func
{
	int& i;
	func(int& i_) :i(i_) {}
	void operator()()
	{
		for (int j = 0; j < 1000; j++)
		{
			do_something(i);
		}
	}
};
void do_something_in_current_thread()
{

}
void f()
{
	int some_local_state = 0;
	scoped_thread t(std::thread(func(some_local_state)));
	do_something_in_current_thread();
}

int main()
{
	f();
}