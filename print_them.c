#include "main.h"

/**
 * print_them - takes the format from _printf and control the %
 * @format: the full string from printf
 * @ap: all argumentents in _printf
 * @go_to_function: holds specifiers and functions' pointers
 *
 * Return: the length
 */
int print_them(const char *format, va_list ap, formats_t go_to_function[])
{
	int i, j, printed_count = 0, len_function;

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; go_to_function[j].scp; j++)
			{
				if (format[i + 1] == go_to_function[j].scp[0])
				{
					len_function = go_to_function[j].f(ap);
					if (len_function == -1)
						return (-1);
					printed_count += len_function;
					break;
				}
			}
			if (!go_to_function[j].scp && format[i + 1] != ' ')
			{
				if (format[i + 1])
				{
					_writechar(format[i]);
					_writechar(format[i + 1]);
					printed_count += 2;
				}
				else
					return (-1);
			}

			i++;
		}
		else
		{
			_writechar(format[i]);
			printed_count++;
		}
	}
	return (printed_count);
}
