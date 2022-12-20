#include "DoubleArray.h"
#include <iostream>
#include "DAException.h"

DoubleArray::DoubleArray()
{
	m_size = 0;
	m_arr = nullptr;
}

DoubleArray::DoubleArray(int size, double* arr)
{
	m_size = size;
	m_arr = new double[m_size];

	for (int i = 0; i < m_size; i++)
		m_arr[i] = arr[i];
}

DoubleArray::DoubleArray(const DoubleArray& obj)
{
	Copy(obj);
}

DoubleArray::~DoubleArray()
{
	delete[] m_arr;
}

void DoubleArray::Copy(const DoubleArray& obj)
{
	if (obj.m_size == 0 || obj.m_arr == nullptr)
	{
		m_size = 0;
		m_arr = nullptr;
		return;
	}

	m_size = obj.m_size;
	m_arr = new double[m_size];

	for (int i = 0; i < m_size; i++)
		m_arr[i] = obj.m_arr[i];
}

DoubleArray& DoubleArray::operator=(const DoubleArray& obj)
{
	if (this == &obj)
		return *this;

	Clear();
	Copy(obj);

	return *this;
}

DoubleArray DoubleArray::operator+ (double number_)
{
	DoubleArray tempArr(*this);

	for (int i = 0; i < m_size; i++)
		tempArr.m_arr[i] += number_;
	
	return tempArr;
}

DoubleArray DoubleArray::operator- (double number_)
{
	DoubleArray tempArr(*this);

	for (int i = 0; i < m_size; i++)
		tempArr.m_arr[i] -= number_;

	return tempArr;
}

DoubleArray DoubleArray::operator* (double number_)
{
	DoubleArray tempArr(*this);

	for (int i = 0; i < m_size; i++)
		tempArr.m_arr[i] *= number_;

	return tempArr;
}

DoubleArray DoubleArray::operator/ (double number_)
{
	DoubleArray tempArr(*this);

	for (int i = 0; i < m_size; i++)
		tempArr.m_arr[i] /= number_;

	return tempArr;
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

double& DoubleArray::At(int index_) const
{
	if ((index_ >= m_size) || (index_ < 0))
		throw(DAException("Error! Out of range!", *this));
	return m_arr[index_];
}

double& DoubleArray::Front() const
{
	return m_arr[0];
}

double& DoubleArray::Back() const
{
	return m_arr[m_size - 1];
}

double& DoubleArray::operator[] (int index_) const
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

void DoubleArray::Insert(double num_, int index_)
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
	m_size;
	double* arr = new double[m_size+1];

	for (int i = 0; i < m_size; i++)
		arr[i] = m_arr[i];

	arr[m_size] = num_;

	++m_size;
	delete[] m_arr;
	m_arr = new double[m_size];

	for (int i = 0; i < m_size; i++)
		m_arr[i] = arr[i];

	delete[] arr;
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
	double buffarr[1024];

	while (stream.peek() == ' ')
		stream.ignore();
	if (stream.peek() != '[')
		throw(DAException("Array input error (array must start with [ )", obj));
	stream.ignore();
	if (stream.peek() == ']')
	{
		stream.ignore();
		obj.Clear();
		return stream;
	}

	double data = 0;
	int i = 0;

	while (stream.peek() != EOF)
	{
		stream >> data;
		if (stream.fail())
			throw(DAException("It was not a number that was entered", obj));
		buffarr[i] = data;

		if (stream.peek() == ']')
		{
			stream.ignore();

			obj.Clear();

			obj.m_size = i + 1;
			obj.m_arr = new double[obj.m_size];

			for (i = 0; i < obj.m_size; i++)
				obj.m_arr[i] = buffarr[i];

			return stream;
		}
		if (stream.peek() != ' ')
			throw(DAException("the elements were not introduced through ' '", obj));
		else
			stream.ignore();
		i++;
	}
}
