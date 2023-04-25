#include "main.h"

/**
 * _isdigit - this function checks if character is digit
 * @n: the character to check
 * Return: 1 if digit, else 0
 */
int _isdigit(int n)
{
		return (n >= '0' && n <= '9');
}

/**
 * _strlen - returns the length of a string
 * @str: the string whose length to check
 * Return: integer length of string
 */
int _strlen(char *str)
{
	int i = 0;

	while (*str++)
		i++;
	return (i);
}

/**
 * print_number - this function prints a number with optional formatting
 * @str: the string representation of the number
 * @params: pointer to the parameters struct
 * Return:  the number of characters printed to the output
 */
int print_number(char *str, prm_t *params)
{
	unsigned int num_digits = _strlen(str);
	int is_negative = (*str == '-' && !(*params).unsign);

	if (*str == '0' && !str[1] && !(*params).precisions)
		str = "";
	if (is_negative)
	{
		str++;
		num_digits--;
	}
	if ((*params).precisions != UINT_MAX)
		while (num_digits++ < (*params).precisions)
			*--str = '0';
	if (is_negative)
		*--str = '-';

	if (!(*params).minus_f)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_left_shift - prints a number with options
 * @str: the string representation of the number
 * @params: pointer to the parameters struct
 * Return: the number of characters printed to the output
 */
int print_number_left_shift(char *str, prm_t *params)
{
	unsigned int Num = 0, is_negative, is_negative2, num_digits = _strlen(str);
	char padding_char = ' ';

	if ((*params).zero_f && !(*params).minus_f)
		padding_char = '0';
	is_negative = is_negative2 = (!(*params).unsign && *str == '-');
	if (is_negative && num_digits < (*params).widths && padding_char == '0' &&
			!(*params).minus_f)
		str++;
	else
		is_negative = 0;

	if ((*params).plus_f && !is_negative2 && !(*params).unsign)
		Num += _putchar('+'), num_digits++;
	else if (params->space_f && !is_negative2 && !(*params).unsign)
		Num += _putchar(' '), num_digits++;
	Num += _puts(str);
	while (num_digits++ < (*params).widths)
		Num += _putchar(padding_char);
	return (Num);
}

/**
 * print_number_right_shift - this function prints a number with options
 * @str: the string representation of the number
 * @params: pointer to the parameters struct
 * Return: the number of characters printed to the output
 */
int print_number_right_shift(char *str, prm_t *params)
{
	unsigned int Num = 0, is_negative, is_negative2, num_digits = _strlen(str);
	char padding_char = ' ';

	if ((*params).zero_f && !(*params).minus_f)
		padding_char = '0';
	is_negative = is_negative2 = (!(*params).unsign && *str == '-');
	if (is_negative && num_digits < (*params).widths && padding_char == '0' &&
			!(*params).minus_f)
		str++;
	else
		is_negative = 0;
	if (((*params).plus_f && !is_negative2) ||
		(!(*params).plus_f && (*params).space_f && !is_negative2))
		num_digits++;
	if (is_negative && padding_char == '0')
		Num += _putchar('-');
	if ((*params).plus_f && !is_negative2 && padding_char == '0' &&
			!(*params).unsign)
		Num += _putchar('+');
	else if (!(*params).plus_f && params->space_f && !is_negative2 &&
		!(*params).unsign && (*params).zero_f)
		Num += _putchar(' ');
	while (num_digits++ < params->widths)
		Num += _putchar(padding_char);
	if (is_negative2 && padding_char == ' ')
		Num += _putchar('-');
	if (params->plus_f && !is_negative2 && padding_char == ' ' &&
			!(*params).unsign)
		Num += _putchar('+');
	else if (!(*params).plus_f && params->space_f && !is_negative2 &&
		!(*params).unsign && !(*params).zero_f)
		Num += _putchar(' ');
	Num += _puts(str);
	return (Num);
}
