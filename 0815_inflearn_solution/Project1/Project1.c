#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void func(int k);

int main()
{
	auto int a;
	a = 1024;
	auto int b = a * 3;

	int i = 1;
	int j = 2;

	printf("i %lld\n", (long long)&i);
	{
		int i = 3;
		printf("i %lld\n", (long long)&i);
		int ii = 123;
		printf("j = %d\n", j);
	}
	// ii는 위 블록을 벗어나면 볼 수 없음
	printf("i %lld\n", (long long)&i);

	for (int m = 1; m < 2; m++)
	{
		printf("m %lld\n", (long long)&m);
	}

	func(5);

	for (int m = 3; m < 4; m++)
	{
		printf("m %lld\n", (long long)&m);
	}
	return 0;
}

void func(int k)
{
	int i = k * 2;
	printf("i %lld\n", (long long)&i);
}