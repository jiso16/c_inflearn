#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	char buffer[40];
	printf("$ ");
	gets(buffer);
	printf("%s:%d\n", buffer, strlen(buffer));
}