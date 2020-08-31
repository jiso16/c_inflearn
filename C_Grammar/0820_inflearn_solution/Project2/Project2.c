#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define LEN 101
struct book
{
	char name[LEN];
	char author[LEN];
};

void print_books(const struct book books[], int n);

int main()
{

	struct book my_book[3];
	my_book[0] = (struct book){ "The Great Gatsby", "F . Scott Fitzgerald" };
	my_book[1] = (struct book){ "Hamlet", "William Shakespeare" };
	my_book[2] = (struct book){ "The Odyssey", "Homer" };

	print_books(my_book, 3);

	return 0;

}

void print_books(const struct book books[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("Book %d : \"%s\" written by  \"%s\" \n", i + 1, books[i].name, books[i].author);
	}
}