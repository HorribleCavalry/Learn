#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <thread>
//referenceed https://www.jianshu.com/p/d686ad9de817

//class Foo
//{
//	int val = 0;
//
//	Foo(const Foo & f) : val(f.val)
//	{
//		std::cout << "called const Foo &" << std::endl;
//	}
//const Foo & f和Foo const& f其实是一个东西
//	Foo(Foo const& f) : val(f.val)
//	{
//		std::cout << "called Foo const&" << std::endl;
//	}
//
//	Foo(Foo && f) : val(f.val)
//	{
//		std::cout << "called Foo &&" << std::endl;
//	}
//};

std::function<int(int)> add_c(int x)
{
	return [&](int a) {return x + a; };
	//这个lambda表达式会捕捉到当前堆栈中所有地变量，会悬挂引用
}

int main()
{
	auto basicLambda = [] {std::cout << "Hello World!" << std::endl; };
	basicLambda();

	auto add = [](const int& a, const int& b) {return a + b; };

	auto multiply = [](const int& a, const int& b) {return a * b; };

	int x = 10;
	auto add_x = [x](const int& a) { return a + x; };

	//[]：默认不捕获任何变量；
	//[=]：默认以值捕获所有变量；
	//[&]：默认以引用捕获所有变量；
	//[x]：仅以值捕获x，其它变量不捕获；
	//[&x]：仅以引用捕获x，其它变量不捕获；
	//[=, &x]：默认以值捕获所有变量，但是x是例外，通过引用捕获；
	//[&, x]：默认以引用捕获所有变量，但是x是例外，通过值捕获；
	//[this]：通过引用捕获当前对象（其实是复制指针）；
	//[*this]：通过传值方式捕获当前对象；
	//注意最好不要使用[=]和[&]默认捕获所有变量。
	//首先说默认引用捕获所有变量，有很大可能会出现悬挂引用（Dangling references）
}