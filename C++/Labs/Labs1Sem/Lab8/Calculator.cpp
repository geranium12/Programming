#include <iostream>
#include "Library.h"


const char *digits = "1234567890";

int priority(char c)
{
	if ((c == '*') || (c == '/'))
	{
		return 2;
	}
	else
	{
		if ((c == '+') || (c == '-'))
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
}

char *toPostfix(char *str)
{
	char *post = new char[STR_SIZE];
	int countPost = 0;
	StackNode* top = NULL;
	int lenStr = strlen(str);
	for (int i = 0; i < lenStr; i++)
	{
		const char letter = str[i];
		if (letter == ' ')
			continue;
		int j = 0;
		int lenDigits = strlen(digits);
		while ((letter != digits[j]) && (j < lenDigits))
			j++;
		if (j != lenDigits)
		{
			post[countPost] = digits[j];
			countPost++;
		}
		else
		{
			if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'))
			{
				post[countPost] = letter;
				countPost++;
			}
			else
			{
				post[countPost] = ' ';
				countPost++;
				switch (letter)
				{
				case '(':
				{
					push(&top, (char *)'(');
					break;
				}
				case ')':
				{
					while (((char)peek(top) != '(') && (!isEmpty(top)))
					{
						post[countPost] = (char)pop(&top);
						countPost++;
					}
					if (!isEmpty(top))
					{
						pop(&top);
					}
					break;
				}
				default:
				{
					while ((!isEmpty(top)) && (priority(letter) <= priority((char)peek(top))))
					{
						post[countPost] = (char)pop(&top);
						countPost++;
					}
					push(&top, (char *)letter);
					break;
				}
				}
			}
		}
	}
	while (!isEmpty(top))
	{
		post[countPost] = (char)pop(&top);
		countPost++;
		post[countPost] = ' ';
		countPost++;
	}
	post[countPost] = '\0';
	return post;
}

int calculate(char *str)
{
	StackNode* top = NULL;
	int i;

	int lenStr = strlen(str);
	for (i = 0; i < lenStr; i++)
	{
		if (str[i] == ' ')
			continue;
		if (isdigit(str[i]))
		{
			int num = 0;
			while (isdigit(str[i]))
			{
				num = num * 10 + (int)(str[i] - '0');
				i++;
			}
			i--;
			push(&top, (int *)num);
		}
		else
		{
			int val1 = (int)pop(&top);
			int val2 = (int)pop(&top);
			switch (str[i])
			{
			case '+':	push(&top, (int *)(val2 + val1));
				break;
			case '-':	push(&top, (int *)(val2 - val1));
				break;
			case '*':	push(&top, (int *)(val2 * val1));
				break;
			case '/':	push(&top, (int *)(val2 / val1));
				break;
			}
		}
	}
	return (int)pop(&top);
}