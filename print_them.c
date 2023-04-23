#include "main.h"

/**
 * print_them - takes the format from _printf and control the %
 * @format: the full string from printf
 * @ap: all argumentents in _printf
 * @go_to_function: holds specifiers and functions' pointers
 *
 * Return: the length
 */
int print_them(const char *format, va_list ap, formats_t goto_func[])
{
	int i, j, printed_count = 0, len_func;

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			int flag = 0;

			for (j = 0; goto_func[j].scp && format[i + 1]; j++)
			{
				if (goto_func[j].scp[0] == format[i + 1])
				{
					len_func = goto_func[j].f(ap);
					if (len_func == -1)
						return(-1);
					printed_count += len_func;
					i++;
					flag = 1;
					break;
				}
			}
			if (!flag)
			{
				if (format[i + 1])
				{	
					_writechar(format[i + 1]);
					_writechar(format[i]);
					printed_count += 2;
				}
				else
				{
					_writechar(format[i]);
					printed_count++;
				}
			}
		}
		else
		{
			_writechar(format[i]);
			printed_count++;
		}

	}
	return (printed_count);
}
