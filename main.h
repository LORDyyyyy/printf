#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct formats_struct - a struct that holds the functions
 * @scp: specifiers
 * @f: function pointer to select the right function
 */
typedef struct formats_struct
{
	char *scp;
	int (*f)(va_list);
} formats_t;

int _printf(const char *format, ...);
int _writechar(char c);
int print_them(const char *format, va_list ap, formats_t goto_func[]);
int print_char(va_list ap);
int print_string(va_list ap);
int print_precen(va_list ap);
int print_number(va_list ap);
int print_int(va_list ap);
int print_uint(va_list ap);

#endif
