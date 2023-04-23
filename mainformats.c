#include "main.h"

/**
 * _writechar - just like write, print a single character
 * @c: the character to be printed
 *
 * Return: 1
 */
int _writechar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - print a characte using _writecharater
 * @ap: the passed argument
 *
 * Return:1
 */
int print_char(va_list ap)
{
	_writechar(va_arg(ap, int));
	return (1);
}


/**
 * print_string - prints a string
 * @ap: the passed argument
 *
 * Return: string length
 */
int print_string(va_list ap)
{
	int len = 0;
	char *str = va_arg(ap, char *);
	
	if (str == NULL)
		str = "(null)"
	while (str[len])
	{
		_writechar(str[len]);
		len++;
	}
	return (len);
}

