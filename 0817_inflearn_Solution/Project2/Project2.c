#define _CTR_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	const const const int n = 7; // = const int n = 7;

	typedef const int zip;
	const zip q = 9; // = const const int zip;

	//volatile : 최적화 하지 않음

	volatile int vi = 1;
	volatile int* pvi = &vi;

	int i1 = vi;

	int i2 = vi;

	//restrict : 최적화를 도와줌

	int ar[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* par = ar;

	int* __restrict restar = (int*)malloc(10 * sizeof(int));
	if (!restar) exit(1);

	ar[0] += 3;
	par[0] += 5;
	// par[0] += 8; // restric을 해준 변수가 아니기 때문에 접근하지 못하고 최적화하지 못함

	restar[0] += 3;
	restar[0] += 5;
	//restar[0] += 8; 최적화 해줌
}