#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int secret_code = 3569;
	int i = 0;
	do // �ϴ� �ϰ��� �ڵ�, ��������
	{
		printf("Enter the code:");
		scanf("%d", &i);
	} 
	while (i != secret_code);

	printf("Good!");
	
	return 0;
}