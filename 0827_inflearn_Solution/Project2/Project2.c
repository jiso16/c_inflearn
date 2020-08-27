#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void goodbye(void)
{
	printf("GoodBye\n");
}

void thankyou()
{
	printf("Thankyou\n");
}

int main()
{
	printf("Purchaced?\n");
	if (getchar() == 'y')
		atexit(thankyou);
	while (getchar() == 'n') {};
	printf("Goodbye message?\n");
	if (getchar() == 'y')
		atexit(goodbye); //종료할때 불러오는 거
}