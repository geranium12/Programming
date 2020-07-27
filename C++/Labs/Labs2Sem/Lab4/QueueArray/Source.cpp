#include "QueueArray.h"

using namespace std;

int main()
{
	QueueArray q(10);
	for (int i = 0; i < 10; i++)
	{
		q.push_back(i + 1);
	}
	for (int i = 0; i < 4; i++)
		q.pop_front();
	for (int i = 0; i < 4; i++)
		q.push_back(i + 1);

	q.print();
	if (q.isFool())
		cout << "fool" << endl;
	else
		cout << "not fool" << endl;
	system("pause");
	return 0;
}