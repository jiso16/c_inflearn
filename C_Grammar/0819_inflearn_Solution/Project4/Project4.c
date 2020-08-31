#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define FUNDLEN 50

struct fortune {
	char bank_name[FUNDLEN];
	double bank_saving;
	char fund_name[FUNDLEN];
	double fund_invest;
};

double sum(struct fortune my_fortune);

int main()
{
	struct fortune my_fortune =
	{
		"Wells-Fargo",
		4032.27,
		"JPMorgan chase",
		8543.94
	};

	printf("Total: $%.2f.\n", sum(my_fortune));

	return 0;

}

double sum(struct fortune my_forturn)
{
	return my_forturn.bank_saving + my_forturn.fund_invest;
}