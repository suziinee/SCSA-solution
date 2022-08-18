#include <stdio.h>

int a, b;
int min = -1;
int max = -1;
int arr[100000]; 
int cnt;

void func(void)
{
	for (int i = 2; i*i <= b; i++) {
		if (arr[i] == 0) {
			int j = 2; 
			while (i*j <= b) {
				if (arr[i*j] == 0) arr[i*j] = 1; //소수가 아니면 1
				j++;
			}
		}
	}

	for (int i = a; i <= b; i++) {
		if (arr[i] == 0) {
			max = i;
			if (min == -1) min = i;
			cnt++;
		}
	}

	printf("max:%d min:%d\n", max, min);
}

void main(void)
{
	scanf("%d %d", &a, &b);
	if (a == 1) a = 2;
	func();
	printf("%d\n%d", cnt, min + max);
}