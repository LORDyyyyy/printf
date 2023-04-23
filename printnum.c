#include "main.h"

/**
 * print_number - just prints a number
 * @n: the number
 *
 * Return: it's len
 */
int print_number(int n)
{
	int div = 1, len = 0, nn;

	if (n < 0)
	{
		_writechar('-');
		n *= -1;
		len++;
	}
	nn = n;

	while (nn / div > 9)
		div *= 10;
	while (div)
	{
		_writechar(nn / div + 48);
		nn %= div;
		div /= 10;
	}
	return (len);
}
