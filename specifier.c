#include "main.h"

/**
 * get_specifier - this function finds the format function
 * @s: A string containing the format specifier to be matched.
 * Return: corresponding print function else, returns NULL.
 */
int (*get_specifier(char *s))(va_list ap, prm_t *params)

{
	speci_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hexadecimal},
		{"X", print_HEXADECIMAL},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifiers)
	{
		if (*s == specifiers[i].specifiers[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_func - finds the format function
 * @s: string of the format
 * @ap: argument pointer
 * @params: the parameters struct
 * Return: the number of bytes printed
 */

int get_print_func(char *s, va_list ap, prm_t *params)
{
	int (*f)(va_list, prm_t *) = get_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}

/**
 * get_flag - This function identifies the flag in the format string.
 * @s: The format string
 * @params: The parameters struct
 * Return: The integer value of the identified flag.
 */

int get_flag(char *s, prm_t *params)

{
	int flag_value = 0;

	switch (*s)
	{
		case '+':
			flag_value = (*params).plus_f = 1;
			break;
		case ' ':
			flag_value = (*params).space_f = 1;
			break;
		case '#':
			flag_value = (*params).hashtag_f = 1;
			break;
		case '-':
			flag_value = (*params).minus_f = 1;
			break;
		case '0':
			flag_value = (*params).zero_f = 1;
			break;
	}
	return (flag_value);
}

/**
 * get_modifier - this function Identifies and sets the value of a modifier
 *  in the format string
 * @s: The format string
 * @params: The parameters struct
 * Return: The integer value of the identified modifier.
 */
int get_modifier(char *s, prm_t *params)
{
	int modifier_set = 0;

	switch (*s)
	{
		case 'h':
			modifier_set = (*params).modifier_h = 1;
			break;
		case 'l':
			modifier_set = (*params).modifier_l = 1;
			break;
	}
	return (modifier_set);
}

/**
 * *get_width - this function Extracts and sets
 * the width from the format string.
 * @s: the format string
 * @params: A struct containing formatting parameters for the string.
 * @ap: A pointer to a variable argument list containing arguments to format.
 * Return: A new pointer
 */
char *get_width(char *s, prm_t *params, va_list ap)
{
	int width_value = 0;

	if (*s == '*')
	{
		width_value = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			width_value = width_value * 10 + (*s++ - '0');
	}
	(*params).widths = width_value;
	return (s);
}

