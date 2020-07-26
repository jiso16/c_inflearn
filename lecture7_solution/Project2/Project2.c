#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int main()
{
	char ch;
	

	while ((ch = getchar()) != '\n')
	{
		if (islower(ch))
		{
			ch = toupper;
		}
		else if (isupper(ch))
		{
			ch = tolower;
		}
		
		putchar(ch);
	}
	putchar(ch);
	return 0;
}