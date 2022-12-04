#pragma once
#include <iostream>

class DoubleArray
{
private:
	int m_size;
	double* m_arr;

public:
	DoubleArray(int size = 0, double* arr = nullptr)
	{
		m_size = size;
		m_arr = new double[m_size];

		for (int i = 0; i < m_size; i++)
			m_arr[i] = arr[i];
	}

	~DoubleArray()
	{
		delete[] m_arr;
	}


	void operator+ (const double& number_);
	void operator- (const double& number_);
	void operator* (const double& number_);
	void operator/ (const double& number_);


	//Capacity

	bool IsEmpty() const;
	int Size() const;

	//Access (возвращает указатель)

	double* At(unsigned const int& index_) const;
	double* Front() const;
	double* Back() const;
	double& operator[] (unsigned const int& index_) const;

	//Modifiers

	void Clear();
	void Insert(const double& num_, const int& index_);
	void Erase(const int& firstIndex_, const int& lastIndex_);
	void Push_back(const double& num_);
	void Resize(const int& size_);

	friend std::ostream& operator<<(std::ostream& stream, const DoubleArray& obj);
	friend std::istream& operator>>(std::istream& stream, DoubleArray& obj);
};
