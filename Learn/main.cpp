#include <iostream>
#include <cassert>
//Referenced: https://github.com/wuye9036/CppTemplateTutorial
//Part 2.22

template <typename T>
class TypeToID
{
	static int const ID = 0x80000000;
};

template <>
class TypeToID<float>
{
	static int const ID = 123;
};

template <typename T>
class TypeToID<T*>
{
public:
	typedef T		 SameAsT;
	static int const ID = 0x80000000;
};

//You can even customize overloaded classes based on templates.
template<typename T>
class AddFloatOrMulInt
{
//public:
//	static T Do(T a, T b);
};

template<>
class AddFloatOrMulInt<float>
{
public:
	static float Do(float a, float b)
	{
		return a + b;
	}
};

template<>
class AddFloatOrMulInt<int>
{
public:
	static int Do(int a, int b)
	{
		return a * b;
	}
};

int main()
{
	auto result0 = AddFloatOrMulInt<int>::Do(3, 2);
	auto result1 = AddFloatOrMulInt<float>::Do(3.0, 2.0);
}