#include <iostream>
using std::cout;
using std::endl;
#include "Array.h"


Array::Array(size_t size, int filler)
{
	array = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		array[i] = filler;
	}
	this->size = size;
}

Array::Array(size_t size)
	: Array(size, 0)
{
}

Array::Array(const Array& other)
{
	*this = other;
}

Array::Array(Array&& other) // MOVE CTOR
{
	cout << "~~~~~~~~~~~~~ MOVE CTOR\n";
	this->array = other.array; 
	this->size = other.size;

	other.array = nullptr;
	other.size = 0;
}

Array& Array::operator=(const Array& other)
{
	if (this != &other)
	{
		if (array != nullptr)
		{
			delete[] array;
		}
		array = new int[size = other.size];
		for (size_t i = 0; i < size; i++)
		{
			array[i] = other.array[i];
		}
	}
	return *this;
}

Array& Array::operator=(Array&& other)
{
	cout << "~~~~~~~~~~~~~ MOVE =\n";

	if (this != &other)
	{
		if (this->array != nullptr)
			delete[] array;
		this->array = other.array;
		this->size = other.size;

		other.array = nullptr;
		other.size = 0;
	}
	return *this;
}

Array Array::operator+(const Array& other) const // this = left, other = right
{
	Array result(this->size + other.size);// 0 0 0 0 0 0 0 0 0 0
	size_t i;
	for ( i = 0; i < this->size; i++)
	{
		result.array[i] = array[i];
	}
	for (size_t j = 0; j < other.size; j++, ++i)// 1 1 1 1 1 0 0 0 0 0
	{
		result.array[i] = other.array[j];
	}
	return result;
}

int& Array::operator[](int index)
{
	static int error;// 0
	if (isValidIndex(index))
	{
		return array[index];
	}
	std::cerr << ">>>>>>>>>Error index : " << index << endl; // cerr = standard stream for errors
	return  error;
}

void Array::print() const
{
	cout << "Array : " << (size == 0 ? "empty" : "") << endl;
	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << "\t";
	}
	cout << endl;
}

Array& Array::operator++()
{
	for (size_t i = 0; i < size; i++)
	{
		++array[i];

	}
	return *this;
}

Array Array::operator++(int)
{
	Array old = *this; // скопіювали ЦЕЙ обєкт у old
	++* this; // виклик префіксної форми, тобто ++ для  кожного елемента
	return old; //повертаємо СТАРЕ значення
}

Array::~Array()
{
	if (array != nullptr) {
		delete[] array;
		array = nullptr;
	}
}
