#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

void ToUpper(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

void ToLower(char* str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
}

int main()
{
	char str[] = "Hello, World";

	void (*pf)(char*);

	pf = ToUpper;

	printf("String literal %lld\n", (long long)("Hello, World!"));
	printf("Funtion Pointer %lld\n", (long long)ToUpper);
	printf("Bariable %11d\n", (long long)str);
	(*pf)(str);  // = ToUpper(str);

	printf("ToUpper %s\n", str);
	pf = ToLower;

	pf(str);

	printf("ToLower %s\n", str);
}