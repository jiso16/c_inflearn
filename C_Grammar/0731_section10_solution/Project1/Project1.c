#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
 
#define MONTH 12
int main()
{
	int high[MONTH] = { 2,5,11,18,23,27,29,30,26,20,12,4 };
	int i = 0;

	for (int i = 0; i < MONTH; ++i)
	{
		printf("%d", high[i]);
	}
	printf("\n");

	float avg = 0.0;
	for ( i = 0; i < MONTH; ++i);
	{
		avg += high[i];
	}
	printf("Average = %f\n", avg/(float)MONTH);

	high[0] = 1;
	high[1] = 2;

	printf("%p %p\n", high, &high[0]);
}