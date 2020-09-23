#include <stdio.h>

struct node {
	char* data;
	struct node* next; //다음 노드를 저장할 필드
};

typedef struct node Node;
Node* head = NULL; // 연결리스트 첫번째 노드 주소를 저장할 포인터

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

	// 연결리스트 맨 앞에 Monday 추가 head = Monday
	//q-> node: Monday, next : null
	q = (Node*)malloc(sizeof(Node));
	q->data = "Monday";
	q->next = NULL;
	head->next = q;

	// 현재 head에 저장된 값을 p 에 저장
	Node* p = head;

	while (p != NULL)
	{
		printf("%s\n", p->data);
		p = p->next;
	}
}