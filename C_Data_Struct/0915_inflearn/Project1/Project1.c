#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

static char OPERATOR[] = "+-*/";

Stack operand_stack;

int is_operator(char ch)
{
	for (int i = 0; i < strlen(OPERATOR); i++)
		if (OPERATOR[i] == ch)
			return i;
	return -1;
}

int eval(char* expr)
{
	operand_stak = creat();
	char* token = strtok(expr, " ");
	while (token != NULL)
	{
		if(token[0] >= '0'&& token[0] <='9')
		{
			int value = atoi(token);
			push(operand_stack, value);
		}
		else if (is_operator(token[0]) > -1)
		{
			int result = eval_op(token[0]);
			push(operand_stack, result);
		}
		else
		{
			handle_exception("Syntax Error: invalid \
				character encountered.");
		}
		token = strtok(NULL, " ");
	}
	if (is_empty(operand_stack))
		handle_exception("Syntax Error: Stack empty \
			in eval_op");
	int answer = pop(operand_stack);
	if (is_empty(operand_stack))
		return answer;
	else {
		handle_exception("Syntax Error: Stack should \
			be empty");
		return -1;
	}

}

void handle_exception(const char* err_msg)
{
	printf("%s\n", err_msg);
	exit(1);
}

int eval_op(char op)
{
	if(is_empty(operand_stack))
		handle_exception("Syntax Error: stack \
			empty in eval_op");
	int rhs = pop(operand_stack);
	if(is_empty(operand_stack))
		handle_exception("Syntax Error: stack \
			empty in eval_op");
	int lhs = pop(operand_stack);
	int result = 0;
	switch (op)
	{
		case '+': result = lhs + rhs; break;
		case '-': result = lhs - rhs; break;
		case '*': result = lhs * rhs; break;
		case '/': result = lhs / rhs; break;
	}
	return result;
}