#include <iostream>
#include <cassert>
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

int main()
{
	Person<int> p0;
	Person<float> p1;
	Person<float*> p2;
	
	//It can not work, I don't know why.
	//Person<int, int> p2;
}