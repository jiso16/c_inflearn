#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int secret_code = 3569;
	int i = 0;
	do // 일단 하고보는 코드, 진입조건
	{
		printf("Enter the code:");
		scanf("%d", &i);
	} 
	while (i != secret_code);

	printf("Good!");
	
	return 0;
}