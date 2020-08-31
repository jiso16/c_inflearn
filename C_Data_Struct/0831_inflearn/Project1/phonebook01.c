#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define CAPACITY 100 //�ִ� 100�� ����
#define BUFFER_SIZE 100

// names�� numbers�� char* Ÿ���� �迭
char* names[CAPACITY]; //ĳ���� ������ ���
char* numbers[CAPACITY]; // ��ȭ��ȣ���� ���ڴ� ���ڷ� �ٷ�
int n = 0;

void add();
void find();
void status();
void Remove();

int main()
{
	char command[BUFFER_SIZE];
	while (1)
	{
		printf("$ ");
		scanf("%s", &command);
		if (strcmp(command, "add") == 0)
		{
			add();
		}
		else if (strcmp(command, "find") == 0)
		{
			find();
		}
		else if (strcmp(command, "status") == 0)
		{
			status();
		}
		else if (strcmp(command, "remove") == 0)
		{
			Remove();
		}
	}
}

void add()
{
	char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
	scanf("%s", buf1);
	scanf("%s", buf2);

	names[n] = _strdup(buf1);
	numbers[n] = _strdup(buf2);
	n++;
	/*strdup �� �迭�� �����, �Ű������� ���� �ϳ��� ���ڿ��� 
	������ �ּҿ� �����Ͽ� ��ȯ �����޸� ���*/

	printf("%s was added successfully.\n", buf1);
}

void find()
{
	char buf[BUFFER_SIZE];
	scanf("%s", buf);
	
	for (int i = 0; i < n; i++)
	{
		if (strcmp(buf, names[i]) == 0);
		{
			printf("%s\n", numbers[i]);
			return;
		}
	}
	printf("No person named '%s' exists.\n", buf);
}

void status()
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%s %s\n", names[i], numbers[i]);
	}
	printf("Total %d persons.\n", n);
}

void Remove()
{
	char buf[BUFFER_SIZE];
	scanf("%s", buf);

	for (int i = 0; i < n; i++)
	{
		if (strcmp(buf, names[i]) == 0);
		{
			names[i] = names[n - 1]; // �Ǹ������� �ִ� ����� i �ڸ��� ����
			numbers[i] = numbers[n - 1];
			n--; // �Ѹ� �پ����ϱ� �Ѹ� �ٿ���
			return;
		}
	}
	printf("No person named '%s' exists.\n", buf);
}


