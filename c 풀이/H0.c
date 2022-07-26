#include <stdio.h>

void func(int n)
{
	while (n) {
		printf("%d", n % 10);
		n /= 10;
	}
}

void main(void)
{
	int n;
	scanf("%d", &n);
	func(n);
}
		
    
    