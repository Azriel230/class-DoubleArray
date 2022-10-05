class DoubleArray
{
private:
	int m_size;
	double* m_arr;

public:
	DoubleArray(int size = 0, double* arr = nullptr)
	{
		m_size = size;
		m_arr = new double[size];

		m_arr = arr;
	}

	~DoubleArray()
	{
		m_size = 0;
		delete[] m_arr;
	}


	void operator+ (const double number_);
	void operator- (const double number_);
	void operator* (const double number_);
	void operator/ (const double number_);


	//Capacity

	bool IsEmpty() const;

	int Size() const;

};
