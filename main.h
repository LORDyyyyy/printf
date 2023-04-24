#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct parameters - controls 'flags', 'width', 'length', and '.precision'
 * a boolian struct
 *
 * @unsign: true if unsigned
 * @plus_flag: true if plus flag exist
 * @space_flag: true if space flag exist
 * @hashtag_flag: true if ..............
 * @zero_flag: true if ................
 * @minus_flag: true if .............
 *
 * @width: field width if specified
 * @precision: field precision if specified
 *
 * @h_modifier: lenght, for short int
 * @l_modifier: lenght, for long int
 *
 */



typedef struct parameters
{
	unsigned int unsign : 1;

	unsigned int plus_flag : 1;
	unsigned int space_flag : 1;
	unsigned int hashtag_flag : 1;
	unsigned int zero_flag : 1;
	unsigned int minus_flag : 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier;
	unsigned int l_modifier;
} params_t;


/**
 * struct formats_struct - a struct that holds the functions
 * @scp: specifiers, and there is a file for every sepcifier "scp.c"
 * @f: function pointer to select the right function
 */
typedef struct formats_struct
{
	char *scp;
	int (*f)(va_list, params_t *);
} formats_t;

/* main printf.c */
int _printf(const char *format, ...);

/* the write function, writechar.c */
int writechar(int);
int writestr(char *);
int _strlen(char *);

/* print_1.c */
int print_char(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_precen(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);

/* give the parameter struct members its initial value,init_params.c*/
void init_params(params_t *params);

/* a file contains all specifiers,flags, and modifiers scp.c */
int (*get_scp(char *s))(va_list ap, params_t *params);
int get_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
int not_scp(char *start, char *end, char *except);

/* numbers methods are here, LORDy, printnum.c */
char *convert(long int num, int base, int flags);
int _isdigit(int c);
int print_number(char *str, params_t *params);

/* main functions, L, mainfunc.c */
int print_char(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);

/* width and precision, wid_pre.c */
char *get_precision(char *p, params_t *params, va_list ap);
char *get_width(char *s, params_t *params, va_list ap);

/* left and right padding, padding.c */
int print_n_right_pad(char *str, params_t *params);
int print_n_left_pad(char *str, params_t *params);

#endif
