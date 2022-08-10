#include <stdio.h>

int r, c;
int a, b;

void red(void) //red로 시작하는 한 줄 그리기
{
	for (int i = 0; i < c; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < b; j++) printf("X");
		}
		else {
			for (int j = 0; j < b; j++) printf(".");
		}
	}
	printf("\n");
}

void white(void)
{
	for (int i = 0; i < c; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < b; j++) printf(".");
		}
		else {
			for (int j = 0; j < b; j++) printf("X");
		}
	}
	printf("\n");
}

void draw(void)
{
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < a; j++) {
			if (i % 2 == 0) red();
			else white();
		}
	}
}

int main(void)
{
	scanf("%d %d %d %d", &r, &c, &a, &b);
	draw();
	return 0;
}