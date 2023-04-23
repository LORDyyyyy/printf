#include "main.h"

/**
 * print_them - takes the format from _printf and control the %
 * @format: the full string from printf
 * @ap: all argumentents in _printf
 * @goto_func: holds specifiers and functions' pointers
 *
 * Return: the length
 */
int print_them(const char *format, va_list ap, formats_t goto_func[])
{
	int i, j, printed_count = 0, len_function;

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			for (j = 0; goto_func[j].scp; j++)
			{
				if (format[i + 1] == goto_func[j].scp[0])
				{
					len_function = goto_func[j].f(ap);
					printed_count += len_function;
					break;
				}
			}
			if (!goto_func[j].scp && format[i + 1])
			{
				_writechar(format[i]);
				_writechar(format[i + 1]);
				printed_count += 2;
			}
			else
			{
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
