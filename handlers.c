#include <stddef.h>
#include <stdarg.h>
#include "main.h"

/**
 * char_print - Prints a character value
 * @args: A variable of type va_list from which an argument
 * is to be extracted
 *
 * Return: 1 on success, otherwise 0
 */
int char_print(va_list args)
{
	char c;

	c = va_arg(args, int);
	if (c == '\0')
		return (0);
	else
		return (_putchar(c));
}

/**
 * str_print - Prints out a string(null-terminated array of characters
 * @args: A variable of type va_list from which an argument is to be extracted
 *
 * Return: The length of the string
 * 0 if the string has a NULL reference
 */
int str_print(va_list args)
{
	int str_length;
	const char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		return (0);
	while (*(str + str_length) != '\0')
		str_length += _putchar(*(str + str_length));
	return (str_length);
}

/**
 * num_print - Prints a number
 * @args: A variable of type va_list from which an argument is to be extracted
 *
 * Return: Number of individual digits in the number
 * 0 if nothing is printed
 */
int num_print(va_list args)
{
	int num;
	int printed_digits = 0;
	char temp_arr[20]; /* Temporary buffer to hold digits */
	int i = 0;

	num = va_arg(args, int);
	if (num < 0)
	{
		printed_digits += _putchar('-');
		num = -num;
	}
	if (num >= 0 && num <= 9)
	{
		printed_digits += _putchar(num + '0');
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
			printed_digits += _putchar(temp_arr[--i]);
	}
	return (printed_digits);
}
