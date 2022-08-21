#include <stdio.h>

#define MAX 1000
int n;
int stick[MAX + 10];

void input(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &stick[i]);
}

int min(void)
{
	int ret = 2000;
	for (int i = 0; i < n; i++) {
		if (stick[i] == 0) continue;
		if (stick[i] < ret) ret = stick[i];
	}
	return ret;
}

void cut(int tmp)
{
	for (int i = 0; i < n; i++) {
		if (stick[i] > 0) {
			stick[i] = (stick[i] < tmp) ? 0 : (stick[i] - tmp);
		}
	}
}

int count(void)
{
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (stick[i] != 0) cnt++;
	}
	return cnt;
}

void solve(void)
{
	printf("%d\n", n);
	for (;;) {
		int tmp = min();
		cut(tmp);
		int c = count();
		if (c == 0) break;
		printf("%d\n", c);
		
	}
}


int main(void)
{
	input();
	solve();
	return 0;
}