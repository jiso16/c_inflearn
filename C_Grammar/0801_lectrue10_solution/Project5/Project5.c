#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/*int arr0[3] = { 1,2,3 };
	int arr1[3] = { 4,5,6 };

	int* parr[2] = { arr0, arr1 }; // 포인터가 담길수 있는 메모리 공간을 두개 확보한 배열

	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < 3; ++i)
		{
			printf("%d(==%d,%d)", parr[j][i], *(parr[j] + i),(*(parr +j))[i]);
		}
		printf("\n");
	}
	printf("\n");*/

	int arr[2][3] = { {1,2,3 },{4,5,6} };

	int* parr[2];


}