﻿#include <iostream>
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

//template<typename T>
//class vec2
//{
//public:
//	template<typename U, typename Enabled0 = std::true_type, typename Enabled1 = std::true_type>
//	static void call(const vec2<U>& rhs)
//	{
//		std::cout<<"In mother called.\n"
//	}
//
//	template<typename U>
//	static void call<U, typename std::is_floating_point<T>, typename std::is_integral<U>>(const vec2<U>& rhs)
//	{
//
//	}
//};

//template<typename T>
//void vec2<T>::call()

class creation
{
public:
	creation(unsigned long _id) : id(_id) {}
	unsigned long id;
	static const creation human;
};
const creation creation::human(1);

template<typename T>
class vec4
{
public:
	T x, y, z, w;
public:
	vec4(T _x, T _y, T _z, T _w)
		:x(_x), y(_y), z(_z), w(_w)
	{
	}
public:
	vec4() : vec4(0, 0, 0, 0) {}
	vec4(const vec4& v) : vec4(v.x, v.y, v.z, v.w) {}
	vec4(vec4&& v) : vec4(v) {}
};

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
	std::cout << creation::human.id;

	vec4<float> vl;
	vec4<float> v(vl);

	//It can not work, I don't know why.
	//Person<int, int> p2;
}