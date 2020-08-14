#include <stdio.h>

extern int el;

void testLinkage()
{
	printf("Do Somthing called\n");
	printf("%d\n", el);

	el++;
}