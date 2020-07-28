#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int int_min(int i, int j);

int main()
{
	int_min( 11,12);
	

	while (1)
	{
		printf("input two integers: ");

		if (scanf("%d %d", & 11, & 12) != 2) break;

		int lesser = int_min(11, 12);
		printf("the lesseer of %d and %d is %d\n", 11, 12, lesser);
	}
}

int int_min(int i, int j)
{
	int min;

	if (i < j)
		min = i;
	else
		min = j;
	return min;

}