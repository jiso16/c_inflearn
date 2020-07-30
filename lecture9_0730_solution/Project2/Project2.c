#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fibonacci(int number);

int main()
{
	for (int count = 1; count < 13; ++count)
		printf("%d", fibonacci(count));
	return 0;
}

int fibonacci(int number)
{
	if (number > 2)
		return fibonacci(number - 1) + fibonacci(number - 2);
	else
		return 1;
}
//재귀호출 사용하면 메모리가 비효율적