#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num, sum = 0;
	int status;

	printf("enter an integer (q to quit) :");
	
	status = scanf("%d", &num);

	while (status == 1)
	{
		sum = sum + num;
		printf("enter next integer (q to quit):");
		status = scanf("%d", &num);
	}
	printf("sum = %d\n", sum);

	return 0;
}