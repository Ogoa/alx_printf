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
	int (*func)(va_list args);

	if (format == NULL)
		return (-1);
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
			if (*(format + i) == 'c' || *(format + i) == 's' ||
					*(format + i) == 'd' || *(format + i) == 'i')
			{
				func = get_specifier((format + i));
				printed_chars += func(args);
			}
			else
			{
				printed_chars += _putchar('%');
				printed_chars += _putchar(*(format + i));
			}
		}
		i++;
	}
	va_end(args);
	return (printed_chars);
}
