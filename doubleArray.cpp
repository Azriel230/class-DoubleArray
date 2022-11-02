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
		true;
	else
		false;
}

int DoubleArray::Size() const
{
	return m_size;
}

double* DoubleArray::At(unsigned const int& index_) const
{
	if ((index_ >= m_size) || (index_ < 0))
		throw "Out of range array";
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
		throw "Out of range array";
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
	{
		std::cout << "ERROR! Out of range array!" << std::endl;
		return;
	}
		//throw "Out of range array";

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
	{
		std::cout << "ERROR! Out of range array!" << std::endl;
		return;
	}

	int indexSize = lastIndex_ - firstIndex_ + 1;
	int newSize = m_size - indexSize;

	double* arr = new double[newSize];
	int n = 0;
	for (int i = 0; i < firstIndex_; i++)
	{
		arr[n] == m_arr[i];
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
	{
		std::cout << "The entered size is equal to the original size";
		return;
	}
	
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
	// TODO: вставьте здесь оператор return
}

std::istream& operator>>(std::istream& stream, DoubleArray& obj)
{
	// TODO: вставьте здесь оператор return
}
