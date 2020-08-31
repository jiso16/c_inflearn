#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define LEN 20

struct name {
	char given[LEN];
	char gamily[LEN];
};

struct friend{
	struct name full_name;
	char mobile[LEN];
};

int main()
{
	struct friend my_friends[2] = {
		{{"ariana", "Grande"}, "1234-1234"},
		{{"Taylor","Swift"}, "6555-5555"}
	};

	struct friend* girl_friend;

	girl_friend = &my_friends[0];
	
	printf("%zd\n", sizeof(struct friend));//friend의 사이즈 60
	printf("%lld %s\n", (long long)girl_friend, girl_friend->full_name.given);

	girl_friend++;

	printf("%lld %s\n", (long long)girl_friend, girl_friend->full_name.given);
	// 출력하면 사이즈 차이만큼 주소가 넘어가서 my_friends[1]이 출력됨
	return 0;
}