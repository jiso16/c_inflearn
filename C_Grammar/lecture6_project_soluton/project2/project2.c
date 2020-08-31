#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	const double PI = 3.14159265358979;
	double guess = 0.0;

	printf("input pi:");

	scanf("$1f", &guess);

	while (fabs(guess - PI) > 0.01)
	{
		printf("Fool! Try again.\n");
		scanf("%1f", &guess);
	}
	printf("Good!");

	return 0;
}