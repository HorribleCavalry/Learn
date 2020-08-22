#include <iostream>
#include <limits>
#include "exc_mean.h"
double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
	
	double x, y, z;
	while (true)
	{
		std::cout << "Enter two numbers: " << std::endl;
		std::cin >> x;
		std::cin >> y;
		
		try
		{
			std::cout<<"The hmean is :"<< hmean(x, y)<< std::endl;
			std::cout<<"The gmean is :"<< gmean(x, y)<< std::endl;
		}
		catch (bad_hmean& bh)
		{
			bh.mesg();
			std::cout << "Please enter a new pair of numbers: "<<std::endl;
			continue;
		}
		catch (bad_gmean& bg)
		{
			bg.mesg();
			std::cout << "Please enter a new pair of numbers: " << std::endl;
			break;
		}
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
	if (a <0.0 || b <0.0)
		throw bad_gmean(a, b);
	return std::sqrt(a * b);
}
