#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	long long* ptr = 0;
	
	printf("%p %11d\n", ptr, (long long)ptr);

	ptr += 2;

	printf("%p %11d\n", ptr, (long long)ptr);

	//ptr = -ptr; // not working �����ʹ� �ּҰ��̱� ������ ������ ���� �� �ϰ� ���Ƴ���
	//ptr = +ptr; // not working

	double arr[10];
	double* ptr1 = &arr[1]; 
	double* ptr2 = &arr[3];

	
	// ptr2 = ptr1 + ptr2; // not working �ּҳ��� ���ϱ� �۵� �� ��

	int i = ptr2 - ptr1;
	printf("%d %d %d\n", (long long)ptr1, (long long)ptr2, i);

	return 0;
}