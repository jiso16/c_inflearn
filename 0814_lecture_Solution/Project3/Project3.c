#include <stdio.h>

int el;
static int i1; //���� scope�� ������

void testLinkage();

int main()
{
	el = 1024;

	testLinkage();

	printf("%d", el);
	return 0;
}