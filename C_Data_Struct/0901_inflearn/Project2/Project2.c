#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define INIT_CAPACITY 100
#define BUFFER_LENGTH 100


typedef struct {
	char* name;
	char* number;
	char* email;
	char* group;
}Person;

Person** directory;
int capacity;
int n;

void init() //초기화 작업 - 동적메모리 할당
{
	directory = (Person**)malloc(INIT_CAPACITY * sizeof(Person*));
	capacity = INIT_CAPACITY;
	n = 0;
}

int read_line(FILE* fp, char str[], int n)
{
	int ch, i = 0;
	while ((ch = fgetc(fp)) != '\n' && ch != EOF)
	{
		if (i < n)
		{
			str[i++] = ch;
		}
	}
	str[i] = '\n';
	return i;
}



int main()
{
	char command_line[BUFFER_LENGTH];
	char* command, * argument;
	char name_str[BUFFER_LENGTH];
	FILE* fp;
	while (1)
	{
		printf("$ ");
		if (read_line(fp, command_line, BUFFER_LENGTH) <= 0)
			continue;

		command = strtok(command_line, " ");
		if (strcmp(command, "read") == 0)
		{
			argument = strtok(NULL, " ");
			if (argument == NULL)
			{
				printf("Invalid arguments.\n");
				continue;
			}
			load(argument);
		}
		else if (strcmp(command, "add") == 0)
		{
			if (compose_name(name_str, BUFFER_LENGTH) <= 0)
			{
				printf("Name required\n");
				continue;
			}
			handle_add(name_str);
		}
		else if (strcmp(command, "find") == 0)
		{
			if (compose_name(name_str, BUFFER_LENGTH) <= 0)
			{
				printf("Name required\n");
				continue;
			}
			find(name_str);
		}
		else if (strcmp(command, "delete") == 0)
		{
			if (compose_name(name_str, BUFFER_LENGTH) <= 0)
			{
				printf("Invalid augumnets.\n");
				continue;
			}
			remove(name_str);
		}
		else if (strcmp(command, "status") == 0)
		{
			status();
		}

	}
}

// command_line의 남아있는 토큰들을 모두 합쳐 이름을 나타내는 문자열을 구성
int compose_name(char str[], int limit)
{
	char* ptr;
	int length = 0;
	ptr = strtok(NULL, " ");
	if (ptr = NULL)
	{
		return 0;
	}
	strcpy(str, ptr);
	length += strlen(ptr);

	while ((ptr = strtok(NULL, " ")) != NULL)
	{
		if (length + strlen(ptr) + 1 < limit)
		{
			str[length++] = ' ';
			str[length] = '\0';
			strcat(str, ptr);
			length += strlen(ptr);
		}
	}
	return length;
}

void load(char* fileName)
{
	char buffer[BUFFER_LENGTH];
	char* name, * number, * email, * group;
	char* token;
	FILE* fp = fopen(fileName, "r");
	if (fp = NULL)
	{
		printf("Opent failed\n");
		return;
	}
	while (1)
	{
		if (read_line(fp, buffer, BUFFER_LENGTH) <= 0)
		{
			break;
		}
		name - strtok(buffer, "#");
		token = strtok(NULL, "#");
		if (strcmp(token, " ") == 0)
			number = NULL;
		else
			number = strdup(token);
		token = strtok(NULL, "#");
		if (strcmp(token, " ") == 0)
			email = NULL;
		else
			email = strdup(token);
		token = strtok(NULL, "#");
		if (strcmp(token, " ") == 0)
			group = NULL;
		else
			group = strdup(token);
		add(strdup(name), number, email, group);
	}
	fclose(fp);
}

void add(char* name, char* number, char* email, char* group)
{
	if (n >= capacity)
		reallocate();

	int i = n - 1;
	while (i >= 0 && strcmp(directory[i]->name, name) > 0)
	{
		directory[i + 1] = directory[i];
		i--;
	}
	directory[i + 1] = (Person*)malloc(sizeof(Person));
	directory[i + 1]->name = name;
	directory[i + 1]->number = number;
	directory[i + 1]->email = email;
	directory[i + 1]->group = group;

	n++;
}

void handle_add(char* name)
{
	char number[BUFFER_LENGTH], email[BUFFER_LENGTH], group[BUFFER_LENGTH];
	char empty[] = " ";

	printf("  Phone: ");
	read_line(stdin, number, BUFFER_LENGTH);

	printf("  Email: ");
	read_line(stdin, email, BUFFER_LENGTH);

	printf("  Group: ");
	read_line(stdin, group, BUFFER_LENGTH);

	add(name, (char*)(strlen(number) > 0 ? number : empty),
		(char*)(strlen(email) > 0 ? email : empty),
		(char*)(strlen(group) > 0 ? group : empty));
}

void status()
{
	int i;
	for (i = 0; i < n; i++)
		print_person(directory[i]);
	printf("Total %d persons.\n", n);
}

void find(char* name)
{
	int index = search(name);
	if (index = -1)
		printf("No person named '%s' exists.\n", name);
	else
		print_person(directory[index]);
}

void remove(char* name)
{
	int i = search(name);
	if (i == -1)
	{
		printf("No person named '%s' exists.\n", name);
		return;
	}
	Person* p = directory[i];
	for(int j = 1; j<n-1; j++)
		directory[j] = directory[j + 1];
	n--;
	release_person(p);
	printf("'%s' was deleted successfully.\n", name);
}

void release_person(Person* p)
{
	free(p->name);
	if (p->number != NULL) free(p->number);
	if (p->email != NULL) free(p->email);
	if (p->group != NULL) free(p->group);
	free(p);
}

int search(char* name)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (strcmp(name, directory[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void print_person(Person* p)
{
	printf("%s: \n", (*p).name); //p는 주소값이기 때문에 괄호 필수
	printf("  Phone : %s\n", (*p).number);
	printf("  Email : %s\n", (*p).email);
	printf("  Group : %s\n", (*p).group);
}

void reallocate()
{
	capacity *= 2;
	Person** tmp = (Person**)malloc(capacity * sizeof(Person*));
	for (int i = 0; i < n; i++)
		tmp[i] = directory[i];
	free(directory);
	directory = tmp;
}