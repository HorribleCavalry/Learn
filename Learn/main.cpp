#include <iostream>
#include <cassert>
//Referenced: https://github.com/wuye9036/CppTemplateTutorial
//Part 2.3.1

template<typename T>
struct X
{

};

template<typename T>
struct Y
{
	typedef X<T> ReboundType;
	typedef typename X<T>::MemberType MemberType;
	typedef UnknownType MemberType3;
	void foo()
	{
		X<T> instance0;
		typename X<T>::MemberType instance1;
		WTF instance2;
		It is nothing.
	}
};

int main()
{

}