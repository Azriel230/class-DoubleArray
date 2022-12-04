#include "DoubleArray.h"
#include <iostream>
#include "DAException.h"

int main()
{
	try
	{
		DoubleArray mas1;
		std::cin >> mas1;
		std::cout << std::endl << mas1;
	}
	catch (DAException obj)
	{
		std::cout << obj;
	}

	return 0;
}
