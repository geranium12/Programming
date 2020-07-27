	#include "ListWithIteratorAndVisitor.h"

int main()
{
	List<void*> list;
	int a[] = { 1, 3, 5 };
	double b[] = { 2, 4, 6 };
	for (int i = 0; i < 6; i++)
	{
		list.PushBack(&a[i]);
		list.PushBack(&b[i]);
	}
	GetTypeVisitor visitor;
	list.accept(visitor);
	std::cout << visitor.getValue() << std::endl;
	system("pause");
	return 0;
}