#include <stdarg.h>
#include <stddef.h>
#include "main.h"

/**
 * print_rot13string -prints a string  of characters rotated 13 times
 * @args: list of arguments
 * @buffer: buffer array to handle print
 * @buffer_size: index of the buffer at the time of function call
 * Return: number of characters printed
 */
int print_rot13string(va_list args, char *buffer, int buffer_size)
{
	char x;
	char *str;
	unsigned int i = 0;
	unsigned int j = 0;
	int count = 0;
	char in[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);

	if (str == NULL)
		return (0);
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				buffer[buffer_size++] = x;
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			buffer[buffer_size++] = x;
			count++;
		}
	}
	return (count);
}
