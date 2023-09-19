#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include "main.h"

/**
 * address_print - Prints the address of a variable
 * @args: A variable of type va_list from which the argument is to be extracted
 * @buffer: Pointer to a character array that will hold the characters
 * to be printed
 * @buffer_size: The current index of the buffer at the time of
 * the function call
 *
 * Return: The number of characters printed
 */
int address_print(va_list args, char *buffer, int buffer_size)
{
	void *ptr = NULL;
	uintptr_t address = 0;
	int printed_chars = 0;

	ptr = va_arg(args, void *);
	if (ptr == NULL || buffer == NULL)
		return (0);
	address = (uintptr_t)ptr;
	buffer[buffer_size++] = 0 + '0';
	buffer[buffer_size++] = 'x';
	printed_chars += 2;
	printed_chars += address_helper(address, buffer, buffer_size);
	return (printed_chars);
}

/**
 * address_helper - Function that handles the delegated funcionality
 * of converting a number to its hexadecimal equivalent
 * @num: Number to be converted
 * @buffer: Pointer to a character array that will hold the characters
 * to be printed
 * @buffer_size: The current index of the buffer at the time of
 * the function call
 *
 * Return: The number of printed characters
 */
int address_helper(uintptr_t num, char *buffer, int buffer_size)
{
	char temp_arr[16];
	int i = 0;
	int n = 0;

	if (buffer == NULL)
		return (0);
	if (num == 0)
	{
		buffer[buffer_size++] = 0 + '0';
		return (1);
	}
	while (num)
	{
		n = num % 16;
		if (n < 9)
		{
			temp_arr[i] = n + '0';
		}
		else
		{
			if (n == 10)
				*(temp_arr + i) = 'a';
			else if (n == 11)
				*(temp_arr + i) = 'b';
			else if (n == 12)
				*(temp_arr + i) = 'c';
			else if (n == 13)
				*(temp_arr + i) = 'd';
			else if (n == 14)
				*(temp_arr + i) = 'e';
			else if (n == 15)
				*(temp_arr + i) = 'f';
		}
		i++;
		num /= 16;
	}
	n = i;
	while (i)
		buffer[buffer_size++] = temp_arr[--i];
	return (n);
}
