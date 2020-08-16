#include <iostream>
#include <limits>

bool hmean(double a, double b, double* ans);

int main()
{
	double x, y, z;
	while (true)
	{
		std::cout << "Enter two numbers: " << std::endl;
		std::cin >> x;
		std::cin >> y;
		if (hmean(x, y, &z))
		{
			std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << std::endl;
		}
		else
		{
			std::cout << "One value should not be the negative of the other -  try again.\n";
		}
		std::cout << "Enter next set of numbers <q to quit>: ";
	}
	std::cout << "Bye!\n";
	return 0;
}

bool hmean(double a, double b, double * ans)
{
	(*ans) = a == -b ? std::numeric_limits<double>::max() : 2.0*a*b / (a + b);
	return !(a==-b);
}
