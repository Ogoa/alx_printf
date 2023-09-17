#include <stddef.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: Pointer to the memory location holding the string
 * that acts as a format specifier of what is to be printed
 *
 * Return: The number of characters printed (excluding the null
 * byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int printed_chars = 0;
	char c; /* Will temporarily hold a character retrieved from the list */
	char *str; /* Will temporarily hold a string retrieved from the list */

	if (format == NULL)
		return (0);
	va_start(args, format);
	while (*(format + i) != '\0')
	{
		if (*(format + i) != '%')
		{
			printed_chars += _putchar(*(format + i));
		}
		else if (*(format + i) == '%')
		{
			i++;
			switch (*(format + i))
			{
			case 'c':
				c = va_arg(args, int);
				printed_chars += _putchar(c);
				break;
			case 's':
				str = va_arg(args, char *);
				printed_chars += _print_str(str);
				break;
			case '%':
				_putchar('%');
				printed_chars++;
				break;
			default:
				break;
			}
		}
		i++;
	}
	va_end(args);
	return (printed_chars);
}

/**
 * _print_str - Prints a string value
 * @str: Pointer to the memory location holding the null-terminated
 * array of characters
 *
 * Return: The length of the string (printed characters)
 * 0 if the 'str' has a NULL reference
 */
int _print_str(const char *str)
{
	int str_length = 0;

	if (str == NULL)
		return (0);
	while (*(str + str_length) != '\0')
	{
		_putchar(*(str + str_length));
		str_length++;
	}
	return (str_length);
}
