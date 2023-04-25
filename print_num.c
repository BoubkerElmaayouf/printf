#include "main.h"

/**
 * convert - this function Converts a given decimal number to another base
 * @num: The decimal number to be converted.
 * @base: The desired base for the conversion.
 * @flags: Flags that may affect the conversion.
 * @params: A struct containing additional parameters
 * that can be used during conversion.
 * Return: A pointer to a character array containing
 * the result of the conversion.
 */
char *convert(long int num, int base, int flags, prm_t *params)
{
	static char *arr;
	static char buff[50];
	char *p;
	char sign_char = 0;
	unsigned long nbr = num;
	(void)params;

	if (!(flags & UNSIGNED_CONVERT) && num < 0)
	{
		nbr = -num;
		sign_char = '-';
	}
	arr = flags & LOWERCASE_CONVERSION ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buff[49];
	*p = '\0';

	do	{
		*--p = arr[nbr % base];
		nbr /= base;
	} while (nbr != 0);

	if (sign_char)
		*--p = sign_char;
	return (p);
}

/**
 * print_unsigned - this function prints unsigned integer numbers
 * @ap: pointer to the argument list
 * @params: pointer to the parameters struct
 * Return: the number of character printed
 */
int print_unsigned(va_list ap, prm_t *params)
{
	unsigned long longer;

	if ((*params).modifier_l)
		longer = (unsigned long)va_arg(ap, unsigned long);
	else if ((*params).modifier_h)
		longer = (unsigned short int)va_arg(ap, unsigned int);
	else
		longer = (unsigned int)va_arg(ap, unsigned int);
	(*params).unsign = 1;
	return (print_number(convert(longer, 10, UNSIGNED_CONVERT, params), params));
}



/**
 * print_address - this function prints the memory address
 * @ap: pointer to the argument list
 * @params: pointer to the parameters struct
 * Return: the number of character printed
 */
int print_address(va_list ap, prm_t *params)
{
	unsigned long int adress = va_arg(ap, unsigned long int);
	char *address_str;

	if (!adress)
		return (_puts("(nil)"));

	address_str = convert(adress, 16, UNSIGNED_CONVERT |
			LOWERCASE_CONVERSION, params);
	*--address_str = 'x';
	*--address_str = '0';
	return (print_number(address_str, params));
}
