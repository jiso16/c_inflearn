#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void count()
{
	int ct = 0; //�ݺ����� �ƴ��̻� ct ���� ��� 0�� �����
	printf("count = %d\n", ct);
	ct++;
}

void static_count()
{
	static int ct = 0; // ���α׷��� ���������� ct�� ������� ����
	printf("static conunt = %d\n", ct);
	ct++;
}

int main()
{
	count();
	count();

	static_count();
	static_count();
}