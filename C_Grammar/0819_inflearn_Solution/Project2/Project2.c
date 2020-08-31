#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


#define MAX_BOOK 3

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

struct book
{
	char title[40];
	char autor[40];
	float price;
};

int main()
{
	struct book library[40];
	int count = 0;

	while (1)
	{
		printf("Input a book title or press [Enter] to stop. \n >>");
		if (s_gets(library[count].title, 40) == NULL) break;
		if (library[count].title[0] == '\0') break;

		printf("Input the autor.\n>>");
		s_gets(library[count].autor, 40);

		printf("Input the price.\n>>");
		int flag = scanf("%f", &library[count].price);
		while (getchar() != '\n')
			continue;

		count++;

		if (count == MAX_BOOK)
		{
			printf("No more books.\n");
			break;
		}
	}
	if (count > 0)
	{
		printf("\n The list of books:\n");
		for (int index = 0; index < count; index++)
		{
			printf("\"%s\" written by %s: $%.1f\n", library[index].title, library[index].autor, library[index].price);
		}

	}
	else 
		printf("Mo books to show.\n");

	return 0;
}