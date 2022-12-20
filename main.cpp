#include "DoubleArray.h"
#include <iostream>
#include "DAException.h"

int main()
{
	try
	{
		double arr[3] = { 1, 2, 3 };
		DoubleArray mas1(3, arr);
		std::cout << "mas1: " << mas1 << std::endl;
		std::cout << std::endl;
		std::cout << "mas2: " << mas1 + 3 << std::endl;
		std::cout << "mas2: " << mas1 - 3 << std::endl;
		std::cout << "mas2: " << mas1 * 3 << std::endl;
		std::cout << "mas2: " << mas1 / 3 << std::endl;
		std::cout << std::endl;
		std::cout << mas1.IsEmpty() << std::endl;
		std::cout << mas1.Size() << std::endl;
		std::cout << std::endl;
		std::cout << mas1.At(1) << std::endl;
		std::cout << mas1.Front() << std::endl;
		std::cout << mas1.Back() << std::endl;
		std::cout << mas1[1] << std::endl;
		std::cout << std::endl;
		mas1.Insert(7, 1);
		std::cout << mas1 << std::endl;
		mas1.Erase(1, 1);
		std::cout << mas1 << std::endl;
		mas1.Push_back(4);
		std::cout << mas1 << std::endl;
		mas1.Resize(10);
		std::cout << mas1 << std::endl;
		mas1.Resize(2);
		std::cout << mas1 << std::endl;
	}
	catch (DAException obj)
	{
		std::cout << obj;
	}

	return 0;
}
