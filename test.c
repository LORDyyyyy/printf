#include "main.h"
#include <stdio.h>

int main(void)
{
	char s1[] = "LORDyy", s2[] = "\0";
	char  z = '\0';
	int x, y;
	x = _printf("Test 1, %s %s %c %c %c %s %c %s %s %c ", s1, s2, 48, 0, z, "test_again", '\0', "\0", " ", 't');
	printf("\n");
	y = printf("Test 1, %s %s %c %c %c %s %c %s %s %c ", s1, s2, 48, 0, z, "test_again", '\0', "\0", " ", 't');
	printf("\n mine : %d , og : %d\n", x, y);
	return (0);
}
