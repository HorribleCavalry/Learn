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
	func(int& i_) : i(i_) {}
	void operator()()
	{
		for (unsigned j = 0; j < 10000; j++)
		{
			do_something(i);
		}
	}
};

void oops()
{
	int some_local_state = 0;
	func my_func(some_local_state);
	std::thread my_thread(my_func);
	my_thread.join();
	std::cout << some_local_state;
}
struct f_mod
{
	int dev;
public:
	f_mod(const int& _dev) : dev(_dev) {}

	bool operator()(const int& x)
	{
		return x % dev == 0;
	}
};

float betsy(int);
float pam(int);

void test(float(*pf)(int))
{
	(*pf)(2);
}



template<typename T, typename U>
auto eff(T t, U u) ->decltype(t*u)
{
	return t * u;
}

class Useless
{
public:
	int n;
	char* pc;
	static int ct;
	void ShowObject() const;
public:
	Useless();
	explicit Useless(int k);
	Useless(int k, char ch);
	Useless(const Useless & f);
	Useless(Useless && f);
	Useless operator+(const Useless& f) const;
	Useless& operator=(const Useless& f);
	Useless& operator=(Useless&& f);
	void ShowData() const;
	~Useless();
};

int Useless::ct = 0;

void Useless::ShowObject() const
{
	std::cout << "Number of elements: " << n;
	std::cout << "Deta address: " << (void*)pc << std::endl;
}

Useless::Useless()
{
	++ct;
	n = 0;
	pc = nullptr;
	std::cout << "default constructor called; number of objects: " << ct << std::endl;
	ShowObject();
}

Useless::Useless(int k)
	:n(k)
{
	++ct;
	pc = new char[n];
	std::cout << "int constructor called; number of objects: " << ct << std::endl;
	ShowObject();
}

Useless::Useless(int k, char ch)
	:n(k)
{
	++ct;
	std::cout << "int, char constructor called; number of objects: " << ct << std::endl;
	pc = new char[n];
	for (uint32_t i = 0; i < n; i++)
	{
		pc[i] = ch;
	}
	ShowObject();
}

Useless::Useless(const Useless & f)
	:n(f.n)
{
	++ct;
	std::cout << "copy constructor called; number of objects: " << ct << std::endl;
	pc = new char[n];
	for (uint32_t i = 0; i < n; i++)
	{
		pc[i] = f.pc[i];
	}
	ShowObject();
}

Useless::Useless(Useless && f)
	:n(f.n)
{
	++ct;
	std::cout << "move constructor called; number of objects: " << ct << std::endl;
	pc = f.pc;
	f.pc = nullptr;
	f.n = 0;
	ShowObject();
}

Useless::~Useless()
{
	std::cout << "deconstructor called; objects left: " << --ct << std::endl;
	std::cout << "deleted object:\n";
	ShowObject();
	if (pc!=nullptr)
	{
		delete[] pc;
	}
}

Useless Useless::operator+(const Useless & f) const
{
	std::cout << "Entering operator+()\n";
	Useless temp = Useless(n + f.n);
	for (int i = 0; i < n; i++)
	{
		temp.pc[i] = pc[i];
	}

	for (int i = n; i < temp.n; i++)
	{
		temp.pc[i] = f.pc[i - n];
	}

	std::cout << "temp object:\n";
	std::cout << "Leaving operator+()\n";
	return temp;
}

Useless & Useless::operator=(const Useless & f)
{
	if (this==&f)
	{
		return *this;
	}

	delete[] pc;
	n = f.n;
	pc = new char[n];
	for (uint32_t i = 0; i < n; i++)
	{
		pc[i] = f.pc[i];
	}

	return *this;
}

Useless & Useless::operator=(Useless && f)
{
	if (this==&f)
	{
		return*this;
	}

	delete[] pc;
	f.n = 0;
	n = f.n;
	pc = f.pc;
	f.pc = nullptr;
	return *this;
}

void Useless::ShowData() const
{
	if (n == 0)
	{
		std::cout << "(Object empty)";
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			std::cout << pc[i];
		}
	}
	std::cout << std::endl;
}

int main()
{
	test(betsy);
	test(pam);
	float(*pf)(int) = betsy;
	(*pf)(2);
	pf = pam;
	(*pf)(2);

	auto df = betsy;
	(*df)(2);
	df = pam;
	(*df)(2);
	int* arr = new int[4]{ 1,2,1,2 };

	auto re =eff(12,1.5);

	std::cout << "Now it is the part of move situation:\n";

	{
		Useless one(10, 'x');
		Useless two = one;
		Useless three(20, 'o');
		Useless four(one + three);
		std::cout << "Object one: ";
		one.ShowData();

		std::cout << "Object two: ";
		two.ShowData();

		std::cout << "Object three: ";
		three.ShowData();

		std::cout << "Object four: ";
		four.ShowData();
	}

	return 0;
}

float betsy(int)
{
	std::cout << "betsy\n";
	return 0.0f;
}

float pam(int)
{
	std::cout << "pam\n";
	return 0.0f;
}
