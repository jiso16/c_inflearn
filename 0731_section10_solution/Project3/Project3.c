#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	
	int arr[10];

	int num = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < num; ++i)
		arr[i] = (i + 1) * 100;
	int* ptr = arr;
	printf("%p %p %p\n", ptr ,arr ,&arr[0]);

	ptr += 2;
	printf("%p %p %p\n", ptr, arr+2, &arr[2]);
	printf("%d %d %d\n", *(ptr + 1), *(arr + 3), arr[3]); // index와 포인터의 산술연산 같이 사용 가능
	printf("%d %d %d\n", *ptr + 1, *arr + 3 ,arr[3]); //위와는 완전 다른 결과값 나옴
	
	
	//int* ptr = arr;
	for (int i = 0; i < num; ++i)
	{
		printf("%d %d\n", *ptr++, arr[i]);
		ptr++;
	}

}