#include <iostream>

//Referenced: https://github.com/wuye9036/CppTemplateTutorial

template<typename T, int Size>
class Array
{
public:

	T data[Size];
};

int main()
{
	Array<float, 32> arr;
	int x = 32;

	//This writting style is not allowed, because the "Size" must be determined in compile phase.
	//Array<int, x> arrX;
}