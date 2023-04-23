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
