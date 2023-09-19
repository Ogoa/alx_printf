#include "main.h"

/**
 * is_printable -Evaluates if a char is printable
 * @c: character to be evaluated
 * Return: 1 if c is printable, otherwise 0
 */
int is_printable(char c)
{
	if (c >= 32 && c <= 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code -Append ascci in hexadecimal code to buffer
 * @buffer: array of characters.
 * @i: Index to start appending
 * @ascci_code: ASCII CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF"

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit -Verifies if char is a digit
 * @c: Char to be evaluated
 * Return: 1 if c is a digit otherwise 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}