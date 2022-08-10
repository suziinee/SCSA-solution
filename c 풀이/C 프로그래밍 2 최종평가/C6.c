#include <stdio.h>

int num[3];
char op[2];
int ans;

void calcul(void)
{
	if (op[0] == '*' || op[0] == '/' || op[0] == '%') {
		ans = num[0];
		if (op[0] == '*') ans *= num[1];
		if (op[0] == '/') ans /= num[1];
		if (op[0] == '%') ans %= num[1];

		if (op[1] == '+') ans += num[2];
		if (op[1] == '-') ans -= num[2];
		if (op[1] == '*') ans *= num[2];
		if (op[1] == '/') ans /= num[2];
		if (op[1] == '%') ans %= num[2];
		return;
	}
	else {
		if (op[1] == '*' || op[1] == '/' || op[1] == '%') {
			ans = num[1];
			if (op[1] == '*') ans *= num[2];
			if (op[1] == '/') ans /= num[2];
			if (op[1] == '%') ans %= num[2];

			if (op[0] == '+') num[0] += ans;
			if (op[0] == '-') num[0] -= ans;
			ans = num[0];
			return;
		}
		else {
			ans = num[0];
			if (op[0] == '+') ans += num[1];
			if (op[0] == '-') ans -= num[1];
			if (op[1] == '+') ans += num[2];
			if (op[1] == '-') ans -= num[2];
			return;
		}
	}
}

int main(void)
{
	scanf("%d%c%d%c%d", &num[0], &op[0], &num[1], &op[1], &num[2]);
	calcul();
	printf("%d", ans);
	return 0;
}