#pragma once
#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <sstream> 
#include <functional>

// task 1

void outputList(std::list<int>& _list)
{
	std::for_each(_list.begin(), _list.end(), [](int item) {std::cout << item << " "; });
	std::cout << std::endl;
}

void sortList(std::list<int>& _list)
{
	_list.sort([](int a, int b) { return std::abs(a) < std::abs(b);});
}

const std::list<int>::const_iterator firstEven(std::list<int>& _list)
{
	return find_if(_list.begin(), _list.end(), [](int item) { return (!(item % 2));  });
}

int countEven(std::list<int>& _list)
{
	int counter = 0;
	std::for_each(_list.begin(), _list.end(), [&counter](int item) { if (!(item % 2)) counter++; });
	return counter;
}

void replaceNegativeNumbers(std::list<int>& _list)
{
	for_each(_list.begin(), _list.end(), [](int& item) { if (item < 0) item = 0; });
}

// task 2  


template<typename... ArgumentTypes>
double FSums(ArgumentTypes... args);

template<class T> double FSums(T temp) { return temp; }

template<typename T, typename... ArgumentTypes>
double FSums(T temp, ArgumentTypes... args)
{
	auto lambdaFSums = [](ArgumentTypes... args)
	{
		return FSums<double>(args...);
	};
	return lambdaFSums(args...) + temp;
}


/* task 2 1


template<typename... T>
void ignore(T ...) { ; }

template<typename... T>
double CalcSum(T... args)
{
	double sum = 0;
	ignore(sum += args ...);
	return sum;
}
*/

// task 3

template<typename... ArgumentTypes>
std::string ToStr(std::string seps, ArgumentTypes... args);

template<typename T, typename... ArgumentTypes>
std::string ToStr(std::string seps, T temp1, ArgumentTypes... args)
{
	std::stringstream str;
	str << temp1 << seps;
	str << ToStr(seps, args...);
	return str.str();
}

template<> std::string ToStr(std::string seps) { return ""; }

template<typename T, typename... ArgumentTypes>
std::string ToString(std::string seps, T temp1, ArgumentTypes... args)
{
	std::string str;
	auto lambda = [&]() {str = ToStr(seps, temp1, args...); };
	lambda();
	str.pop_back();
	return str;
}