#include <stdio.h>

struct node {
	char* data;
	struct node* next; //다음 노드를 저장할 필드
};

typedef struct node Node;
Node* head = NULL; // 연결리스트 첫번째 노드 주소를 저장할 포인터

int main()
{
	//머리노드에 데이터 저장, 다음은 null로 넣어줌
	head = (Node*)malloc(sizeof(Node));
	head->data = "1";
	head->next = NULL;

	Node* node2 = (Node*)malloc(sizeof(Node));
	node2->data = "2";
	node2->next = NULL;
	//헤드의 다음은 node2를 가르킴
	head->next = node2;

	Node* node3 = (Node*)malloc(sizeof(Node));
	node3->data = "3";
	node3->next = NULL;
	//node2 의 다음은 node3가르킴
	node2->next = node3;

	Node* node4 = (Node*)malloc(sizeof(Node));
	node4->data = "4";
	node4->next = NULL;
	//node3 의 다음은 node4가르킴
	node3->next = node4;

	// 현재 head에 저장된 값을 p 에 저장
	Node* p = head;

	while (p != NULL)
	{
		printf("%s\n", p->data);
		p = p->next;
	}

	free(node4);	// 노드 메모리 해제
	free(node3);    // 노드 메모리 해제
	free(node2);    // 노드 메모리 해제
	free(head);     // 머리 노드 메모리 해제

}