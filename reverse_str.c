#include <stddef.h>
#include <stdarg.h>
#include "main.h"

/**
 * reverse_str - Prints the reversed string
 * @args: A variable of type va_list that will be used to estract the variable
 * @buffer: Pointer an array of characters that holds the characters
 * to be printed
 * @buffer_size: The current index of the buffer at the time of
 * the function call
 *
 * Return: The number of characters printed
 */
int reverse_str(va_list args, char *buffer, int buffer_size)
{
	const char *str;
	int str_length = 0;
	int printed_chars = 0;

	str = va_arg(args, char *);
	if (str == NULL)
		return (0);
	while (*(str + str_length) != '\0')
		str_length++;
	printed_chars = str_length;
	while (str_length)
		buffer[buffer_size++] = str[--str_length];
	return (printed_chars);
}
