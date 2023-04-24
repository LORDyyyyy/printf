#include "main.h"

/**
 * print_char - prints a char
 * @ap: the passed argument
 * @params: the parameters struct
 *
 * Return: printed output length
 */
int print_char(va_list ap, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(ap, int);

	if (params->minus_flag)
		sum += writechar(ch);

	while (pad++ < params->width)
		sum += writechar(pad_char);

	if (!params->minus_flag)
		sum += writechar(ch);
	return (sum);
}

/**
 * print_string - prints a string
 * @ap: the passed argument
 * @params: the parameters struct
 *
 * Return: printed output length
 */
int print_string(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *), pad_char = ' ';
	unsigned int pad = 0, len = 0, i = 0, j;

	if (str == NULL)
		str = "(null)";

	j = pad = _strlen(str);

	if (params->precision < pad)
		j = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				len += writechar(*str++);
		else
			len += writestr(str);
	}

	while (j++ < params->width)
		len += writechar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				len += writechar(*str++);
		else
			len += writestr(str);
	}
	return (len);
}

/**
 * print_percent - prints '%' symbol
 * @ap: the passed argument
 * @params: the parameters struct
 *
 * Return: 1
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (writechar('%'));
}

/**
 * print_int - prints an integer
 * @ap: passed argument
 * @params: parameters
 *
 * Return: No. of digits printed
 */
int print_int(va_list ap, params_t *params)
{
	long n;

	if (params->h_modifier)
		n = (short int)va_arg(ap, int);
	else if (params->l_modifier)
		n = va_arg(ap, long);
	else
		n = (int)va_arg(ap, int);

	return (print_number(convert(n, 10, 0), params));
}
