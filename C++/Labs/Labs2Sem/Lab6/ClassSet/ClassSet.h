/*
	7.	  ласс множество Ц KSet
				   ћетоды:
						 конструкторы, деструктор;
						 операции: [], =, ==, !=,
							+, +=    - объединение множеств,
	*, *=     - пересечение множеств,
	/,  /=      - разность множеств,
	Ц, Ц=     - симметрическа€ разность множеств: A-B = (A/B)+(B/A),
	<, <=, >, >=   - включение
	<<, >>,
	[]       - v[A] - максимальное подмножество множества v, такое что v[A] <= A; если A имеет   тип элемента множества, то рассматриваетс€ одноэлементное множество {A};
   v[A] = B  - заменить в v подмножество v[A] на B;
		   функции:
		Size()  - количество элементов множества,
		Clear() Ц удалить все элементы множества,
	Swap()  - обмен€ть значени€ (т.е. множества).
*/
#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Set {
private:
	int* p;
	int size;
	void sort();
public:
	Set();
	Set(const Set& s);
	Set(int*, int);
	bool include(int);

	friend Set operator + (const Set &s1, const int n);
	friend Set operator - (const Set &s1, const int n);

	friend bool operator == (const Set&s1, const Set&s2);
	friend bool operator != (const Set&s1, const Set&s2);
	friend bool operator > (const Set&s1, const Set&s2);
	friend bool operator < (const Set&s1, const Set&s2);
	friend bool operator >= (const Set&s1, const Set&s2);
	friend bool operator <= (const Set&s1, const Set&s2);

	Set operator * (const Set&s1);
	Set operator + (const Set&s1);
	Set operator - (const Set&s1);

	Set& operator += (const int);
	Set& operator -= (const int);

	Set& operator *= (const Set&s1);
	Set& operator += (const Set&s1);
	Set& operator -= (const Set&s1);

	friend ostream& operator << (ostream &out, const Set &s);
	friend istream& operator >> (istream &in, Set &s);
};
