#include "main.h"

/**
 * _putchar - This function writes a character to the standard output
 * @z: The character to print
 * Return: On success, this function returns 1.
 * On failure, it returns -1 and sets the error appropriately
 */
int _putchar(int z)
{
	static int i;
	static char buf[BUF_OUTPUT_SIZE];

	if (z == BUFFER_FLUSH || i >= BUF_OUTPUT_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (z != BUFFER_FLUSH)
		buf[i++] = z;
	return (1);
}

/**
 * _puts - a function that prints a string with newline
 * @s: pointer to a characte 
 * Return: the length of the string s - a 
 */
int _puts(char *s)
{
	char *a = s;

	while (*s)
		_putchar(*s++);
	return (s - a);
}
