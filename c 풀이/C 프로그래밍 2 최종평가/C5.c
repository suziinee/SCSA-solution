#include <stdio.h>

char a[100 + 10];
char b[100 + 10];
char ch;
int a_zero; int b_zero;

void input(void)
{
	scanf(" %s", a);
	scanf(" %c", &ch);
	scanf(" %s", b);
}

void mul(void)
{
	printf("1");
	for (int i = 0; i < a_zero + b_zero - 2; i++) printf("0");
}

void plus(void)
{
	if (a_zero > b_zero) {
		printf("1");
		for (int i = 1; i < a_zero; i++) {
			if (i == (a_zero - b_zero)) printf("1");
			else printf("0");
		}
	}
	else if (a_zero < b_zero) {
		printf("1");
		for (int i = 1; i < b_zero; i++) {
			if (i == (b_zero - a_zero)) printf("1");
			else printf("0");
		}
	}
	else if (a_zero == b_zero) {
		printf("2");
		for (int i = 1; i < a_zero; i++) {
			printf("0");
		}
	}
}

int main(void)
{
	input();
	int i = 0; int j = 0;
	while (a[i++]) a_zero++;
	while (b[j++]) b_zero++;
	if (ch == '*') mul();
	else if (ch == '+') plus();
	return 0;
}