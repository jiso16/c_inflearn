#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//2차원 배열

int main()
{
	int arr[2][3] = { {1,2,3},
					{4,5,6} };

	printf("%d\n\n", arr[1][1]);

	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < 3; ++i)
		{
			printf("%d", arr[j][i]);
		}
		printf("\n");
	}

	int* ptr = &arr[0][0];
	for (int k = 0; k < 6; ++k)
	{
		printf("%d",ptr[k]);
	}
	printf("\n\n");

	printf("%zd %zd\n", sizeof(arr), sizeof(arr[0]));//sizeof(arr)는 배열 전체의 크기, 3개짜리의 크기{1,2,3)
}