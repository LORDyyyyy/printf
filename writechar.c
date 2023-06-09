#include "main.h"


/**
 * writechar - just like write, print a single character
 * @c: the character to be printed
 *
 * Return: 1
 */
int writechar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * writestr - prints a string
 * @str: the string
 *
 * Return: its len
 */
int writestr(char *str)
{
	int len = 0;

	while (str[len])
	{
		writechar(str[len]);
		len++;
	}
	return (len);
}

/**
 * _strlen - return the string length
 * @s: string
 *
 * Return: s length
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}
