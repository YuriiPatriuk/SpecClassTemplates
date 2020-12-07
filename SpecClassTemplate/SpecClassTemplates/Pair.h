#pragma once
#include <iostream>
using namespace std;
//шаблон функції, яка отримує initializer_list<T>
//і повертає пару значень(максимальне та мінімальне)

template <typename T>
pair<T,T> func(std::initializer_list<T>& list)
{
	T max = *list.begin();
	T min = *list.begin();
	for (auto i : list)
	{
		if (i > max)
			max =  i;

		else if ( i < min)
			min =  i;
	}
	pair <T, T> p{ max,min };
	return p;
}