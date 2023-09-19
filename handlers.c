#include <stddef.h>
#include <stdarg.h>
#include "main.h"

/**
 * char_print - Prints a character value
 * @args: A variable of type va_list from which an argument
 * is to be extracted
 * @buffer: Pointer to a character array that will store the
 * characters to be printed
 * @buffer_size: Current index of the buffer at the time of function call
 *
 * Return: 1 on success, otherwise 0
 */
int char_print(va_list args, char *buffer, int buffer_size)
{
	char c;

	c = va_arg(args, int);
	if (c == '\0')
	{
		return (0);
	}
	else
	{
		buffer[buffer_size++] = c;
		return (1);
	}
}

/**
 * str_print - Prints out a string(null-terminated array of characters
 * @args: A variable of type va_list from which an argument is to be extracted
 * @buffer: Pointer to a character array that will store the
 * characters to be printed
 * @buffer_size: Current index of the buffer at the time of function call
 *
 * Return: The length of the string
 * 0 if the string has a NULL reference
 */
int str_print(va_list args, char *buffer, int buffer_size)
{
	int str_length = 0;
	const char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		return (0);
	while (*(str + str_length) != '\0')
	{
		buffer[buffer_size++] = *(str + str_length);
		str_length++;
	}
	return (str_length);
}

/**
 * num_print - Prints a number
 * @args: A variable of type va_list from which an argument is to be extracted
 * @buffer: Pointer to a character array that will store the
 * characters to be printed
 * @buffer_size: Current index of the buffer at the time of function call
 *
 * Return: Number of individual digits in the number
 * 0 if nothing is printed
 */
int num_print(va_list args, char *buffer, int buffer_size)
{
	int num = 0;
	int printed_digits = 0;
	char temp_arr[20] = ""; /* Temporary buffer to hold digits */
	int i = 0;

	num = va_arg(args, int);
	if (num < 0)
	{
		buffer[buffer_size++] = ('-');
		printed_digits++;
		num = -num;
	}
	if (num >= 0 && num <= 9)
	{
		buffer[buffer_size++] = num + '0';
		printed_digits++;
	}
	else
	{
		while (num)
		{
			temp_arr[i] = (num % 10) + '0';
			num /= 10;
			i++;
		}
		while (i)
		{
			buffer[buffer_size++] = temp_arr[--i];
			printed_digits++;
		}
	}
	return (printed_digits);
}

/**
 * bin_print - Prints the binary representation of an unsigned integer argument
 * @args: A variable of type va_list from which an argument is to be extracted
 * @buffer: Pointer to a character array that will store the
 * characters to be printed
 * @buffer_size: Current index of the buffer at the time of function call
 *
 * Return: The number of binary characters printed
 */
int bin_print(va_list args, char *buffer, int buffer_size)
{
	unsigned int num = 0;
	int i = 0;
	char temp_arr[32] = ""; /**
			     * Temporary buffer to hold digits so that
			     * they can be reversed
			     */
	int printed_digits = 0;

	num = va_arg(args, int);
	if (num == 0)
	{
		buffer[buffer_size++] = (0 + '0');
		return (++printed_digits);
	}
	while (num)
	{
		temp_arr[i] = (num % 2) + '0';
		num /= 2;
		i++;
	}
	while (i)
	{
		buffer[buffer_size++] = temp_arr[--i];
		printed_digits++;
	}
	return (printed_digits);
}
