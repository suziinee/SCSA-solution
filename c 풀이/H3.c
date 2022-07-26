#include <stdio.h>

int func(int n)
{
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (n%i == 0) {
			if (i <= n / i) {
				(n / i) == i ? (res += 1) : (res += 2);
			}
			else return res;
		}
	}
}

void main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	int ans = 1;
	
	for (int i = n; i <= m; i++) {
		if (func(i) > func(ans)) ans = i;
	}
	printf("%d", ans);
}
		
    
    