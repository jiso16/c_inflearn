#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM_ROWS 10
#define FIRST_GHAR 'A'

int main()
{
	int r;
	int c;
	for (r = 0; r < NUM_ROWS; ++r)
	{
		for (c = FIRST_GHAR; c <= FIRST_GHAR + r; ++c)
		{
			printf("%c", c);
		}
		printf("\n");
	}
	return 0;
}
