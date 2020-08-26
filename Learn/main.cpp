#include <iostream>

//Referenced: https://github.com/wuye9036/CppTemplateTutorial

template<typename SrcT, typename DesT>
DesT c_style_cast(SrcT v)
{
	return static_cast<DesT>(v);
}

int main()
{
	int v = 0;
	float i = c_style_cast<int,float>(v);
}