#include <iostream>
#include "DAException.h"
#include "DoubleArray.h"

std::ostream& operator<<(std::ostream& stream, const DAException& obj)
{
	for (int i = 0; obj.m_message[i] != '\0'; i++)
		stream << obj.m_message[i];
	stream << std::endl;
	stream << "The object that caused the exception: ";

	return stream;
}