#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void my_func(int);

int main()
{
	my_func(1);

	return 0;
}

void my_func(int n)
{
	printf("level %d, address of varialbe n = %d\n", n, (int)&n ); //주소계속 바뀜
	
	if (n <= 4)
	{
		my_func(n + 1);// 본인 자신의 함수를 부름: 재귀호출 무한루프에서 사용 안 함
	}
	printf("level %d, address of varialbe n = %d\n", n, (int)&n); //실행했던걸 다시 한 단계씩 되돌림
	
}