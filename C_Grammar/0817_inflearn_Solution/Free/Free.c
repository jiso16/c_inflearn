#define _CTR_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 10;

	int* ptr = NULL;

	ptr = (int*)calloc(n, sizeof(int));
	if (!ptr)
	{
		exit(1);
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%d", ptr[i]);
	}
	printf("\n");

	for (int i = 0; i < n; ++i)
	{
		ptr[i] = i + 1;
	}
	n = 20;

	int* ptr2 = NULL;
	ptr2 = (int*)realloc(ptr, n * sizeof(int));

	printf("%p %p\n", ptr, ptr2);
	printf("%d\n", ptr[0]);

	if (!ptr2)
	{
		exit(1);
	}
	else
		ptr = NULL;
	for (int i = 0; i < n; i++)
	{
		printf("%d", ptr2[i]);
	}
	printf("\n");

	free(ptr2);
}