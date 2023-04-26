#include "main.h"

/**
 * print_percent - this function prints string
 * @ap: pointer to the argument list
 * @params: pointer to the parameters struct
 * Return: the number of charachters printed
 */

int print_percent(va_list ap, prm_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_char - this function prints character
 * @ap: pointer to the argument list
 * @params: pointer to the parameters struct
 * Return: the number of charachters printed
 */

int print_char(va_list ap, prm_t *params)
{
	char padding_char = ' ';
	unsigned int padding = 1, num_chars = 0;
	unsigned int ch = va_arg(ap, int);

	if ((*params).minus_f)
		num_chars += _putchar(ch);
	while (padding++ < (*params).widths)
		num_chars += _putchar(padding_char);
	if (!(*params).minus_f)
		num_chars += _putchar(ch);
	return (num_chars);
}

/**
 * print_int -this function prints integer
 * @ap: pointer to the argument list
 * @params: pointer to the parameters struct
 * Return: the number of charachters printed
 */

int print_int(va_list ap, prm_t *params)
{
	long longer;

	if ((*params).modifier_l)
		longer = va_arg(ap, long);
	else if ((*params).modifier_h)
		longer = (short int)va_arg(ap, int);
	else
		longer = (int)va_arg(ap, int);
	return (print_number(convert(longer, 10, 0, params), params));
}

/**
 * print_string - this function prints string
 * @ap: pointer to the argument list
 * @params: pointer to the parameters struct
 * Return: the number of charachters printed
 */
int print_string(va_list ap, prm_t *params)
{
	char *string = va_arg(ap, char *);
	char padding_char = ' ';
	unsigned int padding = 0, num_chars = 0, x = 0, y;

	(void)params;
	switch ((int)(!string))
		case 1:
			string = NULL_STRING;

	y = padding = _strlen(string);
	if ((*params).precisions < padding)
		y = padding = (*params).precisions;

	if ((*params).minus_f)
	{
		if ((*params).precisions != UINT_MAX)
			for (x = 0; x < padding; x++)
				num_chars += _putchar(*string++);
		else
			num_chars += _puts(string);
	}
	while (y++ < (*params).widths)
		num_chars += _putchar(padding_char);
	if (!(*params).minus_f)
	{
		if ((*params).precisions != UINT_MAX)
			for (x = 0; x < padding; x++)
				num_chars += _putchar(*string++);
		else
			num_chars += _puts(string);
	}
	return (num_chars);
}

/**
 * print_S - this function custom format specifier
 * @ap: pointer to the argument list
 * @params: pointer to the parameters struct
 * Return: the number of charachters printed
 */

int print_S(va_list ap, prm_t *params)
{
	char *string = va_arg(ap, char *);
	int num_chars = 0;
	char *hex;

	if ((int)(!string))
		return (_puts(NULL_STRING));
	for (; *string; string++)
	{
		if ((*string > 0 && *string < 32) || *string >= 127)
		{
			num_chars += _putchar('\\');
			num_chars += _putchar('x');
			hex = convert(*string, 16, 0, params);
			if (!hex[1])
				num_chars += _putchar('0');
			num_chars += _puts(hex);
		}
		else
		{
			num_chars += _putchar(*string);
		}
	}
	return (num_chars);
}

