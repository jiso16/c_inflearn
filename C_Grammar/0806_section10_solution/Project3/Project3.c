#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 11.1. ���ڿ��� �����ϴ� ���

#define MESSAGE "A symbolic string contant"
#define MAXLENGTH 81

int main()
{
	char words[MAXLENGTH] = "A string in an array"; // �迭
	const char* ptr1 = "A pointer to a string"; 
	// ��򰡿� ����Ǿ� �ִ� ���ڿ� �ּ��� ù��° �ּҸ� ������

	puts("Puts() adds a newline at the end:");// �ڿ� ���ο� ������ �˾Ƽ� ���ٿ���
	puts(MESSAGE);
	puts(words); // MAXLENGTH ��ŭ�� �޸𸮸� �ʱ�ȭ ������ �ʾƼ� warning�� ��
	puts(ptr1);
	words[3] = 'p';
	puts(words);
	//ptr1[8] = 'A';  Error����

	char greeting[50] = " Hello, and" "How are" "you" "today!";
	// ����ǥ ������ ���⵵ ��µ�
	puts(greeting);

	printf("\"To be, or not to be\" Hamlet said.\n");

	printf("%s, %p, %c\n", "We", "are", *"Exellent programmers");

	const char m1[15] = "Love you!";
	
	for (int i = 0; i < 15; ++i)
	{
		printf("%d ", (int)m1[i]); // ���ڿ��� ���������� �ٲ� - ascii code ���
	}
	printf("\n");

	int n = 8;
	char cookies[1] = { 'A' };
	char cakes[2 + 5] = { 'A', };
	char pies[2 * sizeof(long double) + 1] = { 'A', };
}