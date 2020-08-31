#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <iso646.h>

int main()
{
	int number = 0;
	scanf("%d", &number);

	bool is_even = (number % 2 == 0) ? true : false;

	if (is_even)
	{
		printf("even");
	}
	else
	{
		printf("odd");
	}
	return 0;
}