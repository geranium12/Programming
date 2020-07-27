#include "StackArray.h"

using namespace std;

int main()
{
	StackArray st(10);
	for (int i = 0; i < 9; i++)
		st.push(i + 1);
	cout << st.isFool() << endl;
	cout << st.peek() << endl;
	StackArray st2(st);
	st.push(10);
	cout << st.isFool() << endl;
	cout << st2.peek() << endl;
	system("pause");
	return 0;
}