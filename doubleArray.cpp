#include "doubleArray.h";
#include <iostream>

int MaxArraySize(int size_arr1_, int size_arr2_)
{
	if (size_arr1_ < size_arr2_)
		return size_arr2_;
	else
		return size_arr1_;
}

int MinArraySize(int size_arr1_, int size_arr2_)
{
	if (size_arr1_ > size_arr2_)
		return size_arr2_;
	else
		return size_arr1_;
}

void DoubleArray::operator+ (const double number_)
{
	for (int i = 0; i < m_size; i++)
		m_arr[i] += number_;
}

void DoubleArray::operator- (const double number_)
{
	for (int i = 0; i < m_size; i++)
		m_arr[i] -= number_;
}

void DoubleArray::operator* (const double number_)
{
	for (int i = 0; i < m_size; i++)
		m_arr[i] *= number_;
}

void DoubleArray::operator/ (const double number_)
{
	for (int i = 0; i < m_size; i++)
		m_arr[i] /= number_;
}

bool DoubleArray::IsEmpty() const
{
	if (m_size == 0)
		true;
	else
		false;
}

int DoubleArray::Size() const
{
	return m_size;
}
