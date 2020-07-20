#include <stdio.h>

int main()
{
	int i, j, sum= 0;

	printf("Input Two integers:");

	scanf("%d %d", &i,&j);//&을 사용하는 이유: 입력받을 변수의 주소를 알려줌
	
	sum = i + j;

	printf("%d + %d = %d",i,j, sum);

	return 0;
}