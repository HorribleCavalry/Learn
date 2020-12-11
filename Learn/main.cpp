#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <thread>
#include <string>
#include <utility>
#include <mutex>


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

std::mutex mut0;
std::mutex mut1;

struct Increment0
{
	Increment0(int _idx, volatile int* _memPtr0) :idx(_idx), memPtr0(_memPtr0){}
	int idx;
	volatile int* memPtr0;
	void operator()()
	{
		for (int i = 0; i < 10000; i++)
		{
			mut0.lock();
			++(*memPtr0);
			for (int i = 0; i < 10000; i++)
			{
				++(*memPtr0);
				--(*memPtr0);
			}
			mut0.unlock();
		}
	}
};

struct Increment1
{
	Increment1(int _idx, volatile int* _memPtr0) :idx(_idx), memPtr0(_memPtr0) {}
	int idx;
	volatile int* memPtr0;
	void operator()()
	{
		for (int i = 0; i < 10000; i++)
		{
			mut0.lock();
			++(*memPtr0);
			//std::cout << "Idx=" << idx << "incremented num:" << *memPtr0 << std::endl;
			mut0.unlock();
		}
	}
};

struct Reading
{
	Reading(int _idx, volatile int* _memPtr0) :idx(_idx), memPtr0(_memPtr0) {}
	int idx;
	volatile int* memPtr0;
	void operator()()
	{
		while (true)
		{
			mut0.lock();
			std::cout << *memPtr0 << std::endl;
			mut0.unlock();
		}
	}
};

int main()
{
	volatile int base = 0;
	Increment0 op0(0, &base);
	Increment0 op1(1, &base);
	Reading op2(2, &base);
	std::thread th2(op2);
	std::thread th0(op0);
	std::thread th1(op1);
	th2.join();
	th0.join();
	th1.join();
}