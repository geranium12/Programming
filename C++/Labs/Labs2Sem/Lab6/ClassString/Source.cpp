// Герасимчик Анна. 1 курс. 7 группа
#include "ClassString.h"

using namespace std;

int main()
{
	char* p1 = new char[100];
	char *p2 = new char[100];
	strcpy(p1, "Hello ");
	strcpy(p2, "World!");
	String str1(p1, 100), str2(p2, 100);
	cout << str1 << endl;
	cout << str2 << endl;
	cout << "str2 <= str1 " << (str2 <= str1) << endl;
	String str3 = str2; 
	str2 = str1 + str2;
	str1 += str3;
	cout << "str1 += str2 " << str1 << endl;
	cout << "str1 + str2 " << str2 << endl;
	cout << "str1 == str2 " << (str1 == str2) << endl;
	cout << endl;

	char *p4 = new char[100];
	strcpy(p4, "Hellollo");
	String str4(p4, 100);
	char *p5 = new char[100];
	strcpy(p5, "llo");
	String str5(p5, 100);
	cout << "SEARCHWORDINT " << searchWordInt(str4, str5, 0, false) << endl;
	cout << "SEARCHWORDINT " << searchWordInt(str4, str5, 0, true) << endl;
	insertWordPos(str4, str5, 1);
	cout << str4 << endl;
	replaceWord(str4, str5, str2);
	cout << str4 << endl;

	system("pause");
	return 0;
}