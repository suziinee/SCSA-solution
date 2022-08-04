#include <stdio.h>

char s_str[110]; // src
char d_str[110]; // dest

void Upper_Change(char* dest, char* src)
{
	while (*src) *dest++ = *src++ - 32;
}

int main(void)
{
	scanf("%s", s_str);
	Upper_Change(d_str, s_str);
	printf("%s", d_str);
	return 0;
}