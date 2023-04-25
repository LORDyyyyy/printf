#include "main.h"

/**
 * print_octal - print print octal
 * @ap: argument pointer
 * @params: parameter
 *
 * Return: bytes print
 */
int print_octal(va_list ap, params_t *params)
{
	unsigned long u_l;
	char *s;
	int x = 0;

	if (params->l_modifier)
		u_l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		u_l = (unsigned short int)va_arg(ap, unsigned int);
	else
		u_l = (unsigned int)va_arg(ap, unsigned int);
	s = convert(u_l, 8, CONVERT_UNSIGNED);

	if (params->hashtag_flag && u_l)
		*--s = '0';
	params->unsign = 1;
	return (x += print_number(s, params));
}

/**
 * print_hex - hex numbers lowercase
 * @ap: argument pointer
 * @params: parameter
 *
 * Return: bytes print
 */
int print_hex(va_list ap, params_t *params)
{
	unsigned long u_l;
	int x = 0;
	char *s;

	if (params->l_modifier)
		u_l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		u_l = (unsigned short int)va_arg(ap, unsigned int);
	else
		u_l = (unsigned int)va_arg(ap, unsigned int);

	s = convert(u_l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE);
	if (params->hashtag_flag && u_l)
	{
		*--s = 'x';
		*--s = '0';
	}
	params->unsign = 1;
	return (x += print_number(s, params));
}

/**
 * print_HEX - hex numbers upercase
 * @ap: passed argument
 * @params: parameter
 *
 * Return: bytes print
 */
int print_HEX(va_list ap, params_t *params)
{
	unsigned long u_l;
	int x = 0;
	char *s;

	if (params->l_modifier)
		u_l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		u_l = (unsigned short int)va_arg(ap, unsigned int);
	else
		u_l = (unsigned int)va_arg(ap, unsigned int);

	s = convert(u_l, 16, CONVERT_UNSIGNED);
	if (params->hashtag_flag && u_l)
	{
		*--s = 'X';
		*--s = '0';
	}
	params->unsign = 1;
	return (x += print_number(s, params));
}
