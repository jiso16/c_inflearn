#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	enum spectrum{red, orange, yellow, green, blue, violet};

	enum spectrum color;

	color = blue;

	if(color == yellow)
	{ 
		printf("yellow");
	}
	for (color = red; color <= violet; color++) // 정수형이기 때문에 증가연산자, 비교 다 가능
	{
		printf("%d\n", color);
	}

	enum kids {jackjack, dash, snoopy, nano, pitz};

	enum kids my_kids = nano;
	printf("nano %d %d\n", my_kids, nano);

	enum levels { low = 100, medium = 300, high = 500 };

	int score = 300;

	if (score > high)
	{
		printf("High Score\n");
	}
	else if (medium < score < high)
	{
		printf("Good Score\n");
	}
	else if (score < medium)
		printf("SoSo..");
}