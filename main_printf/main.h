#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUF_OUTPUT_SIZE 1024 /*task 4*/
#define BUFFER_FLUSH -1

#define FIELD_ BUF_SIZE 50

#define NULL_STRING "(null)"

#define INIT_PARAMS {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define LOWERCASE_CONVERSION	1
#define UNSIGNED_CONVERT	2

/**
 * struct _parameters - parameters struct
 * @unsign: flag to indicate if unsigned value is present
 * @plus_f: flag to indicate if plus_flag is specified
 * @space_f: flag to indicate if space_flag is specified
 * @hashtag_f: flag to indicate if hashtag_flag is specified
 * @zero_f: flag to indicate if zero_flag is specified
 * @minus_f: flag to indicate if minus_flag is specified
 * @widths: field width specified
 * @precisions: field precision specified
 * @modifier_h: flag to indicate if h_modifier is specified
 * @modifier_l: flag to indicate if l_modifier is specified
 */
typedef struct _parameters
{
	unsigned int unsign			: 1;	/* '-' or  '+' */

	unsigned int plus_f			: 1;
	unsigned int space_f		: 1;
	unsigned int hashtag_f		: 1;
	unsigned int zero_f			: 1;
	unsigned int minus_f		: 1;

	unsigned int widths;
	unsigned int precisions;

	unsigned int modifier_h		: 1;
	unsigned int modifier_l		: 1;
} prm_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifiers;
	int (*f)(va_list, prm_t *);
} speci_t;

/*** _puts and -putchar function | located in the _putchar.c file ***/
int _puts(char *s);
int _putchar(int z);

/***  _prinf fucntion | located in the _printf.c file  ***/
int _printf(const char *format, ...);

/*** All the print functions | located in the print_funcs.c file ***/
int print_char(va_list ap, prm_t *params);
int print_int(va_list ap, prm_t *params);
int print_string(va_list ap, prm_t *params);
int print_percent(va_list ap, prm_t *params);
int print_S(va_list ap, prm_t *params);

/*** number functions  | located in print_numb.c file ***/
char *convert(long int num, int base, int flags, prm_t *params);
int print_unsigned(va_list ap, prm_t *params); /*task 3*/
int print_address(va_list ap, prm_t *params);

/*** convert_number.c | located in the convert_numbers.c file ***/
int print_hexadecimal(va_list ap, prm_t *params);
int print_HEXADECIMAL(va_list ap, prm_t *params);
int print_binary(va_list ap, prm_t *params);
int print_octal(va_list ap, prm_t *params);

/*** simple printers functions | located in  ***/
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, prm_t *params); /* task 13 */
int print_rot13(va_list ap, prm_t *params);

/*** print numbers functions | located in the print_numbers.c file ***/
int _isdigit(int n);
int _strlen(char *str);
int print_number(char *str, prm_t *params);
int print_number_right_shift(char *str, prm_t *params);
int print_number_left_shift(char *str, prm_t *params);

/*** init params function | located in  parametters.c ***/
void init_params(prm_t *params, va_list ap);

/*** string fields function | located in precision.c ***/
char *get_precision(char *p, prm_t *params, va_list ap);

/*** specifier function  | located in specifiers.c ***/
int (*get_specifier(char *s))(va_list ap, prm_t *params);
int get_print_func(char *s, va_list ap, prm_t *params);
int get_flag(char *s, prm_t *params);
int get_modifier(char *s, prm_t *params);
char *get_width(char *s, prm_t *params, va_list ap);

#endif

