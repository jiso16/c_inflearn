#define _CTR_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	const const const int n = 7; // = const int n = 7;

	typedef const int zip;
	const zip q = 9; // = const const int zip;

	//volatile : ����ȭ ���� ����

	volatile int vi = 1;
	volatile int* pvi = &vi;

	int i1 = vi;

	int i2 = vi;

	//restrict : ����ȭ�� ������

	int ar[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* par = ar;

	int* __restrict restar = (int*)malloc(10 * sizeof(int));
	if (!restar) exit(1);

	ar[0] += 3;
	par[0] += 5;
	// par[0] += 8; // restric�� ���� ������ �ƴϱ� ������ �������� ���ϰ� ����ȭ���� ����

	restar[0] += 3;
	restar[0] += 5;
	//restar[0] += 8; ����ȭ ����
}