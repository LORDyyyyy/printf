#include "main.h"

/**
 * print_address - prints tha address of a variable
 * @ap: passed argument
 * @params: parameters
 *
 * Return: number of printed chars.
 */

int print_address(va_list ap, params_t *params)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	char *s;

	if (!n)
	return (writestr("(nil)"));

	s = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE);
	*--s = 'x';
	*--s = '0';
	return (print_number(s, params));
}
