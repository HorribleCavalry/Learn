#include <iostream>
#include <cassert>
//Referenced: https://github.com/wuye9036/CppTemplateTutorial
//Part 2.2 Remove Pointer.

template<typename T>
class TypeToId
{
public:
	static const int id = 0;
};

template<>
class TypeToId<float>
{
public:
	static const int id = 1;
};

template<typename T>
class TypeToId<T*>
{
public:
	typedef T	SameAsT;
	static const int id = 2;
};

template<typename T>
class RemovePointer
{

};

template<typename T>
class RemovePointer<T*>
{
public:
	typedef typename RemovePointer<T>::Tesult Tesult;
};

int main()
{
	RemovePointer<int**>::Tesult x;
	auto testType = x;
}