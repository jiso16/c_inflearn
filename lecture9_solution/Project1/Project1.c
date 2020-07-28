#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define WIDTH 20
#define NAME "sohee"
#define ADDRESS "seoul, gangbuk"

// 이 밑의 두개는 프로토타입
void print_multiple_chars(char c, int n_stars, bool printf_newline);
void print_centered_Str(char str[]);

int main()
{
	print_multiple_chars('*', WIDTH, true);// 함수를 사용할때는 매개변수의 argument 입력
	print_centered_Str(NAME);
	print_centered_Str(ADDRESS);
	print_centered_Str("I LOVE YOU");

	print_multiple_chars('*', WIDTH, false);
	
	return 0;
}

void print_multiple_chars(char c, int n_stars, bool printf_newline) // 매개변수
{
	for (int i = 0; i < n_stars; ++i)
	{
		printf("%c",c);
	}

	if (printf_newline)
	{
		printf("\n");
	}
}

void print_centered_Str(char str[])
{
	int n_blank = 0;
	n_blank = (WIDTH - strlen(str)) / 2;
	print_multiple_chars(' ', n_blank, false);
	printf("%s\n", str);
}