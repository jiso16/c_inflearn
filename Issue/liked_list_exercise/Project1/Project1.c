#include <stdio.h>

struct node {
	char* data;
	struct node* next; //���� ��带 ������ �ʵ�
};

typedef struct node Node;
Node* head = NULL; // ���Ḯ��Ʈ ù��° ��� �ּҸ� ������ ������

int main()
{
	//�Ӹ���忡 ������ ����, ������ null�� �־���
	head = (Node*)malloc(sizeof(Node));
	head->data = "1";
	head->next = NULL;

	Node* node2 = (Node*)malloc(sizeof(Node));
	node2->data = "2";
	node2->next = NULL;
	//����� ������ node2�� ����Ŵ
	head->next = node2;

	Node* node3 = (Node*)malloc(sizeof(Node));
	node3->data = "3";
	node3->next = NULL;
	//node2 �� ������ node3����Ŵ
	node2->next = node3;

	Node* node4 = (Node*)malloc(sizeof(Node));
	node4->data = "4";
	node4->next = NULL;
	//node3 �� ������ node4����Ŵ
	node3->next = node4;

	// ���� head�� ����� ���� p �� ����
	Node* p = head;

	while (p != NULL)
	{
		printf("%s\n", p->data);
		p = p->next;
	}

	free(node4);	// ��� �޸� ����
	free(node3);    // ��� �޸� ����
	free(node2);    // ��� �޸� ����
	free(head);     // �Ӹ� ��� �޸� ����

}