/*
	7.	 ����� ��������� � KSet
				   ������:
						 ������������, ����������;
						 ��������: [], =, ==, !=,
							+, +=    - ����������� ��������,
	*, *=     - ����������� ��������,
	/,  /=      - �������� ��������,
	�, �=     - �������������� �������� ��������: A-B = (A/B)+(B/A),
	<, <=, >, >=   - ���������
	<<, >>,
	[]       - v[A] - ������������ ������������ ��������� v, ����� ��� v[A] <= A; ���� A �����   ��� �������� ���������, �� ��������������� �������������� ��������� {A};
   v[A] = B  - �������� � v ������������ v[A] �� B;
		   �������:
		Size()  - ���������� ��������� ���������,
		Clear() � ������� ��� �������� ���������,
	Swap()  - �������� �������� (�.�. ���������).
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
