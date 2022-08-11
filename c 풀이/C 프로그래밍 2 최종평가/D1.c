#include <stdio.h>

int n;
int max = 1;

int pow(int num)
{
	int ans = 0;
	while (num != 0) {
		ans += (num % 10)*(num % 10);
		num /= 10;
	}
	return ans;
}

int in_arr(int *arr, int num)
{
	for (int i = 0; i < 1000; i++) {
		if (num == arr[i]) return 1;
	}
	return 0;
}

int is_happy(int num) //행복한 수 1 리턴
{
	int arr[1000] = { 0, };
	int i = 0; arr[0] = num;
	for (i = 0; ; i++) {
		int tmp = pow(arr[i]);
		if (tmp == 1) return 1;
		if (in_arr(arr, tmp)) return 0;
		arr[i + 1] = tmp;
	}
}

void func(void)
{
	for (int i = 1; i <= n; i++) {
		if (is_happy(i)) {
			if (i > max) max = i;
		}
	}
}

int main(void)
{
	scanf("%d", &n);
	func();
	printf("%d", max);
	return 0;
}
