#include "main.h"

/**
 * print_binary - print binary
 * @ap: argument argument
 * @params: parameter
 *
 * Return: bytes print
 */
int print_binary(va_list ap, params_t *params)
{
	unsigned int x = va_arg(ap, unsigned int);
	char *s = convert(x, 2, CONVERT_UNSIGNED);
	int y = 0;

	if (params->hashtag_flag && x)
		*--s = '0';
	params->unsign = 1;
	return (y += print_number(s, params));
}

/**
 * print_unsigned - print unsigned
 * @ap: passed argument
 * @params: parameter
 *
 * Return: bytes print
 */

int print_unsigned(va_list ap, params_t *params)
{
	unsigned long u_l;

	if (params->l_modifier)
		u_l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		u_l = (unsigned short int)va_arg(ap, unsigned int);
	else
		u_l = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (print_number(convert(u_l, 10, CONVERT_UNSIGNED), params));
}
