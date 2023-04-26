#include "main.h"

/**
 * print_octal - this function prints unsigned octal numbers
 * @ap: an Argument pointer
 * @params: A pointer to the struct.
 * Return: The number of bytes printed.
 */
int print_octal(va_list ap, prm_t *params)
{
	unsigned long longer;
	char *string;
	int n = 0;

	if ((*params).modifier_l)
		longer = (unsigned long)va_arg(ap, unsigned long);
	else if (params->modifier_h)
		longer = (unsigned short int)va_arg(ap, unsigned int);
	else
		longer = (unsigned int)va_arg(ap, unsigned int);
	string = convert(longer, 8, UNSIGNED_CONVERT, params);

	if ((*params).hashtag_f && longer)
		*--string = '0';
	(*params).unsign = 1;
	n += print_number(string, params);
	return (n);
}

/**
 * print_hexadecimal - this function prints unsigned hex numbers in lowercase
 * @ap: pointer to the argument list
 * @params: pointer to the parameters struct
 * Return: the number of bytes that were printed
 */
int print_hexadecimal(va_list ap, prm_t *params)
{
	int n = 0;
	unsigned long longer;
	char *string;

	if ((*params).modifier_l)
		longer = (unsigned long)va_arg(ap, unsigned long);
	else if ((*params).modifier_h)
		longer = (unsigned short int)va_arg(ap, unsigned int);
	else
		longer = (unsigned int)va_arg(ap, unsigned int);

	string = convert(longer, 16, UNSIGNED_CONVERT | LOWERCASE_CONVERSION, params);
	if ((*params).hashtag_f && longer)
	{
		*--string = 'x';
		*--string = '0';
	}
	(*params).unsign = 1;
	n += print_number(string, params);
	return (n);
}

/**
 * print_HEXADECIMAL - this function prints unsigned hex numbers in UPPERCASE
 * @ap: pointer to the argument list
 * @params: pointer to the parameters struct
 * Return: the number of bytes that were printed
 */

int print_HEXADECIMAL(va_list ap, prm_t *params)
{
	int n = 0;
	unsigned long longer;
	char *string;

	if ((*params).modifier_l)
		longer = (unsigned long)va_arg(ap, unsigned long);
	else if ((*params).modifier_h)
		longer = (unsigned short int)va_arg(ap, unsigned int);
	else
		longer = (unsigned int)va_arg(ap, unsigned int);

	string = convert(longer, 16, UNSIGNED_CONVERT, params);
	if ((*params).hashtag_f && longer)
	{
		*--string = 'X';
		*--string = '0';
	}
	(*params).unsign = 1;
	n += print_number(string, params);
	return (n);
}

/**
 * print_binary - This function takes an unsigned integer
 * and prints its binary equivalent
 * @ap: pointer to the argument passed as a va_list.
 * @params: A pointer to the struct.
 * Return: The number of bytes printed.
 */

int print_binary(va_list ap, prm_t *params)
{
	unsigned int Num = va_arg(ap, unsigned int);
	char *string = convert(Num, 2, UNSIGNED_CONVERT, params);
	int C = 0;

	if ((*params).hashtag_f && Num)
		*--string = '0';
	(*params).unsign = 1;
	C += print_number(string, params);
	return (C);
}
