#include "main.h"

/**
 * print_char - print a characte using _writecharater
 * @ap: the passed argument
 *
 * Return:1
 */
int print_char(va_list ap)
{
	_writechar(va_arg(ap, int));
	return (1);
}


/**
 * print_string - prints a string
 * @ap: the passed argument
 *
 * Return: string length
 */
int print_string(va_list ap)
{
	int len = 0;
	char *str = va_arg(ap, char *);

	if (str == NULL)
		str = "(null)";
	while (str[len])
	{
		_writechar(str[len]);
		len++;
	}
	return (len);
}


/**
 * print_precen - prints %
 * @ap: the pass ....
 *
 * Return: 1
 */
int print_precen(va_list ap)
{
	(void)ap;
	_writechar(37);
	return (1);
}

/**
 * print_int - prints an integer
 * @ap: the pass ...
 *
 * Return: the number of the digits
 */

int print_int(va_list ap)
{
	int len = print_number(va_arg(ap, int));

	return (len);
}
