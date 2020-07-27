#include "SingleList.h"

using namespace std;

int main()
{
	SingleList l;
	for (int i = 0; i < 10; i++)
		l.push_back(i + 1);
	SingleList l2(l);
	l2.delchet();
	l2.print();
	system("pause");
	return 0;
}