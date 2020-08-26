#include <iostream>

//Referenced: https://github.com/wuye9036/CppTemplateTutorial

template<typename T>
auto Add(T&& a, T&& b)
{
	return a + b;
}

template<typename T>
class A
{

};

template<typename T>
T foo(const A<T>& v)
{
	return T();
}

int main()
{
	A<int> v;
	std::cout << foo(v);
}