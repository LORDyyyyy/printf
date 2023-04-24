#include "main.h"


/**
 * get_scp - to selec the right specifier to print
 * @s: the string to check if its a specifier or not
 *
 * Return: the length of the printed string/number
 */
int (*get_scp(char *s))(va_list ap, params_t *params)
{
	formats_t goto_func[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"i", print_int},
		{"d", print_int},
		{NULL, NULL}
	};
	int i;

	for (i = 0; goto_func[i].scp; i++)
		if (*s == goto_func[i].scp[0])
			return (goto_func[i].f);
	return (NULL);
}

/**
 * get_func - if get_scp did not return NULL, thats mean that is a function,
 * so get_func will get the function the return the len of the output
 * @s: the spicifier
 * @ap: passed argument
 * @params: the parameters struct
 *
 * Return: outpur len on success
 */
int get_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_scp(s);

	if (f)
		return (f(ap, params));
	return (0);
}

/**
 * not_scp - if there is no specifier, call not_scp
 * @start: starting point to print
 * @end: end point
 * @except: do not print h or l if exist
 *
 * Return: output length
 */
int not_scp(char *start, char *end, char *except)
{
	int len = 0;

	while (start <= end)
	{
		if (start != except)
		{
			writechar(*start);
			len++;
		}
		start++;
	}
	return (len);
}

/**
 * get_flag - check if there is a flag
 * @s: the character
 * @params: the parameters struct
 *
 * Return: is flag exist, 1, 0 otherwise
 */
int get_flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
		default:
			i = 0;
	}
	return (i);
}

/**
 * get_modifier - check if there is a modifier
 * @s: the character to check
 * @params: the parameters struct
 *
 * Return: is flag exist, 1, 0 otherwise
 */
int get_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = params->h_modifier = 1;
			break;
		case 'l':
			i = params->l_modifier = 1;
			break;
		default:
			i = 0;
			break;
	}
	return (i);
}
