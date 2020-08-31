#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int ch;
	FILE* fr; // 파일을 읽기위한 파일의 포인터

	unsigned long count = 0;

	if (argc != 2)
	{
		printf("usage: %s filemane\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fr = fopen(argv[1], "r") == NULL)) //open a text file for reading
	{
		printf("Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((ch = fgetc(fr)) != EOF)
	{
		fputc(ch, stdout);

		count++;
	}
	fclose(fr);

	printf("File %s has %lu characters\n", argv[1], count);
}