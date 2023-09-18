This repository contains the group project `0x11. C - printf`<br>
In this project, we implement a function that behaves in a similar way to the `printf` function provided in the Standard library.<br>
The directory contains several C source files and one header file.

The function being implemented in this project is the `_printf` function.<br>
`int _printf(const char *format, ...);`<br>
`format` is a constant string that acts as the format template. It indicates the various items that are to be printed and how they will appear when printed. If the `%` symbol preceeds a character, it indicates that there is an argument that is expected in its place. The function will look through the ordered list of optional arguments and expand it in place of the format specifer and then print it.<br>
The function returns the number of individual characters that have been printed.<br>

`my_printf.c`<br>
This source file is where the `_printf` function is implemented.<br>

`get_specifier.c`<br>
This source file is where the `get_specifier` function is implemented.<br>
This function takes in a pointer to a character, from the `format` template, as an argument and determines the appropriate funtion pointer to return, that will handle the given format specifier.<br>
`int (*get_specifier(const char *)(va_list args)`<br>
It relies on a structure that represents a key-value pair that maps a format specifier to its appropriate function. Depending on the character provided, usually following a `%` symbol in the `format` template, it returns a pointer to the function that handles the argument that is to be expanded and printed in its place.<br>
```
struct funcs
{
	const char *type;
	int (*func)(va_list);
};
```
<br>
Here, the key is the pointer to a character that indicates the type of format specifier, while the value is pointer to a functinon that takes an argument of type `va_list`.

`handlers.c`<br>
In this source file, the various functions that handle various format specifiers are defined.

`main.h`<br>
This header file contains all function prototypes of the functions used across all C source files in this directory.<br>
It also has structures that have been defined for purposes of function implementation.
