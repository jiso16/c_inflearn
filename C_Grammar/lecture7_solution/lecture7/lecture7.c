#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char ch;

	while ((ch=getchar()) != '\n')
	{
		if (ch >= 'a'&&ch<='z')
		{
			ch -='a'-'A';
		}
		putchar(ch);
	}
	putchar(ch);
	return 0;
}