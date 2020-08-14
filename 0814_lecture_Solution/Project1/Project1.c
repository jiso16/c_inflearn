#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int g_i = 123;
int g_j;

void func1()
{
	g_i++;
}

void fuc2()
{
	g_i += 2;
}
int main()
{
	int local = 1234;

	func1();
	fuc2();

	printf("%d\n", g_i);
	printf("%d\n", g_j);
	printf("%d\n", local);

	return 0;
}