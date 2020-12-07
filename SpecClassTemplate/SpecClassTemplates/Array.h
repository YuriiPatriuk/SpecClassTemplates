#pragma once

class Array
{
public:
	Array(size_t size , int filler );
	Array(size_t size);
	Array() = default;
	Array(const Array& other); // COPY CTOR
	Array(Array&& other);// MOVE CTOR
	
	Array(std::initializer_list<int>& list);
	
	Array& operator = (const Array& other); // assign with copy
	Array& operator = (Array && other); //assign with MOVING

	Array operator + (const Array& other)const;
	int & operator [] (int index);
	void print() const;
	Array & operator ++();//  prefix
	Array operator ++(int);// postfix
	~Array();
private:
	bool isValidIndex(size_t index) const;
	size_t size = 0;
	int* array = nullptr;
};
inline bool Array::isValidIndex(size_t index) const
{
	return index < size;
}
// Array : operator cast to int : суму елементів масиву
// Array : operator ()(int index, int  howMany) : повертати Array, який є фрагменом this
// 

inline Array::Array(std::initializer_list<int>& list)
{
	array = new int[size = list.size()];
	for (size_t i = 0; i < size; i++)
	{
		array[i] = *(list.begin() + i);
	}
}
