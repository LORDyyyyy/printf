#include "main.h"

/**
 * _printf - just like printf my friend
 * @format: the string with contains everything
 *
 * Return: the length of format
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int printed_count = 0;
	formats_t go_to_function[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_precen},
		{NULL, NULL}
	};

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	printed_count = print_them(format, ap, go_to_function);
	va_end(ap);
	return (printed_count);
}
