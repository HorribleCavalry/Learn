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
class vec2
{
public:
	T x, y;
public:
	vec2(const T& _x, const T& _y) : x(_x), y(_y) {}
};

template<typename T, typename U>
const vec2<float> Add(const vec2<T>& v0, const vec2<U>& v1)
{
	return vec2<float>(v0.x, +v1.x, v0.y + v1.y);
}

template<typename T>
const vec2<T> Add(const vec2<T>& v0, const vec2<T>& v1)
{
	return vec2<T>(v0.x, +v1.x, v0.y + v1.y);
}

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

int main()
{
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