#include <iostream>
#include <stdexcept>
#include <string>

class Sales
{
public:
	enum {MONTHS = 12};

	class bad_index : public std::logic_error
	{
	private:
		int bi;//bad idx value
	public:
		explicit bad_index(int ix, const std::string& s = "Index error in Sales object\n");
		int bi_val() const { return bi; }
		//I think this way of writing is equal to bottom
		//virtual ~bad_index()noexcept {}
		virtual ~bad_index()noexcept {}
	};
};

struct Big
{
	double stuff[20000];
};

int main()
{
	Big* pb = nullptr;
	try
	{
		pb = new Big[1000];
	}
	catch (const std::exception& e)
	{
		e.what();
		exit(EXIT_FAILURE);
	}
	if (pb)
		delete[] pb;
	exit(EXIT_SUCCESS);

}
