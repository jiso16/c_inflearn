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
void load();
void save();
int search(char* name);

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
		else if (strcmp(command, "load") == 0)
		{
			load();
		}
		else if (strcmp(command, "save") == 0)
		{
			save();
		}
	}
}

void find()
{
	char buf[BUFFER_SIZE];
	scanf("%s", buf);
	int index = search(buf);
	if (index == -1)
	{
		printf("No person named '%s' exists.\n", buf);
	}
	else
		printf("%s\n", numbers[index]);
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

	int index = search(buf);
	if (index == -1) {
		printf("No person named '%s' exists.\n", buf);
		return;
	}
	int j = index;
	for (; j < n - 1; j++)
	{
		names[j] = names[j + 1];
		numbers[j] = numbers[j + 1];
	}
	n--;
	printf("'%s' was deleted successfully.\n", buf);
}

void load()
{
	char fileName[BUFFER_SIZE];
	char buf1[BUFFER_SIZE];
	char buf2[BUFFER_SIZE];

	scanf("%s", fileName);
	
	FILE* fp = fopen(fileName, "r");
	if (fp == NULL)
	{
		printf("Open Failed.\n");
		return;
	}
	while ((fscanf(fp, "%s", buf1) != EOF))
	{
		fscanf(fp,"%s", buf2);
		names[n] = _strdup(buf1);
		numbers[n] = _strdup(buf2);
		n++;
	}
	fclose(fp);
}

void save()
{
	int i;
	char fileName[BUFFER_SIZE];
	char tmp[BUFFER_SIZE];

	scanf("%s", tmp);
	scanf("File Name: %s", fileName);
	FILE* fp = fopen(fileName, "w");
	if (fp == NULL)
	{
		printf("Open Failed.\n");
		return;
	}
	for (i = 0; i < n; i++)
	{
		fprintf(fp, "%s %s\n", names[i], numbers[i]);
	}
	fclose(fp);
}

void add()
{
	char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
	scanf("%s", buf1);
	scanf("%s", buf2);

	int i = n - 1;
	while (i > 0 && strcmp(names[i], buf1) > 0)
	{
		names[i + 1] = names[i];
		numbers[i + 1] = numbers[i];
		i--;
	}
	names[i + 1] = _strdup(buf1);
	numbers[i + 1] = _strdup(buf2);
	
	n++;
	printf("%s was added successfully,\n", buf1);
}

int search(char* name)
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(name, names[i]) == 0)
		{
			return i;
		}
	}
	return -1;
}