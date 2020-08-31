#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


#define INIT_CAPACITY 3 //최대 100명 저장
#define BUFFER_SIZE 50

// names와 numbers는 char* 타입의 배열
char** names; //캐릭터 포인터 사용
char** numbers; // 전화번호부의 숫자는 문자로 다룸

int capacity = INIT_CAPACITY;
int n = 0;

int main()
{
	init_directory();
	process_command();

	return 0;
}

void init_directory()
{
	names = (char**)malloc(INIT_CAPACITY * sizeof(char*));
	numbers = (char**)malloc(INIT_CAPACITY * sizeof(char*));
}

int read_line(char str[], int limit) // 배열 str의 크기가 limit
{
	int ch, i = 0;
	while ((ch = getchar()) != '\n') //줄바꿈 나올때까지 읽음
		if (i < limit - 1) //배열 용량 안 넘을때만 저장
			str[i++] = ch;
	str[i] = '\0'; //마지막에 null character추가

	return i; //실제로 읽은 문자수 반환
}
