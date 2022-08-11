#include <stdio.h>

int n;
int p;
int arr[10000 + 10];

void put(void)
{
	arr[0] = n;
	for (int i = 1; i < 10000; i++) {
		arr[i] = arr[i - 1] * n % p;
	}
}

int func(void)
{	
	for (int i = 0; i < 5000; i++) { //시작지점
		for (int n = 1; n < 5000; n++) { //반복개수
			int flag = 0; int start = i;
			while ((start == 1 && n==1)||(start < n)) {
				if (arr[start] != arr[start + n]) {
					flag = 1; break;
				}
				start++;
			}
			if (flag == 0) return n;
		}
	}	
}

int main(void)
{
	scanf("%d %d", &n, &p);
	put();
	int ans = func();
	printf("%d", ans);
	return 0;
}