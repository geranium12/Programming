#include "MyException.h"
#include "ListWithIterator.h"
#include <iostream>

int main()
{
	/*
	std::cout << "List();" << std::endl;	
	List<int> list1;
	std::cout << list1 << " IsEmpty() " << list1.IsEmpty() << " Size() " << list1.Size() << std::endl;

	std::cout << "List<T>(const int _capacity);" << std::endl;
	List<int> list2(20);
	std::cout << list2 << " IsEmpty() " << list2.IsEmpty() << " Size() " << list2.Size() << std::endl;
	std::cout << "List<T>(const std::initializer_list<T> &list);" << std::endl;

	List<int> list3 = { 1, 2, 3, 4, 5 };
	std::cout << list3 << " IsEmpty() " << list3.IsEmpty() << " Size() " << list3.Size() << std::endl;
	std::cout << "List<T>(const List<T> &list);" << std::endl;

	List<int> list4(list3);
	std::cout << list4 << " IsEmpty() " << list4.IsEmpty() << " Size() " << list4.Size() << std::endl;
	//std::cout << "List<T>(List<T> &&list);" << std::endl;
	//List<int> list5(list3);
	//std::cout << list5 << " IsEmpty() " << list5.IsEmpty() << " Size() " << list5.Size() << std::endl;
	//std::cout << "LIST IS EMPTY? " << list3.IsEmpty() << std::endl;

	list3 = list2 = list1;

	List<int> a{ 1, 2, 3, 4 };
	List<int> b{ std::move(a) };
	std::cout << b << std::endl;
	std::cout << a << std::endl;

	//List<int> list3(10);
	//List<int> list1 = { 1, 2, 3, 4, 5 };
	//List<int> list2 = { 1, 2, 3 };
	List<int> list6(list2);
	
	std::cout << "list6 " << list6 << std::endl;
	std::cout << list3 << std::endl;
	std::cout << list3.IsEmpty() << " " << list3.Size() << std::endl;
	std::cout << list1 << std::endl;
	std::cout << (list1 == list2) << std::endl;
	list3 = list2 = list1;
	std::cout << (list1 != list2) << std::endl;
	// cout << list1 != list2 << std::endl;
	std::cout << list1.IsEmpty() << " " << list1.Size() << std::endl;
	list1.Clear();
	std::cout << list1 << " " << list1.IsEmpty() << " " << list1.Size() << std::endl;
	list3.Clear();
	//cout << list3.Back() << std::endl;
	list3.PushBack(6);
	list3.PushFront(7);
	list3.PopBack();
	list3.PopFront();
	//list3.PopBack();
	std::cout << list3 << std::endl;
	std::cout << "_________________" << std::endl;
	
	List<int> list4 = { 1, 2, 3, 4, 5 };
	List<int> list5 = { 1, 2, 3 };
	std::cout << list4 << std::endl << list5 << std::endl;
	Swap(list4, list5);
	std::cout << list4 << std::endl << list5 << std::endl;
	*/
	
	List<int> list7 = { 1, 5, 3, 4 };
	List<int> list8 = { 1, 2 };

	std::cout << list7 << std::endl;
	std::cout << list8 << std::endl;
	std::cout << list7 + list8 << std::endl;
	list8 += list7;
	std::cout << list8 << std::endl;
	
	
	std::cin >> list7;
	std::cout << list7 << std::endl;
	
	for (auto element = --list8.end(); element != --list8.begin(); element--)
	{
		std::cout << *element << " ";
	}
	std::cout << std::endl;

	/*const List<double> list10 = { 1, 2, 3 };
	for (auto element = --list10.end(); element != --list10.begin(); element--)
	{
		std::cout << *element << " ";
	}
	*/
	system("pause");
	return 0;
}