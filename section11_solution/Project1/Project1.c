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
	int ret = scanf("%10s", input);// �����ڸ� �е��� ����, ������ ��ĭ �߽߰� �ű������ ���
	printf("%s\n", input);
	ret = scanf("%10s", input);
	printf("%s\n", input);
}