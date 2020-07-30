#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//int* ptr;
	
	//printf("%p\n", ptr);
	//printf("%p\n", *ptr);
	//------------------------------------------------------------
	int* safer_ptr = NULL;
	int a = 123;

	int b;
	scanf("%d", &b);

	if (b % 2 == 0)
		safer_ptr = &a;
	if (safer_ptr != NULL)
		printf("%p\n", safer_ptr);
	if (safer_ptr != NULL)
		printf("%d\n", *safer_ptr);
		
}