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
	printf("level %d, address of varialbe n = %d\n", n, (int)&n ); //�ּҰ�� �ٲ�
	
	if (n <= 4)
	{
		my_func(n + 1);// ���� �ڽ��� �Լ��� �θ�: ���ȣ�� ���ѷ������� ��� �� ��
	}
	printf("level %d, address of varialbe n = %d\n", n, (int)&n); //�����ߴ��� �ٽ� �� �ܰ辿 �ǵ���
	
}