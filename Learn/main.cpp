#include <iostream>
#include <initializer_list>


template<typename T>
class Test
{
public:
	T a;
public:
	friend const std::ostream& operator<<(const std::ostream& os, const Test& test)
	{
		os << a << std::endl;
		return os;
	}
};

template<typename T>
void processUndefinedLengthParam(const std::initializer_list<T>& params)
{
	for (auto element : params)
	{
		std::cout << element << std::endl;
	}
}

int main()
{

	Test<int> te1;
	te1.a = 10;

	Test<int> te2;
	te2.a = 10;

	processUndefinedLengthParam<Test>(te1, te2);
}