#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <iso646.h>

#define STOP '.'
int main()
{
	char c;
	int n_chars = 0;
	int n_lines = 0;
	int n_words = 0;

	bool word_flag = false;
	bool line_flag = false;

	printf("Enter text:");

	while ((c=getchar())!=STOP)
	{
		if (isspace(c) == false)
		{
			n_chars++;
		}
		else if (!isspace(c) && !line_flag)
		{
			n_lines++;
			line_flag = true;
		}
		else if (c == '\n')
		{
			n_words++;
			line_flag = false;
			
		}
	}
	printf("characers = %d, words=%d, line=%d", n_chars, n_lines, n_words);
}