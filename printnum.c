#include "main.h"

/**
 * convert - a function to convert the base, and convert it to a string
 * @num: number to convert , in base 10.
 * @base: what base to convert
 * @flags: if (10)2 then unsigned and CAPTIAL when hex
 * else if (11)2 then unsigned and lower when hex
 *
 * Return: the number in a string
 */
char *convert(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *p;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buffer[49];
	*p = '\0';

	do {
		*--p = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--p = sign;
	return (p);
}

/**
 * print_number - prints a number as string
 * @str: the string
 * @params: the parameters struct
 *
 * Return: printed output length
 */
int print_number(char *str, params_t *params)
{
	unsigned int i = _strlen(str);
	int neg = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '-';
	if (!params->minus_flag)
		return (print_n_right_pad(str, params));
	else
		return (print_n_left_pad(str, params));
}


/**
 * _isdigit - checks if the character is a digit or not
 * @c: the char
 *
 * Return: 1 if true
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
