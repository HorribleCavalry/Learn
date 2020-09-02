#include <iostream>
#include <cassert>
#include <complex>
#include <type_traits>
//Referenced: https://github.com/wuye9036/CppTemplateTutorial
//

template<typename T, typename... Ts>
class Person
{
};

template<>
class Person<int>
{

};

template<>
class Person<float>
{

};

template<typename U>
class Person<U*>
{
public:
	U test;
};

template<typename T>
T DustomDivide(const T& a, const T& b)
{
	T v;
	return v;
}

template<typename T, typename Enable = std::true_type>
struct SafeDivide
{
	static void Do(const T&a, const T& b)
	{
		std::cout << "Called another!\n";
	}
};

template<typename T>
struct SafeDivide<T,typename std::is_floating_point<T>::type>
{
	static T Do(const T a, const T b)
	{
		std::cout << "Called float\n";
		return a / b;
	}
};

template<typename T>
struct SafeDivide<T, typename std::is_integral<T>::type>
{
	static T Do(const T a, const T b)
	{
		std::cout << "Called int\n";
		//assert(b != 0);
		return a / b;
	}
};

template<typename T>
class vec2
{
public:
	template<typename U, typename Enabled0 = std::true_type, typename Enabled1 = std::true_type>
	static void call(const vec2<U>& rhs)
	{
		std::cout<<"In mother called.\n"
	}

	template<typename U>
	static void call<U, typename std::is_floating_point<T>, typename std::is_integral<U>>(const vec2<U>& rhs)
	{

	}
};

//template<typename T>
//void vec2<T>::call()

int main()
{
	//std::is_integral

	Person<int> p0;
	Person<float> p1;
	Person<float*> p2;
	
	SafeDivide<int>::Do(1, 2);
	//SafeDivide<int>::Do(1, 0);
	SafeDivide<float>::Do(1.0, 2.0);

	SafeDivide<std::complex<float>>::Do({ 1.0f,2.0f }, { 1.0f,-2.0f });

	//It can not work, I don't know why.
	//Person<int, int> p2;
}