#pragma once
#include <iostream>

class DoubleArray
{
private:
	int m_size;
	double* m_arr;

	/*
	* @brief Делает копию объекта
	* @param obj - объект, от которого будем делать копию
	*/
	void Copy(const DoubleArray& obj);
public:

	/*
	* @brief Конструктор по умолчанию
	*/
	DoubleArray();

	/*
	* @brief Конструктор с параметрами
	* @param size - размер массива (по умолчанию равен 0)
	* @param arr - массив элементов типа double (по умолчанию равен nullptr)
	*/
	DoubleArray(int size, double* arr);

	/*
	* @brief Конструктор с параметрами
	* @param obj - контейнер типа DoubleArray
	*/
	DoubleArray(const DoubleArray& obj);

	/*
	* @brief Деструктор
	*/
	~DoubleArray();

	/*
	* @brief Перегрузка оператора = (присваивание)
	* @param obj - объект, от которого будем делать присваивание
	*/
	DoubleArray& operator=(const DoubleArray& obj);

	/*
	* @brief Перегрузка оператора + - к каждому элементу массива прибавляет константу
	* @param number_ - число-слагаемое
	* @return Копия массива с увеличенными значениями на number_
	*/
	DoubleArray operator+ (double number_);

	/*
	* @brief Перегрузка оператора - - из каждого элемента массива вычитаем константу
	* @param number_ - число-вычитаемое
	* @return Копия массива с уменьшенными значениями на number_

	*/
	DoubleArray operator- (double number_);

	/*
	* @brief Перегрузка оператора * - каждый элемент массива умножаем на константу
	* @param number_ - число-множитель
	* @return Копия массива с увеличенными значениями в number_
	*/
	DoubleArray operator* (double number_);

	/*
	* @brief Перегрузка оператора / - каждый элемент массива делим на константу
	* @param number_ - число-делитель
	* @return Копия массива с уменьшенными значениями в number_
	*/
	DoubleArray operator/ (double number_);


	//Capacity

	/*
	* @brief Функция, которая проверяет, пустой ли контейнер
	* @return true или false в зависимости от результата
	*/
	bool IsEmpty() const;

	/*
	* @brief Функция, которая возвращает размер контейнера
	* @return size - целое число (размер)
	*/
	int Size() const;

	//Access (возвращает указатель)

	/*
	* @brief Возвращает указатель на элемент массива по индексу
	* @param index_ - номер элемента массива
	* @return Элемент массива по номеру
	*/
	double& At(int index_) const;

	/*
	* @brief Возвращает указатель на элемент массива по индексу
	* @return Первый элемент массива
	*/
	double& Front() const;

	/*
	* @brief Возвращает указатель на элемент массива по индексу
	* @return Последний элемент массива
	*/
	double& Back() const;

	/*
	* @brief Возвращает указатель на элемент массива по индексу
	* @param index_ - номер элемента массива
	* @return Элемент массива по номеру
	*/
	double& operator[] (int index_) const;

	//Modifiers

	/*
	* @brief Очищает контейнер
	*/
	void Clear();

	/*
	* @brief Вставляет элемент на выбранную позицию в массиве
	* @param num_ - число, которое будет вставленно
	* @param index_ - индекс
	*/
	void Insert(double num_, int index_);

	/*
	* @brief Удаляет элемент или диапазон из массива
	* @param firstIndex_ - начало диапазона
	* @param lastIndex_ - конец диапазона
	*/
	void Erase(const int& firstIndex_, const int& lastIndex_);

	/*
	* @brief Вставляет элемент в конец массива
	* @param num_ - число, которое будет вставлено
	*/
	void Push_back(const double& num_);

	/*
	* @brief Изменяет размер массива (если больше, то дополняет нулями, иначе удаляет лишнее)
	* @param size_ - новый размер
	*/
	void Resize(const int& size_);

	/*
	* Оператор вывода. Выводит в формате [элементы через пробел]
	* @param stream - поток вывода
	* @param obj - массив, которой нужно вывести
	* @return Ссылка на поток вывода
	*/
	friend std::ostream& operator<<(std::ostream& stream, const DoubleArray& obj);

	/*
	* Оператор ввода. Вводит в формате [элементы через пробел]
	* @param stream - поток ввода
	* @param obj - массив, в который записываются введеные значения
	* @return Ссылка на поток ввода
	*/
	friend std::istream& operator>>(std::istream& stream, DoubleArray& obj);
};
