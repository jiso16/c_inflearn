#include <stdio.h>

#define SIZE 10

char stack[SIZE];
int top = -1; // �� ���� ���Ҹ� ��Ÿ�� top ����

int is_full()
{
	if (top >= SIZE - 1) // top�� ũ�Ⱑ size-1���� Ŭ���
	{
		printf("Error: stack is Full\n");
		return 1;
	}
	return 0;
}

int is_empty()
{
	if (top == -1)
	{
		printf("Error: stack is empty\n");
		return 1;
	}
	return 0;
}

void push(char data)
{
	if (is_full != 1)
	{
		top++;
		stack[top] = data;
	}
}

char pop()
{
	if (is_empty != 1)
	{
		char temp = stack[top];
		printf("\nTop: %c\n", stack[top]);
		top--;
		return temp;
	}
}

char peek()
{
	if (is_empty != 1)
	{
		return stack[top];
	}
}

void PrintStack()
{
	if (is_empty != 1)
	{
		for (int i = 0; i <= top; i++)
		{
			printf("%c ", stack[i]);
		}
	}

}

int main()
{
	PrintStack();
	push('a');
	push('b');
	push('c');
	PrintStack();
	pop();
	PrintStack();
}