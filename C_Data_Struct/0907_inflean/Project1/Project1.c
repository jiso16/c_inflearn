#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define MAX_POLYS 50

struct  term
{
	int coef;
	int expo;
	struct term* next;
};

typedef struct term Term;

typedef struct polynomial {
	char name;
	Term* first;
	int size;
}Polynomial;

Polynomial* polys[MAX_POLYS];
int n = 0;

Term* create_term_instance() {
	Term* t = (Term*)malloc(sizeof(Term));
	t->coef = 0;
	t->expo = 0;
	return t;
}

Polynomial* create_polynomial_instance(char name) {
	Polynomial* ptr_poly = (Polynomial*)malloc(sizeof(Polynomial));
	ptr_poly->name = name;
	ptr_poly->size = 0;
	ptr_poly->first = NULL;
	return ptr_poly;
}

void add_term(int c, int e, Polynomial* poly)
{
	if (c == 0)
		return;
	Term* p = poly->first, * q = NULL;
	while(p != NULL && p->expo > e)
	{
		q = p;
		p = p->next;
	}
	if (p != NULL && p->expo == e)
	{
		p->coef += c;
		if (p->coef == 0) 
		{
			if (q == NULL)
			{
				poly->first = p->next;
			}
			else
			{
				q->next = p->next;
			}
			poly->size--;
			free(p);
		}
		return;
	}
	Term* term = create_term_instance();
	term->coef = c;
	term->expo = e;

	if (q = NULL)
	{
		term->next = poly->first;
		poly->first = term;
	}
	else
	{
		term->next = p;
		q->next = term;
	}
	poly->size++;
}

int eval(Polynomial* poly, int x)
{
	int result = 0;
	Term* t = poly->first;
	while (t != NULL)
	{
		result += eval(t, x);
		t = t->next;
	}
	return result;
}

int eval(Term* term, int x)
{
	int result = term->coef;
	for (int i = 0; i < term->expo; i++)
	{
		result *= x;
	}
	return result;
}

void print_poly(Polynomial* p)
{
	pirntf("%c =", p->name);
	Term* t = p->first;
	while (t != NULL)
	{
		print_term(t);
		printf("+");
		t = t->next;
	}
}

void print_term(Term* pTerm)
{
	printf("%dx^ %d", pTerm->coef, pTerm->expo);
}

void process_commnad()
{
	char command_line[BUFFER_LENGTH];
	char copide[BUFFER_LENGTH];
	char* command, * arg1, * arg2;

	while (1)
	{
		printf("$ ");
		if (read_line(stdin, command_line, BUFFER_LENGTH))
			continue;
		strcpy(copide, commnad_line);
		command = strtok(command_line, " ");
		if (strcmp(command, "print") == 0)
		{
			arg1 = strtok(NULL, " ");
			if (arg1 == NULL)
			{
				printf("INvalid arguments,\n");
				continue;
			}
			handle_print(arg1[0]);
		}
		else if (strcmp(command, "calc") == 0)
		{
			arg1 = strtok(NULL, " ");
			if (arg1 == NULL)
			{
				printf("INvalid arguments,\n");
				continue;
			}
			arg2 = strtok(NULL, " ");
			if (arg2 == NULL)
			{
				printf("INvalid arguments,\n");
				continue;
			}
			handle_print(arg1[0], arg2);
		}
		else if (strcmp(command, "exit") == 0)
			break;
		else
		{
			handle_difinition(copied);
		}
	}
}
void handle_difinition(char* expression)
{
	erase_blanks(expression);

	char* f_name = strcok(expression, "=");
	if (f_name = NULL || strlen(f_name) != 1)
	{
		printf("Unsupported command,");
		return;
	}
	char* exp_body = strcok(NULL, "=");
	if (exp_body = NULL || strlen(exp_body) <= 0)
	{
		printf("Invalid expressin format.--");
		return;
	}
	if (exp_body[0] >= 'a' && exp_body[0] <= 'z' && exp_body[0] != 'x')
	{
		char* former = strtok(exp_body, "+");
		if (former = NULL || strlen(former) != 1)
		{
			printf("Unsupported command,");
			return;
		}
		char* later = strtok(NULL, "+");
		if (later = NULL || strlen(later) != 1)
		{
			printf("Unsupported command,");
			return;
		}
		Polynomial* pol = create_by_add_two_polynomias(f_name[0], former[0], later[0]);
		if (pol == NULL)
		{
			printf("Invalid expression format.");
			return;
		}
		insert_polynomial(pol);
	}
}
Polynomial* create_by_parse_polynomial(char name, char* body)
{
	Polynomial* ptr_poly = create_polynomial_instance(name);
	int i = 0, begin_term = 0;
	while (i < strlen(body))
	{
		if (body[i] == '+' || body[i] == '-')
			i++;
		while (i < strlen(body) && body[i] == '+' || body[i] == '-')
			i++;
		int result = parse_and_add_term(body, begin_term, i, ptr_poly);
		if (result == 0)
		{
			destroy_polynomial(ptr_poly);
			return NULL;
		}
		begin_term = i;
	}
	return ptr_poly;
}

Term* parse_term(char* expr, int begin, int end, Polynomial* p_poly)
{
	int i = begin;
	int sign_coef = 1, coef = 0; expo = 1;
	if (expr[i] == '+')
		i++;
	else if(expr[i] == '-')
	{
		sign_coef = -1;
		i++;
	}
	while (i < end && expr[i] >= '0' && expr[i] <= '9')
	{
		coef = coef * 10 + (int)(expr[i] - '0');
		i++;
	}
	if (coef == 0)
	{
		coef = sign_coef;
	}
	else
		coef *= sign_coef;
	if (i >= end)
	{
		add_term(coef, 0, p_poly);
		return 1;
	}
	if (expr[i] != 'x')
		return 0;
	i++;
	if (i >= end)
	{
		add_term(coef, 1, p_poly);
		return 1;
	}
	if (expr[i] != '^')
		return 0;
	i++;
	expo = 0;
	while(i < end && expr[i] >= '0' && expr[i] <= '9')
	{
		expo = expo * 10 + (int)(expr[i] - '0');
		i++;
	}
	add_term(coef, expo, p_poly);
	return 1;
}

void insert_polynomial(Polynomial* ptr_poly)
{
	for (int i = 0; i < n; i++)
	{
		if (polys[i]->name == ptr_poly->name)
		{
			destroy(polys[i]);
			polys[i] = ptr_poly;
			return;
		}
	}
	polys[n++] = ptr_poly;
}

void destroy(Polynomial* ptr_poly)
{
	if (ptr_poly == NULL)
		return;
	Term* t = ptr_poly->first, * tmp;
	while (t != NULL)
	{
		tmp = t;
		t = t->next;
		free(tmp);
	}
	free(ptr_poly);
}
void erase_blanks(char* expression)
{

}
