#include <iostream>

//Referenced: https://github.com/wuye9036/CppTemplateTutorial

template<typename T>
auto Add(T&& a, T&& b)
{
	return a + b;
}

int main()
{
	int a = 5;
	//int b = 3;
	int b = 3;
	auto result = Add(a, b);
	std::cout << result;
}