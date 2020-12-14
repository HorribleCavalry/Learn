#ifndef __ALLOCATOR__
#define __ALLOCATOR__

#include <new>
#include <cstddef>
#include <cstdlib>
#include <climits>
#include <iostream>

namespace CAVSTD
{

	template<typename T>
	inline T* _allocate(ptrdiff_t size, T*)
	{
		std::set_new_handler(nullptr);
		T* temp = (T*)(::operator new((size_t)(size * sizeof(T))));

		if (!temp)
		{
			std::cerr << "out of memory" << std::endl;
			exit(1);
		}
		return temp;
	}

	template <typename T>
	class allocator
	{
	public:
		typedef T value_type;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef T& reference;
		typedef const T& const_reference;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;

		template<typename U>
		struct rebind
		{
			typedef allocator<U> other;
		};

		pointer allocate(size_type n, const void* hint = nullptr)
		{
			return _allocate((difference_type)n, (pointer)nullptr);
		}

		void deallocate(pointer p, size_type n) {}

	public:
		//allocator();
		//~allocator();

	private:

	};

}

#endif // __ALLOCATOR__
