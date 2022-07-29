#include <stdio.h>

int nums[100000] = { 0 };
int mod[100000] = { 0 };
int ans = 0;

void func(long long int a)
{
	if (nums[a / 100000] == (a / 100000)) {
		if (mod[a % 100000] == (a % 100000)) {
			return;
		}
		else {
			ans += 1;
			mod[a % 100000] = (a % 100000);
			return;
		}
	}
	else {
		nums[a / 100000] = (a / 100000);
		mod[a % 100000] = (a % 100000);
		ans += 1;
		return;
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	long long int a;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a);
		func(a);
	}
	printf("%d", ans);
	return 0;
}