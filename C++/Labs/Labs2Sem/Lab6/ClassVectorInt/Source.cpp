#include "ClassVector.h"
#include <iostream>

using namespace std;

int main()
{
	Vector v;
	
	for (int i = 0; i < 10; i++)
	{
		v.push_front(i + 1);
	}
	for (int i = 0; i < 10; i++)
	{
		v.pop_front();
	}
	cout << v;
	system("pause");
	return 0;
}