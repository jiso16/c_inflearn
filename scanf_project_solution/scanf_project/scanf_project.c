#include <stdio.h>

int main()
{
	int i, j, sum= 0;

	printf("Input Two integers:");

	scanf("%d %d", &i,&j);//&�� ����ϴ� ����: �Է¹��� ������ �ּҸ� �˷���
	
	sum = i + j;

	printf("%d + %d = %d",i,j, sum);

	return 0;
}