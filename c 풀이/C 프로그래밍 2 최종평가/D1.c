#include <stdio.h>

int n;
int max = 1;
int happy[100000];
int unhappy[100000];

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

int is_happy(int num) //happy[i]==0인 수만 들어옴
{
	int arr[1000] = { 0, };
	int i = 0; arr[0] = num;
	for (i = 0; ; i++) {
		int tmp = pow(arr[i]);
		if (happy[tmp] || (tmp == 1)) { //arr를 모두 happy에 넣음
			for (int j = 0; j <= i + 1; j++) {
				if (happy[arr[j]] == 0) happy[arr[j]] = 1;
			}
			return 1;
		}
		if (unhappy[tmp] || (in_arr(arr, tmp))) { //arr를 모두 unhappy에 넣음
			for (int j = 0; j <= i + 1; j++) {
				if (unhappy[arr[j]] == 0) unhappy[arr[j]] = 1;
			}
			return 0;
		}
		arr[i + 1] = tmp;
	}
}

void func(void)
{
	for (int i = 1; i <= n; i++) {
		if (happy[i]) {
			if (i > max) max = i;
		}
		if (unhappy[i]) continue;
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