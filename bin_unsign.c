#include "main.h"

/**
 * print_binary - print binary
 * @ap: passed pointer
 * @params: parameter
 *
 * Return: bytes print
 */
int print_binary(va_list ap, params_t *params)
{
	unsigned int x = va_arg(ap, unsigned int);
	char *s = convert(x, 2, CONVERT_UNSIGNED, params);
	int y = 0;

	if (params->hashtag_flag && x)
		*--s = '0';
	params->unsign = 1;
	return (y += print_number(s, params));
}

