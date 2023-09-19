#include <unistd.h>
#include "main.h"

/**
 * _putchar - Prints a single character on the console screen
 * @c: The individual character to be printed
 *
 * Return: 1 on success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
