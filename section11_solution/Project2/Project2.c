#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void main()
{
	/*char msg[] = "Just, do it!";
	puts(msg);
	printf("Length %d\n", strlen(msg));
	fit_str(msg, 4);
	puts(msg);
	printf("Length %d\n", strlen(msg));
	*/

	char str[100] = "First string";
	char str2[] = "Second string";
	strcat(str, str2);
	puts(str);
	
	char stra[100] = "";
	int i = 123;
	double d = 3.14;
	sprintf(stra, "%05d.png %f", i, d);
	puts(stra);

	printf("%s\n", strchr("Hello Wolrd", 'W'));
	printf("%s\n", strpbrk("Hello Wolrd", "ABCDE"));
	printf("%s\n", strpbrk("Hello Wolrd", "abcde"));
	printf("%s\n", strrchr("Hello Wolrd", 'l'));
	printf("%s\n", strstr("Hello Wolrd", "wor"));
	printf("%s\n", strstr("Hello Wolrd", "Wor"));

}

void fit_str(char* str, unsigned int size)
{
	if (strlen(str) > size)
		str[size] = '\0';
}
