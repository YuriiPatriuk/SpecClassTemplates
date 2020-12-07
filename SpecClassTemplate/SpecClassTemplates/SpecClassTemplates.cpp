#include <iostream>
#include <utility>
#include <tuple>
#include <string>
#include "Pair.h"
#include "Array.h"
#include "Student.h"
using namespace std;

int main()
{
    /*pair<int, string> p{ 5,"five" };
    cout << p.first << "\t" << p.second << endl;
    p.first = 100;
    cout << p.first << "\t" << p.second << endl;

    tuple<int, string, double> t( 1,"Apple", 199.54 );
    cout << get<0>(t) << endl;*/
   /* cout << get<1>(t) << endl;
    cout << get<2>(t) << endl;

    get<2>(t)++;
    cout << get<2>(t) << endl;
    
    int i;
    string s;
    double d;
    tie(i,s,d) = t;
    cout << i << " " << s << " " << d << endl;
    cout << endl;
    auto t2 = tie(++i,s,d);
    cout << get<0>(t2) << endl;
    cout << get<1>(t2) << endl;
    cout << get<2>(t2) << endl;*/

    /*initializer_list<int> list = { 11, 2, -34, -23 };
    cout << typeid(list).name() << endl;
    cout <<"First: "<< *list.begin() << endl;
    cout <<"Last: "<< *(list.end()-1) << endl;
    
    double sum = 0;
    for (size_t i = 0; i < list.size(); i++)
    {
        sum += *(list.begin() + i);
        cout << *(list.begin()+i) << endl;
    }
    cout << "Sum: " << sum << endl;

    const int SIZE = 4;
    int array[SIZE]{ 12,100,45,67 };
    cout << "Array: \n";
    for (int& elem : array)
    {
        cout << ++elem << "\t";
    }
    cout << endl;
    cout << array[0] << endl;

    for (auto & elem : list)
    {
        cout << elem << " _____ ";
    }

    auto result = func(list);
    cout << result.first << endl;
    cout << result.second << endl;

    Array arr(list);
    cout << "Array: \n";
    arr.print();*/


    tuple<const char*, std::initializer_list<size_t>, Student::Gender> t("Yura", {5,6,11,11,7,8},Student::Gender::MALE);
    Student student(t);
    student.print();

}
