#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char str[60] = "String array initialized";
	const char* ptr = "A Pointer initialized";

	puts("String without\n");
	puts("END");
	printf("START\n");
	
	char input[100] = "";
	int ret = scanf("%10s", input);// 열글자를 읽도록 강제, 하지만 빈칸 발견시 거기까지만 출력
	printf("%s\n", input);
	ret = scanf("%10s", input);
	printf("%s\n", input);
}