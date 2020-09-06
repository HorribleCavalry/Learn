#include <iostream>
#include <cassert>
#include <complex>
#include <type_traits>
//Referenced: https://github.com/wuye9036/CppTemplateTutorial
//

#define Uint unsigned int
#define Float double
#define Int int



template<typename T, typename... Ts>
class Person
{
};

template<>
class Person<int>
{

};

template<>
class Person<float>
{

};

template<typename U>
class Person<U*>
{
public:
	U test;
};

template<typename T>
T DustomDivide(const T& a, const T& b)
{
	T v;
	return v;
}

template<typename T, typename Enable = std::true_type>
struct SafeDivide
{
	static void Do(const T&a, const T& b)
	{
		std::cout << "Called another!\n";
	}
};

template<typename T>
struct SafeDivide<T,typename std::is_floating_point<T>::type>
{
	static T Do(const T a, const T b)
	{
		std::cout << "Called float\n";
		return a / b;
	}
};

template<typename T>
struct SafeDivide<T, typename std::is_integral<T>::type>
{
	static T Do(const T a, const T b)
	{
		std::cout << "Called int\n";
		//assert(b != 0);
		return a / b;
	}
};

//template<typename T>
//class vec2
//{
//public:
//	template<typename U, typename Enabled0 = std::true_type, typename Enabled1 = std::true_type>
//	static void call(const vec2<U>& rhs)
//	{
//		std::cout<<"In mother called.\n"
//	}
//
//	template<typename U>
//	static void call<U, typename std::is_floating_point<T>, typename std::is_integral<U>>(const vec2<U>& rhs)
//	{
//
//	}
//};

//template<typename T>
//void vec2<T>::call()

class creation
{
public:
	creation(unsigned long _id) : id(_id) {}
	unsigned long id;
	static const creation human;
};
const creation creation::human(1);

template<typename T>
class vec4
{
public:
	T x, y, z, w;
public:
	vec4(T _x, T _y, T _z, T _w)
		:x(_x), y(_y), z(_z), w(_w)
	{
	}
public:
	vec4() : vec4(0, 0, 0, 0) {}
	vec4(const vec4& v) : vec4(v.x, v.y, v.z, v.w) {}
	vec4(vec4&& v) : vec4(v) {}
};

template<typename T>
class Mat4x4
{
public:
	T m[4][4];
public:
	Mat4x4()
	{
		for (Uint i = 0; i < 4; i++)
		{
			for (Uint j = 0; j < 4; j++)
			{
				m[i][j] = i == j ? 1 : 0;
			}
		}
	}
	Mat4x4<T>(const Mat4x4<T>& mat)
	{
		for (Uint i = 0; i < 4; i++)
		{
			for (Uint j = 0; j < 4; j++)
			{
				m[i][j] = mat.m[i][j];
			}
		}
	}
	Mat4x4(Mat4x4&& mat)
	{
		for (Uint i = 0; i < 4; i++)
		{
			for (Uint j = 0; j < 4; j++)
			{
				m[i][j] = mat.m[i][j];
			}
		}
	}
	const Mat4x4& operator=(const Mat4x4& mat)
	{
		for (Uint i = 0; i < 4; i++)
		{
			for (Uint j = 0; j < 4; j++)
			{
				m[i][j] = mat.m[i][j];
			}
		}
	}
	const Mat4x4& operator=(Mat4x4&& mat)
	{
		for (Uint i = 0; i < 4; i++)
		{
			for (Uint j = 0; j < 4; j++)
			{
				m[i][j] = mat.m[i][j];
			}
		}
	}
	~Mat4x4() {}

public:

	template<typename U>
	Mat4x4(const Mat4x4<U>& mat)
	{

	}

	//Mat4x4<Float>(Mat4x4<Int>& mat)<Float>
	//{
	//	for (Uint i = 0; i < 4; i++)
	//	{
	//		for (Uint j = 0; j < 4; j++)
	//		{
	//			m[i][j] = mat.m[i][j];
	//		}
	//	}
	//}

	//template<>
	//explicit Mat4x4<Int>operator=(const Mat4x4<Float>& mat)<Int>
	//{
	//	for (Uint i = 0; i < 4; i++)
	//	{
	//		for (Uint j = 0; j < 4; j++)
	//		{
	//			m[i][j] = mat.m[i][j];
	//		}
	//	}
	//}

public:
	Mat4x4(
		T m00, T m01, T m02, T m03,
		T m10, T m11, T m12, T m13,
		T m20, T m21, T m22, T m23,
		T m30, T m31, T m32, T m33
	)
		//:
		//m[0][0](m00), m[0][1](m01), m[0][2](m02), m[0][3](m03),
		//m[1][0](m10), m[1][1](m11), m[1][2](m12), m[1][3](m13),
		//m[2][0](m20), m[2][1](m21), m[2][2](m22), m[2][3](m23),
		//m[3][0](m30), m[3][1](m31), m[3][2](m32), m[3][3](m33)
	{
		m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
		m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
		m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
		m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
	}
public:
	vec4<T>&& Row(Uint idx) const
	{
		//CHECK(idx >= 0 && idx <= 3, "Mat4x4::Row(idx): idx is out of range!");
		switch (idx)
		{
		case 0: return vec4<T>(m[0][0], m[0][1], m[0][2], m[0][3]); break;
		case 1: return vec4<T>(m[1][0], m[1][1], m[1][2], m[1][3]); break;
		case 2: return vec4<T>(m[2][0], m[2][1], m[2][2], m[2][3]); break;
		case 3: return vec4<T>(m[3][0], m[3][1], m[3][2], m[3][3]); break;
		default:
			//CHECK(false, "It can not run Mat4x4::Row(), called switch::default");
			break;
		}
	}

	vec4<T>&& Column(Uint idx) const
	{
		//CHECK(idx >= 0 && idx <= 3, "Mat4x4::Column(idx): idx is out of range!");
		switch (idx)
		{
		case 0: return vec4<T>(m[0][0], m[1][0], m[2][0], m[3][0]); break;
		case 1: return vec4<T>(m[0][1], m[1][1], m[2][1], m[3][1]); break;
		case 2: return vec4<T>(m[0][2], m[1][2], m[2][2], m[3][2]); break;
		case 3: return vec4<T>(m[0][3], m[1][3], m[2][3], m[3][3]); break;
		default:
			//CHECK(false, "It can not run Mat4x4::Column(), called switch::default");
			break;
		}
	}

	Mat4x4& transpose()
	{
		Float temp;
		for (Uint i = 0; i < 4; i++)
		{
			for (Uint j = i + 1; j < 4; i++)
			{
				temp = m[i][j];
				m[i][j] = m[j][i];
				m[j][i] = temp;
			}
		}

		return *this;
	}

public:


public:
	//__device__  static const Mat4x4 identiy;
};

//Mat4x4<Float>::Mat4x4<Float>(const Mat4x4<Int>& mat)
//{
//
//}

template<typename T>
const Mat4x4<T> operator+(const Mat4x4<T>& mat0, const Mat4x4<T>& mat1)
{
	Mat4x4<T> result;
	for (Uint i = 0; i < 4; i++)
	{
		for (Uint j = 0; j < 4; j++)
		{
			result.m[i][j] = mat0.m[i][j] + mat0.m[i][j];
		}
	}
	return result;
}

int main()
{
	//std::is_integral

	Person<int> p0;
	Person<float> p1;
	Person<float*> p2;
	
	SafeDivide<int>::Do(1, 2);
	//SafeDivide<int>::Do(1, 0);
	SafeDivide<float>::Do(1.0, 2.0);

	SafeDivide<std::complex<float>>::Do({ 1.0f,2.0f }, { 1.0f,-2.0f });
	std::cout << creation::human.id;

	vec4<float> vl;
	vec4<float> v(vl);
	Mat4x4<Float> mt0;
	Mat4x4<Float> mt1;
	auto test = mt0 + mt1;
	//LogData(mt0 + mt1);
	//It can not work, I don't know why.
	//Person<int, int> p2;
}