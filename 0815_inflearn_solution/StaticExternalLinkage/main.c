#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int g_int;
double g_arr[1000] = { 0.0 };

int x = 5;
int y = 1 + 2;

size_t z = sizeof(int);

void fun()
{
	printf("g_int in fun() %d %p\n", g_int, &g_int);
	g_int += 10;
}

void fun_sec();

int main()
{
	extern int g_int;

	extern double g_arr[];

	printf("g_int in main() %d %p\n", g_int, &g_int);
	g_int += 1;

	fun();
	fun_sec();
	return 0;
}
