#include <iostream>

//Referenced: https://github.com/wuye9036/CppTemplateTutorial

float data[1024];
template<typename T>
T GetValue(int i)
{
	return static_cast<T>(data[i]);
}

int main()
{
	//The compiler can not identify the type of return value, so it is not allowed.
	//float a = GetValue(0);
	//int b = Getvalue(1);

	float a = GetValue<float>(0);
	int b = GetValue<int>(1);
}