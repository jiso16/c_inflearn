#include <stdio.h>
#include <string.h>
//#include "stack.h"

#define MAX_LENGTH 100

char OPEN[] = "([{";
char CLOSE[] = "}])";

int is_balanced(char* expr);
int is_open(char ch);
int is_close(char ch);

struct node {
	char* data;
	struct node* next;
};
typedef struct node Node;
Node* top = NULL;

void push(char* item)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = item;
	p->next = top;
	top = p;
}

char* pop()
{
	if (is_empty())
		return NULL;
	char* result = top->data;
	top = top->next;
	return result;
}

char* peek()
{
	if (is_empty())
		return NULL;
	return top->data;
}

int is_empty()
{
	return top == NULL;
}

int main()
{
	char expr[MAX_LENGTH];
	scanf("%s", expr);
	if (is_balanced(expr))
		printf("%s : balanced.\n", expr);
	else
		printf("%s : unbalanced.\n", expr);
}
int is_balanced(char* expr)
{
	int balanced = 1;
	int index = 0;
	while (balanced && index < strlen(expr))
	{
		char ch = expr[index];
		if (is_open(ch) > -1)
			push(ch);
		else if (is_close(ch) > -1)
		{
			if (is_empty())
			{
				balanced = 0;
				break;
			}
			char top_ch = pop();
			if (is_open(top_ch) != is_close(ch))
			{
				balanced = 0;
			}
		}
		index++;
	}
	return(balanced == 1 && is_empty() == 1);
}

int is_close(char ch)
{
	for (int i = 0; i < strlen(CLOSE); i++)
	{
		if (CLOSE[i] == ch)
			return i;
	}
	return -1;
}

int is_open(char ch)
{
	for (int i = 0; i < strlen(OPEN); i++)
	{
		if (OPEN[i] == ch)
			return i;
	}
	return -1;
}