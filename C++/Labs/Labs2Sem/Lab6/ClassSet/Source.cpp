#include "ClassSet.h"

using namespace std;

int main()
{
	int p[] = { 1, 2, 8, 4, 32, 16};
	Set s1(p, 6);
	cout << "S1 = " << s1 << endl;
	s1 = s1 + 64;
	s1 = s1 - 1;
	cout << "s1 = s1 + 64;   s1 = s1 - 1;" << endl;
	cout << "S1 = " << s1 << endl;
	Set s2(s1);
	cout << "Set s2(s1);" << endl;
	cout << "S2 = " << s2 << endl;
	s2 = s2 + 24;
	s2 = s2 + (-2);
	cout << "s2 = s2 + 24;   s2 = s2 + (-2);" << endl;
	cout << "S2 = " << s2 << endl;
	cout << "Union (S1 + S2) : " << s1 + s2 << endl;
	cout << "Intersection (S1 * S2) : " << s1 * s2 << endl;
	cout << "Subtraction (S2 - S1) : " << s2 - s1 << endl;
	s1 -= 32;
	cout << "s1 -= 32;" << endl;
	cout << "S1 = " << s1 << endl;
	cout << "s2.include(32)= " << s2.include(32) << endl;
	cout << "s1.include(32)= " << s1.include(32) << endl;
	cout << "(s1 == s1) = " << (s1 == s1) << "	(s1 == s2) = " << (s1 == s2) << endl;
	cout << "(s1 > s1) = " << (s1 > s1) << "	(s1 >= s1) = " << (s1 >= s1) << endl;
	cout << "(s1 > s2) = " << (s1 > s2) << "	(s2 >= s1) = " << (s2 >= s1) << endl;
	cout << "(s1<s1)=" << (s1 < s1) << "	(s1 <= s1) = " << (s1 <= s1) << endl;
	cout << "(s1<s2)=" << (s1 < s2) << "	(s2 <= s1) = " << (s2 <= s1) << endl;
	system("pause");
	return 0;
}