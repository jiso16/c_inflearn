#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 11.1. 문자열을 정의하는 방법

#define MESSAGE "A symbolic string contant"
#define MAXLENGTH 81

int main()
{
	char words[MAXLENGTH] = "A string in an array"; // 배열
	const char* ptr1 = "A pointer to a string"; 
	// 어딘가에 저장되어 있는 문자열 주소의 첫번째 주소를 가져옴

	puts("Puts() adds a newline at the end:");// 뒤에 새로운 라인을 알아서 덧붙여줌
	puts(MESSAGE);
	puts(words); // MAXLENGTH 만큼의 메모리를 초기화 해주지 않아서 warning이 뜸
	puts(ptr1);
	words[3] = 'p';
	puts(words);
	//ptr1[8] = 'A';  Error유발

	char greeting[50] = " Hello, and" "How are" "you" "today!";
	// 따옴표 사이의 띄어쓰기도 출력됨
	puts(greeting);

	printf("\"To be, or not to be\" Hamlet said.\n");

	printf("%s, %p, %c\n", "We", "are", *"Exellent programmers");

	const char m1[15] = "Love you!";
	
	for (int i = 0; i < 15; ++i)
	{
		printf("%d ", (int)m1[i]); // 문자열을 정수형으로 바꿈 - ascii code 출력
	}
	printf("\n");

	int n = 8;
	char cookies[1] = { 'A' };
	char cakes[2 + 5] = { 'A', };
	char pies[2 * sizeof(long double) + 1] = { 'A', };
}