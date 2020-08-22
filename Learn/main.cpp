#include <iostream>
#include <limits>
#include <string>
#include "exc_mean.h"

class demo
{
private:
	std::string word;
public:
	demo(const std::string& str)
	{
		word = str;
		std::cout << "demo" << word << "created\n";
	}
	~demo()
	{
		std::cout << "demo " << word << " destoryed\n";
	}

	void show() const
	{
		std::cout << "demo " << word << " lives!\n";
	}

	demo() = delete;
	demo(const demo&) = delete;
	demo(demo&&) = delete;
};

double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);

int main()
{

	double x, y;

	{
		demo d1("found in block in main()");
		std::cout << "Enter two numbers: ";
		while (true)
		{
			std::cin >> x;
			std::cin >> y;
			try
			{
				std::cout << "Called Mean: " << means(x, y) << std::endl;
				std::cout << "Please enter next pair:" << std::endl;
			}
			catch (bad_hmean& bh)
			{
				bh.mesg();
				continue;
			}
			catch (bad_gmean& bg)
			{
				bg.mesg();
			}
		}
		d1.show();
	}
	std::cout << "Bye!\n";
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean(a, b);
	return 2.0*a*b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0.0 || b < 0.0)
		throw bad_gmean(a, b);
	return std::sqrt(a * b);
}

double means(double a, double b)
{
	double am, hm, gm;
	demo d2("found in means()");
	am = 0.5f * (a + b);
	try
	{
		hm = hmean(a, b);
		gm = gmean(a, b);
	}
	catch (bad_hmean& bh)
	{
		bh.mesg();
		std::cout << "caught in means()\n";
		throw;
	}
	d2.show();
	return (am + hm + gm) / 3.0;
}
