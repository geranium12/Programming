#include "Library.h"

int main()
{
	std::list<int> container = { -3, 1, 2, 4, -9, 5, 7, 8, 10, -6 };
	
	// task 1

	std::cout << "Output : " << std::endl;
	outputList(container);

	std::cout << "Sort : " << std::endl;
	sortList(container);
	outputList(container);

	const std::list<int>::const_iterator value = firstEven(container);
	if (value != container.end())
	{
		std::cout << "The first even number is " << *value << std::endl;
	}
	else
	{
		std::cout << "The list does not contain even numbers!" << std::endl;
	}
	
	int result = countEven(container);
	std::cout << "The amount of even numbers is " << result << std::endl;

	std::cout << "Replacing all negative numbers to 0 : " << std::endl;
	replaceNegativeNumbers(container);
	outputList(container);

	// task 2

	short m = 13;
	int n1 = 17, n2 = 23;
	double x = 12.8;
	auto xSum = FSums(n1, 4.7, m, 1.5, 10, n2, 'a');
	std::cout << "xSum = " << xSum << std::endl;

	// task 3
	
	int n = 17;
	std::string str = ToString(";", 25, 3.7, n, x);
	std::cout << str;
	
	return 0;
}