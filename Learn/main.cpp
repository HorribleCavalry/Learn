#include <iostream>

template<typename T>
T Add(const T& a, const T& b)
{
	return a + b;
}

template<typename T>
class vector
{
private:
	T* element;
public:
	void push_back(T const&);
	void clear();
};
template<typename T>
inline void vector<T>::push_back(T const &)
{
}
int main()
{
	
	std::cout << "Hello world!";
}