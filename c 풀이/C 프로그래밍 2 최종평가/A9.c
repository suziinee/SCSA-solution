#include <stdio.h>

int n;
int card[200 + 10][3];
int score[200 + 10];

void input(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &card[i][j]);
		}
	}
}

void hashing(void)
{
	for (int j = 0; j < 3; j++) {
		int hash[100 + 10] = { 0, };
		for (int i = 0; i < n; i++) {
			hash[card[i][j]] += 1;
		}
		for (int i = 0; i < n; i++) {
			if (hash[card[i][j]] == 1) score[i] += card[i][j];
		}
	}
}

void output(void)
{
	for (int i = 0; i < n; i++) {
		printf("%d\n", score[i]);
	}
}

void main(void)
{
	input();
	hashing();
	output();
}