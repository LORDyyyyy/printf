#include "main.h"


/**
 * print_rev - prints a reversed string
 * @ap: passed argument
 * @params: parameters
 *
 * Return: string length
 */

int print_rev(va_list ap, params_t *params)
{
	int len, printed = 0;
	char *s = va_arg(ap, char *);
	(void)params;

	if (s)
	{
		len = _strlen(s);
		for (; *s; s++)
			s--;
		for (; len > 0; len--, s--)
			printed += writechar(*s);
	}
	return (printed);
}
