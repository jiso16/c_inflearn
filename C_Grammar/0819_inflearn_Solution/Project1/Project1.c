#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

struct person // 구조체를 선언한다고 해서 메모리가 할당되는게 아님
{
	char name[MAX];
	int age;
	float height;
};

int main()
{
	int flag;

	struct person genie;
	strcpy(genie.name, "Will Smith");

	genie.age = 1000;

	flag = scanf("%f", &genie.height); //dot 연산자가 &주소연산자보다 우선순위 높음
	printf("%f\n", genie.height);

	struct person princess = { "Naomi Scott", 18, 160.0f }; // 초기화

	//초기화하는 다른 법
	struct person princness2 = {
		"Naomi Scott",
		18,
		160.0f
	};

	// 이렇게 초기화하면 순서 바뀌어도 됨
	struct person beauty = {
		.age = 19,
		.name = "Bell",
		.height = 165.0f
	};

	struct person* someone;

	someone = &genie;

	someone->age = 1001; //포인터로 접근하기 때문에 dot대신 화살표 사용

	printf("%s %d\n", someone->name, (*someone).age);

	struct book //함수안에서 구조체 사용 가능
	{
		char title[MAX];
	};

	struct {
		char farm[MAX];
		float price;
	} apple, apple2;
	//태그를 따로 안 정해주고 변수명만 정해줘도 됨

	typedef struct person my_person;

	my_person p3;

}