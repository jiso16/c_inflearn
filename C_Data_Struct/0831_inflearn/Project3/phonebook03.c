#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


#define INIT_CAPACITY 3 //�ִ� 100�� ����
#define BUFFER_SIZE 50

// names�� numbers�� char* Ÿ���� �迭
char** names; //ĳ���� ������ ���
char** numbers; // ��ȭ��ȣ���� ���ڴ� ���ڷ� �ٷ�

int capacity = INIT_CAPACITY;
int n = 0;

int main()
{
	init_directory();
	process_command();

	return 0;
}

void init_directory()
{
	names = (char**)malloc(INIT_CAPACITY * sizeof(char*));
	numbers = (char**)malloc(INIT_CAPACITY * sizeof(char*));
}

int read_line(char str[], int limit) // �迭 str�� ũ�Ⱑ limit
{
	int ch, i = 0;
	while ((ch = getchar()) != '\n') //�ٹٲ� ���ö����� ����
		if (i < limit - 1) //�迭 �뷮 �� �������� ����
			str[i++] = ch;
	str[i] = '\0'; //�������� null character�߰�

	return i; //������ ���� ���ڼ� ��ȯ
}
