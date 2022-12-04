#pragma once
#include <iostream>
#include "DoubleArray.h"

class DAException
{
	char m_message[128];
	DoubleArray m_err_obj;
public:
	DAException()
	{
		m_message[0] = '\0';
		m_err_obj = DoubleArray();
	}
	DAException(const char* error_message, const DoubleArray& arr_)
	{
		int i = 0;
		for (i; error_message[i] != '\0'; i++)
			m_message[i] = error_message[i];
		m_message[i] = '\0';

		m_err_obj = arr_;
	}
	~DAException() {};

	friend std::ostream& operator<<(std::ostream& stream, const DAException& obj);
};