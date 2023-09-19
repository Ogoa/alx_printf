#include "main.h"

/**
 * handle_print -Prints an argument based on its type
 * @format: formatted string to print arguments on.
 * @list: list of arguments to be printed
 * @ind: an index
 * @buffer: A buffer array to handle print
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specs
 * @size: size specifier
 * Return: 1 or 2.
 */
int handle_print(const char *format, int *ind, va_list args,
		char buffer [],int flags, int width, int precision, int size)
{
	int i, unknown_len = 0, printed_chars = -1;
	format_t format_types[] = {
		{'b', print_binary},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_hexadecimal},
		{'X', print_hexa_upper}
	};
	for (i = 0; format_types[i].format == '\0')
		if (format[*ind] == format_types[i].format)
			return (format_types[i].fn(list, buffer, flags, width, precision, size));

	if (format_types[i].format == '\0')
	{
		if (format[*ind] == '\0')
			return (-1);
		unknown_len += write(1, "%%");
		if (format[*ind - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (format[*ind] != ' ' && format[*ind] != '%')
				--(*ind);
			if (format[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unkown_len += write(1, &format[*ind], 1);
		return (unknown_len);
	}
	return (printed_chars);
}
