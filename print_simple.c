#include "main.h"

/**
 * print_from_to -this function prints the range of characters addresses
* @start: pointer to the starting character address
 * @stop: pointer to the stopping character address
 * @except: pointer to the character address to be excluded
 * Return: number of bytes printed
 */
int print_from_to(char *start, char *stop, char *except)
{
	int S = 0;

	for (; start <= stop; start++)
	{
		if (start != except)
			S += _putchar(*start);
		}
		return (S);
}

/**
 * print_rev - this function Prints a string in reverse order
 * @ap: string argument
 * @params: A pointer to a params_t struct containing additional parameters
 * Return: The number of characters printed
 */
int print_rev(va_list ap, prm_t *params)
{
	int S = 0, length;
	char *string = va_arg(ap, char *);
	(void)params;

	if (string != NULL)
	{
		for (length = 0; *string; string++)
			length++;
		string--;
		for (; length > 0; length--, string--)
			S += _putchar(*string);
	}
	return (S);
}

/**
 * print_rot13 - Prints a string in ROT13 encoding.
 * @ap: string Argument
 * @params: A struct that is not used in this function.
 * Return: The number of bytes printed.
 */
int print_rot13(va_list ap, prm_t *params)
{
	int counter = 0;
	int x = 0, index = 0;
	char alphabet[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *input_str = va_arg(ap, char *);
	(void)params;

	while (input_str[x])
	{
		if ((input_str[x] >= 'A' && input_str[x] <= 'Z') ||
				(input_str[x] >= 'a' && input_str[x] <= 'z'))
		{
			index = input_str[x] - 65;
			counter = counter + _putchar(alphabet[index]);
		}
		else
			counter = counter + _putchar(input_str[x]);
		x++;
	}
	return (counter);
}
