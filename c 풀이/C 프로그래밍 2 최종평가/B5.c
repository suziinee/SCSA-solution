#include <stdio.h>

int n;
int arr[300 + 10];
int res[3];
int ans;

int is_Pita(int a, int b, int c)
{
	if (a*a + b * b == c * c) return 1;
	return 0;
}

void dfs(int L, int BeginWith)
{
	if (L == 3) {
		if (is_Pita(res[0], res[1], res[2])) ans += 1;
	}
	else {
		for (int i = BeginWith; i <= n; i++) {
			res[L] = arr[i];
			dfs(L + 1, i + 1);
		}
	}
}


void main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}
	dfs(0, 1);
	printf("%d", ans);
}