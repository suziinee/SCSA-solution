#include <stdio.h>

int n;
int happy[1000 + 10];
int unhappy[1000 + 10];
int max = -1;

int calcul(int num)
{
	int ret = 0;
	while (num) {
		ret += (num % 10) * (num % 10);
		num /= 10;
	}
	return ret;
}

int in_arr(int idx, int* p, int tmp)
{
	for (int i = 0; i < idx; i++) {
		if (p[i] == tmp) return 1;
	}
	return 0;
}

int is_happy(int num)
{
	int arr[1000 + 10] = { 0 };
	arr[0] = num; int i = 1;
	
	for (;;) {
		int tmp = calcul(arr[i - 1]); //tmp=arr[i]

		if ((happy[tmp]) || (tmp == 1)) { //arr를 모두 happy에 넣기
			for (int k = 0; k <= i; k++) {
				if (happy[arr[k]] == 0) happy[arr[k]] = 1;
			}
			return 1;
		}
		if ((in_arr(i, arr, tmp)) || (unhappy[tmp])) { //arr를 모두 unhappy에 넣기
			for (int k = 0; k <= i; k++) {
				if (unhappy[arr[k]] == 0) unhappy[arr[k]] = 1;
			}
			return 0;
		}

		arr[i++] = tmp;
	}
}

void func(void)
{
	for (int i = 1; i <= n; i++) {
		if (unhappy[i]) continue;
		if (happy[i]) {
			if (i > max) max = i;
			continue;
		}
		if (is_happy(i)) {
			if (i > max) max = i;
		}
	}
}

void main(void)
{
	scanf("%d", &n);
	func();
	printf("%d", max);
}
