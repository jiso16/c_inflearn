#include <stdio.h>
#include <string.h>

#define MAX_CAPACITY 100


char stack[MAX_CAPACITY];
int top = -1; //top ����� index

void push(char ch)
{
	if (is_full()) //������ �������� ���̻� push �� ��
		return;
	top++;
	stack[top] = ch;
}
char pop() //pop�� ȣ���ϱ� ���� empty���� �˻� �ʿ�
{
	if (is_empty())
		return;
	char tmp = stack[top];
	top--;
	return tmp;
}

int is_full()
{
	return top == MAX_CAPACITY - 1;
}

int is_empty()
{
	return top == -1;
}

char peek()
{
	return stack[top];
}

int main()
{
	push("4");
	push("3");
	push("2");
	push("1");

	char* str1 = pop();
	char* str2 = pop();
	char* str3 = pop();
	char* str4 = pop();

}