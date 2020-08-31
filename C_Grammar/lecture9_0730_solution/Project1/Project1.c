#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_binary_loop(unsigned long num);
void print_binary(unsigned long num);

//10진수를 이진수로 변환 예제

int main()
{
	unsigned long num = 10;

	print_binary_loop(num);
	print_binary(num);

	printf("\n");

	return 0;
}

void print_binary_loop(unsigned long num)
{
	while (1)
	{
		int quotient = num / 2;
		int remainder = num % 2;

		printf("%d", remainder);
		num = quotient;

		if (num == 0) break;
	}
	printf("\n");
}

void print_binary(unsigned long num)
{
	int remainder = num % 2;

	if (num >= 2)
	{
		print_binary(num / 2);
	}
	printf("%d", remainder);

	return;
}