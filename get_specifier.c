#include <stddef.h>
#include <stdarg.h>
#include "main.h"

/**
 * get_specifier - Selects what function pointer to return based
 * on the format specifier
 * @c: Pointer to the character acting as the format specifier
 *
 * Return: Pointer to the appropriate function based on the
 * matching format specifier
 * NULL if no match is found
 */
int (*get_specifier(const char *c))(va_list args, char *buffer, int size)
{
	funcs types[] = {
		{"c", char_print},
		{"s", str_print},
		{"d", num_print},
		{"i", num_print},
		{"b", bin_print},
		{"u", unsigned_print},
		{"o", oct_print},
		{"x", hex_print},
		{"X", hex_print},
		{"S", s_print},
		{"R", print_rot13string},
		{"r", reverse_str},
		{"p", address_print},
		{NULL, NULL}
	};
	int i = 0;

	while (types[i].spec)
	{
		if (*c == *(types[i].spec))
			return (types[i].func);
		i++;
	}
	return (NULL);
}
