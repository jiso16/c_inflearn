#define _CTR_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	//int arr[100];

	double* ptr = NULL;

	ptr = (double*)malloc(30 * sizeof(double)); // double�� 30��

	if (ptr == NULL) // �޸𸮰����� �� �� ���� ��� null�� ��ȯ
	{
		puts("Memory allocation failed");

		exit(EXIT_FAILURE);
	}
	printf("Before free %p\n", ptr);

	free(ptr);

	printf("After free %p\n", ptr);

	ptr = NULL;
}