#include <stdio.h>

struct node {
	char* data;
	struct node* next; //다음 노드를 저장할 필드
};

typedef struct node Node;
Node* head = NULL; // 연결리스트 첫번째 노드 주소를 저장할 포인터


//**ptr_head : 포인터 변수 head의 주소를 매개변수로 받는다
void add_first(Node **ptr_head, char* item)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = item;
	temp->next = *ptr_head;
	*ptr_head = temp;
}