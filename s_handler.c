#include <stddef.h>
#include <stdarg.h>
#include "main.h"

/**
 * s_print - Handles the printing of a string under the 'S' format specifier
 * @args: A variable of type va_list from which an argument if extracted
 * @buffer: Pointer to a character array that stores the characters to be
 * printed
 * @buffer_size: The index of the buffer at the time of function call
 *
 * Return: The number of characters printed
 */
int s_print(va_list args, char *buffer, int buffer_size)
{
	int str_length = 0;
	const char *str;

	str = va_arg(args, char *);
	if (str == NULL || buffer == NULL)
		return (0);
	while (*(str + str_length) != '\0')
	{
		if (*(str + str_length) < 32 || *(str + str_length) >= 127)
		{
			buffer[buffer_size++] = '\\';
			buffer[buffer_size++] = 'x';
			buffer[buffer_size++] = "0123456789ABCDEF"
				[(*(str + str_length) >> 4) & 0xF];
			buffer[buffer_size++] = "0123456789ABCDEF"[*(str + str_length) & 0xF];
		}
		else
		{
			buffer[buffer_size++] = *(str + str_length);
		}
		str_length++;
	}
	return (str_length);
}
