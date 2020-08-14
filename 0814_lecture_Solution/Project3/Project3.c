#include <stdio.h>

int el;
static int i1; //현재 scope로 제한함

void testLinkage();

int main()
{
	el = 1024;

	testLinkage();

	printf("%d", el);
	return 0;
}