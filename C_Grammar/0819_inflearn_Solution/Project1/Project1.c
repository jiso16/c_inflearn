#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

struct person // ����ü�� �����Ѵٰ� �ؼ� �޸𸮰� �Ҵ�Ǵ°� �ƴ�
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

	flag = scanf("%f", &genie.height); //dot �����ڰ� &�ּҿ����ں��� �켱���� ����
	printf("%f\n", genie.height);

	struct person princess = { "Naomi Scott", 18, 160.0f }; // �ʱ�ȭ

	//�ʱ�ȭ�ϴ� �ٸ� ��
	struct person princness2 = {
		"Naomi Scott",
		18,
		160.0f
	};

	// �̷��� �ʱ�ȭ�ϸ� ���� �ٲ� ��
	struct person beauty = {
		.age = 19,
		.name = "Bell",
		.height = 165.0f
	};

	struct person* someone;

	someone = &genie;

	someone->age = 1001; //�����ͷ� �����ϱ� ������ dot��� ȭ��ǥ ���

	printf("%s %d\n", someone->name, (*someone).age);

	struct book //�Լ��ȿ��� ����ü ��� ����
	{
		char title[MAX];
	};

	struct {
		char farm[MAX];
		float price;
	} apple, apple2;
	//�±׸� ���� �� �����ְ� ������ �����൵ ��

	typedef struct person my_person;

	my_person p3;

}