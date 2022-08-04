#include <stdio.h>

char str[30 + 10];
char sol;
int cnt[26];

void max_cnt(void)
{
	int max_idx = 0;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] > cnt[max_idx]) max_idx = i;
	}
	sol = ('a' + max_idx);
}

void func(char* p)
{
	while (*p) {
		if (('a' <= (*p)) && ('z' >= (*p))) cnt[(*p) - 'a']++;
		p++;
	}
	max_cnt();
}

int main(void)
{
	// 입력받는 부분
	scanf("%s", str);

	func(str);

	// 출력하는 부분
	printf("%c", sol);

	return 0;
}