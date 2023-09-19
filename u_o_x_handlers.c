#include <stdarg.h>
#include <stddef.h>
#include "main.h"

/**
 * oct_print - Converts a decimal number to its octal equivalent
 * and prints it out
 * @args: A variable of type va_list from which an argument is to be extracted
 * @buffer: Pointer to an array that will hold the characters to be printed
 * @buffer_size: The current index of the buffer at the time of function call
 *
 * Return: The number of characters printed
 */
int oct_print(va_list args, char *buffer, int buffer_size)
{
	int printed_chars = 0;
	int num = 0;
	int i = 0;
	char temp_arr[8] = ""; /**
			    * Temporary buffer to hold the octal
			    * representation of the decimal number
			    */

	if (buffer == NULL)
		return (0);
	num = va_arg(args, int);
	while (num)
	{
		temp_arr[i] = (num % 8) + '0';
		num /= 8;
		i++;
	}
	while (i)
	{
		buffer[buffer_size++] = temp_arr[--i];
		printed_chars++;
	}
	return (printed_chars);
}

/**
 * hex_print - Converts a decimal number to its hexadecimal equivalent
 * @args: A variable of type va_list from which an argument is to be extracted
 * @buffer: Pointer to an array that will hold the characters to be printed
 * @buffer_size: The current index of the buffer at the time of function call
 *
 * Return: The number of characters printed
 */
int hex_print(va_list args, char *buffer, int buffer_size)
{
	int printed_chars = 0;
	int num = 0;

	if (buffer == NULL)
		return (0);
	num = va_arg(args, int);
	if (num == 0)
	{
		buffer[buffer_size++] = 0 + '0';
		return (1);
	}
	printed_chars += hex_print_helper(num, buffer, buffer_size);
	return (printed_chars);
}

/**
 * hex_print_helper - Function that handles work delegated from hex_print()
 * @num: Number to be converted into its hexadecimal equivalent
 * @buffer: Pointer to an array character that will hold the characters
 * to be printed
 * @buffer_size: The current index of the buffer at the time of the
 * function call
 *
 * Return: The number of characters that will be printed
 */
int hex_print_helper(int num, char *buffer, int buffer_size)
{
	char temp_arr[16]; /* Temporary buffer */
	int i = 0;
	int printed_chars = 0;

	if (buffer == NULL)
		return (0);
	while (num)
	{
		int n;

		n = num % 16;
		if (n > 9)
		{
			if (n == 10)
				temp_arr[i] = 'a';
			else if (n == 11)
				temp_arr[i] = 'b';
			else if (n == 12)
				temp_arr[i] = 'c';
			else if (n == 13)
				temp_arr[i] = 'd';
			else if (n == 14)
				temp_arr[i] = 'e';
			else if (n == 15)
				temp_arr[i] = 'f';
		}
		else
		{
			temp_arr[i] = n + '0';
		}
		num /= 16;
		i++;
	}
	while (i)
	{
		buffer[buffer_size++] = temp_arr[--i];
		printed_chars++;
	}
	return (printed_chars);
}

/**
 * unsigned_print - Prints an unsigned integer
 * @args: A variable of type va_list from which an argument is to be extracted
 * @buffer: Pointer to an array that will hold the characters to be printed
 * @buffer_size: The current index of the buffer at the time of function call
 *
 * Return: The number of printed numbers
 */
int unsigned_print(va_list args, char *buffer, int buffer_size)
{
	unsigned int num = 0;
	int printed_chars = 0;
	int i = 0;
	char temp_arr[32];

	if (buffer == NULL)
		return (0);
	num = va_arg(args, int);
	while (num)
	{
		temp_arr[i] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	while (i)
	{
		buffer[buffer_size++] = temp_arr[--i];
		printed_chars++;
	}
	return (printed_chars);
}
