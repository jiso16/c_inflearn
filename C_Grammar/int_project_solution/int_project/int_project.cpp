#include <limits.h>
#include <stdio.h>

int main()
{
	unsigned int binary = 0b11111111111111111111111111111111;
	unsigned int oct = 037777777777;
	unsigned int hex = 0xffffffff;
	
	
	printf("%u\n", binary);
	printf("%u\n", oct);
	printf("%u\n", hex);


	return 0;
}