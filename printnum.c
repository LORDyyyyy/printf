#include "main.h"

/**
 * print_number - just prints a number
 * @ap: the passed ....
 *
 * Return: it's len
 */
int print_number(va_list ap)
{
	int div = 1, len = 0, n = va_arg(ap, int);
	int nn;

	if (n < 0)
	{
		_writechar('-');
		n *= -1;
		len++;
	}
	nn = n;

	while (nn / div > 9)
		div *= 10;
	while (div != 0)
	{
		_writechar(nn / div + 48);
		len++;
		nn %= div;
		div /= 10;
	}
	return (len);
}
