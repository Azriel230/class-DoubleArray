#include "DoubleArray.h"
#include <iostream>
#include "DAException.h"

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

void DoubleArray::operator+ (const double& number_)
{
	for (int i = 0; i < m_size; i++)
		m_arr[i] += number_;
}

void DoubleArray::operator- (const double& number_)
{
	for (int i = 0; i < m_size; i++)
		m_arr[i] -= number_;
}

void DoubleArray::operator* (const double& number_)
{
	for (int i = 0; i < m_size; i++)
		m_arr[i] *= number_;
}

void DoubleArray::operator/ (const double& number_)
{
	for (int i = 0; i < m_size; i++)
		m_arr[i] /= number_;
}

bool DoubleArray::IsEmpty() const
{
	if (m_size == 0)
		return true;
	else
		return false;
}

int DoubleArray::Size() const
{
	return m_size;
}

double* DoubleArray::At(unsigned const int& index_) const
{
	if ((index_ >= m_size) || (index_ < 0))
		throw(DAException("Error! Out of range!", *this));
	return &m_arr[index_];
}

double* DoubleArray::Front() const
{
	return &m_arr[0];
}

double* DoubleArray::Back() const
{
	return &m_arr[m_size - 1];
}

double& DoubleArray::operator[] (unsigned const int& index_) const
{
	if ((index_ >= m_size) || (index_ < 0))
		throw(DAException("Error! Out of range!", *this));

	return m_arr[index_];
}

void DoubleArray::Clear()
{
	if (m_arr != nullptr)
	{
		m_size = 0;
		delete[] m_arr;
		m_arr = nullptr;
	}
}

void DoubleArray::Insert(const double& num_, const int& index_)
{
	if ((index_ >= m_size) || (index_ < 0))
		throw(DAException("Error! Out of range!", *this));

	m_size++;
	double* arr = new double[m_size];

	for (int i = 0; i < index_; i++)
		arr[i] = m_arr[i];

	arr[index_] = num_;

	for (int i = index_ + 1; i < m_size; i++)
		arr[i] = m_arr[i - 1];

	delete[] m_arr;
	m_arr = new double[m_size];

	for (int i = 0; i < m_size; i++)
		m_arr[i] = arr[i];

	delete[] arr;
}

void DoubleArray::Erase(const int& firstIndex_, const int& lastIndex_)
{
	if ((firstIndex_ >= m_size) || (firstIndex_ < 0) || (lastIndex_ < 0) || (firstIndex_ > lastIndex_))
		throw(DAException("Error! Out of range!", *this));

	int indexSize = lastIndex_ - firstIndex_ + 1;
	int newSize = m_size - indexSize;

	double* arr = new double[newSize];
	int n = 0;
	for (int i = 0; i < firstIndex_; i++)
	{
		arr[n] = m_arr[i];
		n++;
	}

	for (int i = lastIndex_ + 1; i < m_size; i++)
	{
		arr[n] = m_arr[i];
		n++;
	}

	m_size = newSize;
	delete[]m_arr;
	m_arr = new double[m_size];

	for (int i = 0; i < m_size; i++)
		m_arr[i] = arr[i];

	delete[]arr;
}

void DoubleArray::Push_back(const double& num_)
{
	Insert(num_, m_size);
}

void DoubleArray::Resize(const int& size_)
{
	if (size_ == m_size)
		return;

	if (size_ > m_size)
	{
		double* arr = new double[size_];

		for (int i = 0; i < m_size; i++)
			arr[i] = m_arr[i];

		for (int i = m_size; i < size_; i++)
			arr[i] = 0;

		m_size = size_;
		delete[] m_arr;
		m_arr = new double[m_size];

		for (int i = 0; i < m_size; i++)
			m_arr[i] = arr[i];

		delete[]arr;
	}
	else
	{
		m_size = size_;
		double* arr = new double[m_size];

		for (int i = 0; i < m_size; i++)
			arr[i] = m_arr[i];

		delete[]m_arr;
		m_arr = new double[m_size];

		for (int i = 0; i < m_size; i++)
			m_arr[i] = arr[i];

		delete[] arr;
	}
}

std::ostream& operator<<(std::ostream& stream, const DoubleArray& obj)
{
	stream << '[';
	for (int i = 0; i < obj.m_size; i++)
	{
		stream << obj[i];
		if (i < obj.m_size - 1)
			stream << ' ';
	}
	stream << ']';
	return stream;
}

std::istream& operator>>(std::istream& stream, DoubleArray& obj)
{
	while (stream.peek() == ' ')
		stream.ignore();
	if (stream.peek() != '(')
		throw(DAException("Array input error (array must start with (", obj));
	stream.ignore();
	if (stream.peek() == ')')
	{
		stream.ignore();
		obj.Clear();
		return stream;
	}
	obj.Clear();
	int size = 0;
	stream >> size;
	if (stream.fail())
		throw(DAException("It was not a number that was entered", obj));
	obj.m_size = size;
	if (stream.peek() != ':')
		throw(DAException("After entered size of arr it was not introduced :", obj));
	else
		stream.ignore();
	obj.m_arr = new double[obj.m_size];
	double data = 0;
	int i = 0;
	while (stream.peek() != EOF)
	{
		stream >> data;
		if (stream.fail())
			throw(DAException("It was not a number that was entered", obj));
		obj.m_arr[i] = data;

		if (stream.peek() == ')')
		{
			stream.ignore();
			return stream;
		}
		if (stream.peek() != ',')
			throw(DAException("the elements were not introduced through ,", obj));
		else
			stream.ignore();
		i++;
	}
}
