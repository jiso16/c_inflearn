#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

enum spectrum { red, orange, yellow, green, blue, violet };

const char* colors[] = { "red", "orange", "yellow","green","blue" };

#define LEN 30

int main()
{
	char choice[LEN] = { 0, };
	enum spectrum color;

	bool color_is_found = false;

	while (1)
	{
		puts("Input a color name (empty line to quit): ");
		
		if (scanf("%[^\n]%*c", choice) != 1)
		{
			break;
		}
		for (color = red; color <= blue; color++)
		{
			if (strcmp(choice, colors[color]) == 0)
			{
				color_is_found = true;
				break;
			}
		}
	}
}