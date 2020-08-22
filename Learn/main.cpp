#include "immintrin.h"
#include <iostream>
//Referenced web page: https://blog.csdn.net/sinat_26210035/article/details/88773961
void _mm256_print_epi32(__m256i p)
{
	int *p1 = (int*)&p;
	for (unsigned short i = 0; i < 7; i++)
	{
		std::cout << p[i];
	}
}

int main()
{
	__m256i a = _mm256_set_epi32(7, 6, 5, 4, 3, 2, 1);
	_mm256_print_epi32(a);
	__attribute__((aligned(32))) int d1[8] { -1, -2, -3, -4, -5, -6 ,-7,-8 };
	__m256i d = _mm256_load_si256((__m256i*)d1);
	_mm256_print_epi32(d);
	__mm256i d2 = _mm256_add_epi32(d, a);
	_mm256_print_epi32(d2);
}