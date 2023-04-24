#include "main.h"

/**
 * print_n_right_pad -to add padding 'right'
 * @params: parameter
 * @s: the string
 *
 * Return: print char
 */
int print_n_right_pad(char *s, params_t *params)
{
	unsigned int x = 0, negative_a, negative_b, i = _strlen(s);
	char padding_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		padding_char = '0';
	negative_a = (!params->unsign && *s == '-');
	negative_b = (!params->unsign && *s == '-');
	if (negative_a && i < params->width && padding_char == '0' && !params->minus_flag)
		s += 1;
	else
		negative_a = 0;
	if ((params->plus_flag && !negative_b) || (!params->plus_flag && params->space_flag && !negative_b))
		i++;
	if (negative_a && padding_char == '0')
		x += writechar('-');
	if (params->plus_flag && !negative_b && padding_char == '0' && !params->unsign)
		x += writechar('+');
	else if (!params->plus_flag && params->space_flag && !negative_b && !params->unsign && params->zero_flag)
		x += writechar(' ');
	while (i++ < params->width)
		x += writechar(padding_char);
	if (negative_a && padding_char == ' ')
		x += writechar('-');
	if (params->plus_flag && !negative_b && padding_char == ' ' && !params->unsign)
		x += writechar('+');
	else if (!params->plus_flag && params->space_flag && !negative_b && !params->unsign && !params->zero_flag)
		x += writechar(' ');
	x += writestr(s);
	return (x);
}


/**
 * print_n_left_pad - to add padding 'left'
 * @params: parameter
 * @s: string
 *
 * Return: print char
 */

int print_n_left_pad(char *s, params_t *params)
{
	unsigned int x = 0, negative_a, negative_b, i = _strlen(s);
	char padding_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		padding_char = '0';
	negative_a = negative_b = (!params->unsign && *s == '-');
	if (negative_a && i < params->width && padding_char == '0' && !params->minus_flag)
		s++;
	else
		negative_a = 0;

	if (params->plus_flag && !negative_b && !params->unsign)
		x += writechar('+'), i++;
	else if (params->space_flag && !negative_b && !params->unsign)
		x += writechar(' '), i++;
	x += writestr(s);
	while (i++ < params->width)
		x += writechar(padding_char);
	return (x);
}
