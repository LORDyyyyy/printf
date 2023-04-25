#include "main.h"

/**
 * print_S - prints the string, a specific characters only
 * Non printable characters (0 < ASCII < 32 or >= 127) are printed this way:
 * \x, followed by the ASCII code in hexadecimal (upper case)
 * @ap: passed argument
 * @params: parameters
 *
 * Return: S length
 */

int print_S(va_list ap, params_t *params)
{
	char *s = va_arg(ap, char *), *hex;
	int len = 0;

	if (!s)
		return (writestr("(null)"));
	while (*s)
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
	{
		len += writechar('\\');
		len += writechar('x');
		hex = convert(*s, 16, params);
		if (!hex[1])
			len += writechar(48);
		len += writestr(hex);
	}
	else
		len += writechar(*s);
	s++;
	}
	return (len);
}
