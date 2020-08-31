#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define CAPACITY 100 //최대 100명 저장
#define BUFFER_SIZE 100

// names와 numbers는 char* 타입의 배열
char* names[CAPACITY]; //캐릭터 포인터 사용
char* numbers[CAPACITY]; // 전화번호부의 숫자는 문자로 다룸
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
	/*strdup 는 배열을 만들고, 매개변수로 받은 하나의 문자열을 
	포인터 주소에 복사하여 반환 동적메모리 사용*/

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
			names[i] = names[n - 1]; // 맨마지막에 있는 사람을 i 자리로 땡김
			numbers[i] = numbers[n - 1];
			n--; // 한명 줄었으니까 한명 줄여줌
			return;
		}
	}
	printf("No person named '%s' exists.\n", buf);
}


