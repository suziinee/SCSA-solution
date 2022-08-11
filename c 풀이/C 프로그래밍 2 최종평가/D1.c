#include <stdio.h>

int n;
int max = 1;
int hash[100000];

int pow(int num)
{
	int ans = 0;
	while (num != 0) {
		ans += (num % 10)*(num % 10);
		num /= 10;
	}
	return ans;
}

int is_happy(int num) //행복한 수 1 리턴
{
	int tmp = num;
	for (int i = 0; i < 1000; i++) {
		int p = pow(tmp);
		if (p == 1) return 1;
		tmp = p;
	}
	return 0;
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if (is_happy(i)) {
			if (i > max) max = i;
		}
	}
	printf("%d", max);
	return 0;
}