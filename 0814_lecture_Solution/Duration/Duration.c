#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void count()
{
	int ct = 0; //반복문이 아닌이상 ct 값은 계속 0을 출력함
	printf("count = %d\n", ct);
	ct++;
}

void static_count()
{
	static int ct = 0; // 프로그램이 끝날때까지 ct값 사라지지 않음
	printf("static conunt = %d\n", ct);
	ct++;
}

int main()
{
	count();
	count();

	static_count();
	static_count();
}