#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - a function that prints a string
 * @format: the format of the string to print
 * Return: prints a pointer
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format)
	{
	if (*format == '%' && *(format + 1) == 'p')
	{
		void *ptr = va_arg(args, void *);

		printf(ptr);
		format += 2;

	}
	else
	{
		putchar(*format);
		format++;

	}
	}
	va_end(args);
}
