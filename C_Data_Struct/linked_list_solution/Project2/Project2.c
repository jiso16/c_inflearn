#include <stdio.h>

struct node {
	char* data;
	struct node* next; //���� ��带 ������ �ʵ�
};

typedef struct node Node;
Node* head = NULL; // ���Ḯ��Ʈ ù��° ��� �ּҸ� ������ ������


//**ptr_head : ������ ���� head�� �ּҸ� �Ű������� �޴´�
void add_first(Node **ptr_head, char* item)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = item;
	temp->next = *ptr_head;
	*ptr_head = temp;
}