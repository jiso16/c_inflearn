#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void display(char cr, int lines, int width);

int main()
{
	char c;
	int rows, cols;

	printf("Input one charatr and two integers:\n");
	while ((c = getchar()) != '\n')
	{
		scanf("%d %d", &rows, &cols);
		while (getchar() != '\n') // 버퍼 내용 지우기
		{
			continue;
		}
		display(c, rows, cols);
		printf("Input another character and two integers:\n");
		printf("Press ENster to quit.\n");
	}
	return 0;
}

void display(char cr, int lines, int width)
{}