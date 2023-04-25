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
	int len = 0, printed = 0;
	char *s = va_arg(ap, char *);
	(void)params;

	if (s)
	{
		for (len = 0; *s; s++)
			len += 1;
		s -= 1;
		for (; len > 0; len--, s--)
			printed += writechar(*s);

	}
	return (printed);
}

/**
 * print_rot13 - prints a string in rot13 rotation
 * @ap: argument pointer
 * @params: parameters
 *
 * Return: string length
 */

int print_rot13(va_list ap, params_t *params)
{
	int i, j, len = 0, flag = 1;
	char ORIGINAL[] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
	char ROTATED[] = "NnOoPpQqRrSsTtUuVvWwXxYyZzAaBbCcDdEeFfGgHhIiJjKkLlMm";
	char *s = va_arg(ap, char *);
	(void)params;

	if (s)
	{
		for (i = 0; s[i]; i++)
		{
			for (j = 0; j < 52; j++)
				if (s[i] == ORIGINAL[j])
			{
					len += writechar(ROTATED[j]);
					flag = 0;
					break;
			}
			if (flag)
				len += writechar(s[i]);
			flag = 1;
		}
	}
	return (len);
}
