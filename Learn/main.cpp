#include <iostream>
#include <cassert>
//Referenced: https://github.com/wuye9036/CppTemplateTutorial
//Test vec.

template<typename T>
class vec2
{
public:
	T x,y;
public:
	vec2() : x(0), y(0) {}
	vec2(const T& _x, const T& _y) : x(_x), y(_y) {}
	vec2(const T& n) : x(n), y(n) {}
};

class vec2f : public vec2<float>
{
public:
	vec2f() : vec2<float>() {}
	template<typename T>
	vec2f(const T& _x, const T& _y) : vec2<float>(_x, _y) {}
	template<typename T>
	vec2f(const T& n) : vec2<float>(n) {}

	template<typename T>
	vec2f(const T& n) : vec2<float>(n.x, n.y) {}

	//vec2f(const vec2i& v) : vec2<float>(n) {}


};

class vec2i : public vec2<int>
{
public:
	vec2i() : vec2<int>() {}
	vec2i(const int& _x, const int& _y) : vec2<int>(_x,_y){}
	explicit vec2i(const vec2f& v)
	{
		x = static_cast<int>(v.x);
		y = static_cast<int>(v.y);
	}

	const vec2i& operator=(const vec2i& v)
	{
		x = v.x;
		y = v.y;
	}
};



const vec2f& operator+(const vec2i& v0, const vec2f& v1)
{
	return vec2f(v0.x + v1.x, v1.y + v1.y);
}
const vec2f& operator+(const vec2f& v0, const vec2i& v1)
{
	return vec2f(v0.x + v1.x, v1.y + v1.y);
}
template<typename T>
const vec2f& operator+(const T& n, const vec2f& v)
{
	return vec2f(n + v.x, n + v.y);
}
template<typename T>
const vec2f& operator+(const vec2f& v, const T& n)
{
	return vec2f(v.x + n, v.y + n);
}
const vec2f& operator+(const vec2i& v, const float& n)
{
	return vec2f(v.x + n, v.y + n);
}
const vec2f& operator+(const float& n, const vec2i& v)
{
	return vec2f(v.x + n, v.y + n);
}

const vec2i& operator+(const vec2i& v0, const vec2i& v1)
{
	return vec2i(v0.x + v1.x, v1.y + v1.y);
}
const vec2i& operator+(const int& n, const vec2i& v)
{
	return vec2i(v.x + n, v.y + n);
}
const vec2i& operator+(const vec2i& v, const int& n)
{
	return vec2i(v.x + n, v.y + n);
}


int main()
{
	vec2i i;
	vec2f f;

	const vec2i i;
	const vec2f f;
	
	float in = 0;
	float fn = 0.0f;

	auto temp = (f = i);
}