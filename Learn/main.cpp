#include <iostream>
#include <limits>

double hmean(double a, double b);

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
			z = hmean(x, y);
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "Please enter a new pair of numbers: "<<std::endl;
			continue;
		}
		std::cout << "Harmonic mean of x and y is: " << z << std::endl;
	}

	std::cout << "Bye!\n";
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b);
		throw ("Bad means.");
	return 2.0*a*b / (a + b);
}
