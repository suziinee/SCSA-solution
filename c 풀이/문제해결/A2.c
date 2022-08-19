#include <stdio.h>

#define MAX 1000
int n;
int arr[MAX + 10];

int calcul(int num)
{
	int ret = 0;
	while (num) {
		ret += (num % 10)*(num % 10);
		num /= 10;
	}
	return ret;
}

int happy(int num)
{
	arr[num] = 1;
	while (num != 1) {
		num = calcul(num);
		if (arr[num]) return 0; //반복된 수면 행복한 수가 아님
		arr[num]++;
	}
	return 1;
}

void solve(void)
{
	for (int i = n; i >= 1; i--) {
		if (arr[i]) continue;
		if (happy(i) == 1) {
			printf("%d", i);
			break;
		}
	}
}


void main(void)
{
	scanf("%d", &n);
	solve();
}