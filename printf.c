#include "main.h"


/**
 * _printf - just like printf my friend
 * @format: the string which contains everything
 *
 * Return: the length of format
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int printed_len = 0;
	char *p, *start;
	params_t params = {0};

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (p = (char *)format; *p; p++)
	{
		init_params(&params);
		if (*p != '%')
		{
			writechar(*p);
			printed_len++;
			continue;
		}
		start = p;
		p++;

		while (get_flag(p, &params))
			p++;
		p = get_width(p, &params, ap);
		p = get_precision(p, &params, ap);
		if (get_modifier(p, &params))
			p++;
		if (get_scp(p))
			printed_len += get_func(p, ap, &params);
		else
			printed_len += not_scp(start, p,
					params.l_modifier || params.h_modifier ? p - 1 : 0);
	}
	writechar(BUF_FLUSH);
	va_end(ap);
	return (printed_len);
}
