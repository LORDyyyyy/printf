#include "main.h"

/**
 * print_number - just prints a number
 * @n: the number
 *
 * Return: it's len
 */
int print_number(int n)
{
	int i = 1, dig, len = 0, nn;

	if (n < 0)
	{
		_writechar('-');
		n *= -1;
		len++;
	}

	nn = n;
	while (nn > 0)
	{
		len++;
		nn /= 10;
		i *= 10;
	}
	i /= 10;

	while (i > 0)
	{
		dig = (n / i) % 10;
		_writechar(dig + 48);
		i /= 10;
	}
	return (len);
}
