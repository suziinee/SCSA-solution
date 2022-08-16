#include <stdio.h>

int n;
int cnt;
int arr[10000 + 10];
int res[2];

void dfs(int L, int BeginWith)
{
	if (L == 2) {
		cnt++; 
		return;
	}
	else {
		for (int i = BeginWith; i <= n; i++) {
			res[L] = arr[i];
			dfs(L + 1, i);
		}
	}
}

void main(void)
{
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) arr[i] = i;
	dfs(0, 0);
	printf("%d", cnt);
}