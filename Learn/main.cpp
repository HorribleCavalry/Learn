#include <iostream>
#include <cassert>
//Referenced: https://github.com/wuye9036/CppTemplateTutorial
//

struct A
{

};
template<typename T> struct B
{
	typedef T type;
};
template<typename T> struct X
{
	typedef X<T> _A;
	typedef X _B;
	typedef T _C;

	class Y
	{
	public:
		typedef X<T> _D;
		typedef X<T>::Y _E;

		typedef typename X<T*>::Y _F;
	};

	typedef A _G;
	typedef B<T> _H;

	typedef typename B<T>::type _I;
	typedef B<int>::type _J;
};

class Person
{
public:
	char c;
	int i;
	float f;
public:
	Person(const char& _c, const int& _i, const float& _f) : c(_c), i(_i), f(_f) {}
	Person(const char&_c) : Person(c, 0, 0.0f) {}
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

int main()
{
	X<int> x;
	//I really don't know what is _F.
	X<int>::Y::_F v;
}