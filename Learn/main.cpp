#include <iostream>
#include <cassert>
//Referenced: https://github.com/wuye9036/CppTemplateTutorial
//

template<typename T>
struct X
{

};

template<typename T>
struct Y
{
	typedef X<T> ReboundType;
	//typename is used for identifing the back "MemberType" is a type instead of a variable.
	typedef typename X<T>::MemberType MemberType2;
	//typedef UnknownType MemberType3;
};

int main()
{

}