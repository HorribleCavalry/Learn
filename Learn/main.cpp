#include <iostream>
#include <cassert>
//Referenced: https://github.com/wuye9036/CppTemplateTutorial
//Test vec.

#define Int int
#define Float double

template<typename T>
class vec2
{
public:
	T x, y;
public:
	vec2() :x(0.0), y(0.0) {}
	vec2(const vec2<T>& v) : x(v.x), y(v.y) {}
	vec2(vec2<T>&& v) : x(v.x), y(v.y) {}
	vec2<T>& operator=(const vec2<T>& v)
	{
		x = v.x;
		y = v.y;
		return *this;
	}
	vec2<T>& operator=(vec2<T>&& v)
	{
		x = v.x;
		y = v.y;
		return *this;
	}
	~vec2() {}
public:
	vec2(const T& n) : x(n), y(n) {}
	vec2(const T& _x, const T& _y) : x(_x), y(_y) {}

	template<typename U>
	const vec2<T>(const vec2<U>& v) : x(v.x), y(v.y) {}

public:
	T& operator[](const T& idx)
	{
		//CHECK(idx >= 0 && idx <= 1, "The <idx> in vec2<T>::operator[idx] is illegal!");
		return idx == 0 ? x : y;
	}
public:
};

template<>
class vec2<Int>
{
public:
	Int x, y;
public:
	vec2() :x(0), y(0) {}
	vec2(const vec2<Int>& v) : x(v.x), y(v.y) {}
	vec2(vec2<Int>&& v) : x(v.x), y(v.y) {}
	const vec2<Int>& operator=(const vec2<Int>& v)
	{
		x = v.x;
		y = v.y;
		return *this;
	}
	const vec2<Int>& operator=(vec2<Int>&& v)
	{
		x = v.x;
		y = v.y;
		return *this;
	}
	~vec2() {}
public:
	vec2(const Int& n) : x(n), y(n) {}
	vec2(const Int& _x, const Int& _y) : x(_x), y(_y) {}

	vec2(const Float& n) = delete;
	vec2(const Float& _x, const Float& _y) = delete;

	explicit vec2(const vec2<Float>& v) : x(v.x), y(v.y) {}

public:
	Int& operator[](const Int& idx)
	{
		//CHECK(idx >= 0 && idx <= 1, "The <idx> in vec2<T>::operator[idx] is illegal!");
		return idx == 0 ? x : y;
	}
public:

};

//template<>
//class vec2<Float>
//{
//public:
//	Float x, y;
//public:
//	vec2() :x(0.0), y(0.0) {}
//	vec2(const vec2<Float>& v) : x(v.x), y(v.y) {}
//	vec2(vec2<Float>&& v) : x(v.x), y(v.y) {}
//	vec2<Float>& operator=(const vec2<Float>& v)
//	{
//		x = v.x;
//		y = v.y;
//		return *this;
//	}
//	vec2<Float>& operator=(vec2<Float>&& v)
//	{
//		x = v.x;
//		y = v.y;
//		return *this;
//	}
//	~vec2() {}
//public:
//	vec2(const Float& n) : x(n), y(n) {}
//	vec2(const Float& _x, const Float& _y) : x(_x), y(_y) {}
//public:
//	Float& operator[](const Int& idx)
//	{
//		//CHECK(idx >= 0 && idx <= 1, "The <idx> in vec2<T>::operator[idx] is illegal!");
//		return idx == 0 ? x : y;
//	}
//public:
//
//};

typedef vec2<Int> vec2i;
typedef vec2<Float> vec2f;

int main()
{
	vec2i i;
	vec2f f;

	const vec2i ci;
	const vec2f cf;
	
	Int in = 0;
	Float fn = 0.0f;
	f = i;
	i = f;
}