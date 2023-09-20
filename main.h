#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

/*FLAGS*/
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/*SIZE*/
#define S_LONG 2
#define S_SHORT 1
=======

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

/**
 * struct format - Structure operators
 * @format: the format
 * @fn: the associated function
 */
struct format
{
	char format;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct format format_t -Structure operator
 * @format: the format
 * @format_t: the function associated
 */
typedef struct format format_t;

int _printf(const char *format, ...);
int handle_print(const char *format, int *i, va_list list, char buffer[],
int flags, int width, int precision, int size);
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
int print_rot13string(va_list args, char *buffer, int buffer_size);


#endif /* #ifndef MAIN_H */
