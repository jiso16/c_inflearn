#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 11.3���ڿ��� �迭
int main()
{
	const char* mythings[5] = {
		"Dancing in the rain",
		"Counting apples",
		"Watching moveids with friends",
		"Writing sad letters",
		"Studying the C language"
	};
	char yourtings[5][40] = {
		"Studying the C++ language",
		"eating",
		"watching Netfilx",
		"Walking around till dark",
		"Edleting spam emails"
	};
	
	const char* temp1 = "Dancing in the rain";
	const char* temp2 = "Studying the C++ language";

	printf("%s %u %u\n", mythings[0], (unsigned)mythings[0], (unsigned)temp1);
	//(unsigned)mythings[0], (unsigned)temp1 �ΰ��� �޸� ���� �Ȱ��� ��µ� - �������̱� ����
	printf("%s %u %u\n", yourtings[0], (unsigned)yourtings[0], (unsigned)temp2);
	//(unsigned)yourtings[0], (unsigned)temp2 �ΰ��� �޸� ���� �ٸ��� ��µ� - ���ؿ� �����ؼ� ���� ����

	
	// �� �Ʒ� �ڵ��� ���ڿ��� �ѱ��ھ� ��� - �޸� �鿡�� ���� �� ���� �ڵ�
	for (int i = 0; i < 100; i++)
	{
		printf("%c", mythings[0][i]);
	}
	printf("\n\n");

	for (int i = 0; i < 200; i++)
	{
		printf("%d", (int)yourtings[0][i]);
	}
	printf("\n");

	for (int i = 0; i < 200; i++)
	{
		printf("%c", (int)yourtings[0][i]);
	}
	printf("\n\n");
}
