#include "main.h"

/**
 * get_precision - get precision
 * @params: paramete
 * @ap: pointers
 * @p: string
 *
 * Return: mew pointer
 */
char *get_precision(char *ptr, params_t *params, va_list ap)
{
	int x = 0;

	if (*ptr  != '.')
		return (ptr);
	ptr += 1;
	if (*ptr == '*')
	{
		x = va_arg(ap, int);
		ptr += 1;
	}
	else
	{
		while(_isdigit(*ptr))
			x = x * 10 + (*ptr++ - '0');
	}
	params->precision = x;
	return (ptr);
}
