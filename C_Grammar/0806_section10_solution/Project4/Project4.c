#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 11.3문자열의 배열
int main()
{
	const char* mythings[5] = {
		"Dancing in the rain",
		"Counting apples",
		"Watching moveids with friends",
		"Writing sad letters",
		"Studying the C language"
	};
	char yourtings[5][40] = {
		"Studying the C++ language",
		"eating",
		"watching Netfilx",
		"Walking around till dark",
		"Edleting spam emails"
	};
	
	const char* temp1 = "Dancing in the rain";
	const char* temp2 = "Studying the C++ language";

	printf("%s %u %u\n", mythings[0], (unsigned)mythings[0], (unsigned)temp1);
	//(unsigned)mythings[0], (unsigned)temp1 두개의 메모리 값이 똑같이 출력됨 - 포인터이기 때문
	printf("%s %u %u\n", yourtings[0], (unsigned)yourtings[0], (unsigned)temp2);
	//(unsigned)yourtings[0], (unsigned)temp2 두개의 메모리 값이 다르게 출력된 - 스텍에 복사해서 들어가기 때문

	
	// 이 아래 코딩은 문자열을 한글자씩 출력 - 메모리 면에서 아주 안 좋은 코딩
	for (int i = 0; i < 100; i++)
	{
		printf("%c", mythings[0][i]);
	}
	printf("\n\n");

	for (int i = 0; i < 200; i++)
	{
		printf("%d", (int)yourtings[0][i]);
	}
	printf("\n");

	for (int i = 0; i < 200; i++)
	{
		printf("%c", (int)yourtings[0][i]);
	}
	printf("\n\n");
}
