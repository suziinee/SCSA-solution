#include <stdio.h>

int n;
int p;
int arr[1000000];
int i = 2;

int func(void)
{
	arr[0] = n; arr[1] = n * n % p; arr[2] = (arr[1] * n) % p;
	for (;;) {
		int tmp = (arr[i] * n) % p;
		if ((i + 1) % 2 == 0) { //i가 1,3,5..
			int j = (i + 1) / 2; int flag = 0;
			if (arr[j] == arr[0]) {
				printf("0 if\n");
				for (int k = 0; k <= (i + 1) / 2 - 1; k++, j++) {
					if (arr[k] != arr[j]) {
						flag = 1; break;
					}
				}
				if (flag == 0) return i / 2;
			}
			else if (arr[j] == arr[1]) {
				printf("1 else\n");
				for (int k = 1; k <= (i + 1) / 2; k++, j++) {
					if (arr[k] != arr[j + 1]) {
						flag = 1; break;
					}
				}
				if (flag == 0) return i / 2;
			}
		}

		else { //i가 0,2,4...
			int j = (i / 2) + 1; int flag = 0;
			if (arr[j] == arr[0]) {
				for (int k = 0; k <= (i / 2); k++, j++) {
					if (arr[k] != arr[j]) {
						flag = 1; break;
					}
				}
				if (flag == 0) return (i / 2) + 1;
			}
			else if (arr[j] == arr[1]) {
				for (int k = 1; k <= (i / 2); k++, j++) {
					if (arr[k] != arr[j]) {
						flag = 1; break;
					}
				}
				if (flag == 0) return (i / 2);
			}
		}
		arr[i + 1] = tmp;
		i++;
	}
}

int main(void)
{
	scanf("%d %d", &n, &p);
	int ans = func();
	printf("%d", ans);
	return 0;
}