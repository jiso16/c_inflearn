#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 5

int main()
{
	int my_arr[SIZE];
	int i;
	int sum = 0;
	printf("Enter 5 numbers:");
	for (int i = 0; i < SIZE; ++i)
	{
		scanf("%d", & my_arr[i]);
		sum += my_arr[i];
	}
	printf("%d", sum);
	return 0;
}