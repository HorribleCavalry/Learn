#include "exc_mean.h"
void bad_hmean::mesg()
{
	std::cout << "Called bad_hmean::mesg() now!" << std::endl;
}

const char * bad_gmean::mesg()
{
	return "Called bad_gmean::mesg()!";
}
