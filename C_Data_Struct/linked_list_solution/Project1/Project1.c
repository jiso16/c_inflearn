#include <stdio.h>

struct node {
	char* data;
	struct node* next; //���� ��带 ������ �ʵ�
};

typedef struct node Node;
Node* head = NULL; // ���Ḯ��Ʈ ù��° ��� �ּҸ� ������ ������

int main()
{
	// node: Tuesday, next: Null
	head = (Node*)malloc(sizeof(Node));
	head->data = "Tuesday";
	head->next = NULL;

	//q -> node: Tursday, next: null
	Node* q = (Node*)malloc(sizeof(Node));
	q->data = "Tursday";
	q->next = NULL;
	head->next = q;

	// ���Ḯ��Ʈ �� �տ� Monday �߰� head = Monday
	//q-> node: Monday, next : null
	q = (Node*)malloc(sizeof(Node));
	q->data = "Monday";
	q->next = NULL;
	head->next = q;

	// ���� head�� ����� ���� p �� ����
	Node* p = head;

	while (p != NULL)
	{
		printf("%s\n", p->data);
		p = p->next;
	}
}