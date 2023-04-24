#include "main.h"

/**
 * get_width - get the width from string
 * @params: parameter
 * @ap: passed parameter
 * @s: string
 *
 * Return: the pointer for get_width
 *
 */
char *get_width(char *s, params_t *params, va_list ap)
{
	int x = 0;

	if (*s == '*')
	{
		x = va_arg(ap, int);
		s += 1;
	}
	else
	{
		while (_isdigit(*s))
			x = x * 10 + (*s++ - '0');
	}
	params->width = x;
	return (s);
}
