#include <iostream>

//Referenced: https://github.com/wuye9036/CppTemplateTutorial

template<int i>
class A
{
public:
	static void foo(int i)
	{

	}
};

template <uint8_t a, typename b, void* c>
class B
{

};

template<bool, void(*a)()>
class C
{

};

//This writting style is not allowed, because the member function inside class can not be used in template declaration.
//template<void(A<3>::a*)()) > class D {};

template<int i> int Add(int a)
{
	return a + i;
}

void foo()
{
	A<5> a;
	B<7, A<5>, nullptr> b;
	C < false, &foo> c;
	//It can not run, this writing style is awful.
	//D<A<3>::foo> d;
	int x = Add < 3>(5);
}

int main()
{

}

//This writting style is not allowed, beacause the <float> type in template is not allowed.
//template <float a>class E {};