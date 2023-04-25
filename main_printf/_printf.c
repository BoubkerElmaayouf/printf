#include "main.h"

/**
 * _printf - this function Prints data to the standard
 * output according to a format string
 * @format: pointer to a char string that contains zero or more format.
 * Return: the number of characters
 */

int _printf(const char *format, ...)

{
	int S = 0;
	va_list ArgPtr;
	char *_start, *fmt_ptr;

	prm_t params = INIT_PARAMS;

	va_start(ArgPtr, format);

	/* Checking if the format string is NULL or empty */
	if (format == NULL || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (fmt_ptr = (char *)format; *fmt_ptr; fmt_ptr++)
	{
		init_params(&params, ArgPtr);
		if (*fmt_ptr != '%')
		{
			S += _putchar(*fmt_ptr);
			continue;
		}
		_start = fmt_ptr;
		fmt_ptr++;
		while (get_flag(fmt_ptr, &params))
		{
			fmt_ptr++;
		}
		fmt_ptr = get_width(fmt_ptr, &params, ArgPtr);
		fmt_ptr = get_precision(fmt_ptr, &params, ArgPtr);
		if (get_modifier(fmt_ptr, &params))
			fmt_ptr++;
		if (get_specifier(fmt_ptr) == NULL)
			S += print_from_to(_start, fmt_ptr,
					params.modifier_l || params.modifier_h ? fmt_ptr - 1 : 0);
		else
			S += get_print_func(fmt_ptr, ArgPtr, &params);
	}
	_putchar(BUFFER_FLUSH);
	va_end(ArgPtr);
	return (S);
}

