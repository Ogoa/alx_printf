#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdint.h>

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
	int (*func)(va_list, char *, int);
} funcs;

int (*get_specifier(const char *))(va_list args, char *buffer, int size);
int char_print(va_list args, char *buffer, int buffer_size);
int str_print(va_list args, char *buffer, int buffer_size);
int num_print(va_list args, char *buffer, int buffer_size);
int bin_print(va_list args, char *buffer, int buffer_size);
int unsigned_print(va_list args, char *buffer, int buffer_size);
int oct_print(va_list args, char *buffer, int buffer_size);
int hex_print(va_list args, char *buffer, int buffer_size);
int s_print(va_list args, char *buffer, int buffer_size);
int reverse_str(va_list args, char *buffer, int buffer_size);
int address_print(va_list args, char *buffer, int buffer_size);
int address_helper(uintptr_t num, char *buffer, int buffer_size);
int hex_print_helper(int num, char *buffer, int buffer_size);

#endif /* #ifndef MAIN_H */
