#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int _print_str(const char *);

/**
 * struct funcs - A structure representing a key-value pair of a
 * character and a pointer to a function
 * @spec: A character representing the format specifier
 * @func: Pointer to the function that handles the format
 * specifier
 *
 * Description: This key-value pair represents a hash set that
 * holds a character value and its appropriate function that
 * handles the given format
 */
typedef struct funcs
{
	char *spec;
	int (*func)(va_list);
} funcs;

int (*get_specifier(const char *))(va_list args);
int char_print(va_list args);
int str_print(va_list args);
int num_print(va_list args);

#endif /* #ifndef MAIN_H */
