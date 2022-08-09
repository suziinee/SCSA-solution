#include <stdio.h>

int n, m;
int ans;

void func(void)
{
	int up = 0;
	for (int i = 0; i < 10; i++) {
		if ((n == 0) && (m == 0)) break;
		int tmp1 = n % 10; n /= 10;
		int tmp2 = m % 10; m /= 10;
		if (tmp1 + tmp2 + up < 10) {
			up = 0;
		}
		else {
			up = 1;
			ans += 1;
		}
	}

	if (ans == 0) printf("No carry operation.");
	else if (ans == 1) printf("%d carry operation.", ans);
	else printf("%d carry operations.", ans);
}

void main(void)
{
	scanf("%d %d", &n, &m);
	func();
}