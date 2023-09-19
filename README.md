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
Here, the key is the pointer to a character that indicates the type of format specifier, while the value is pointer to a functinon that takes an argument of type `va_list`.<br>

`handlers.c`<br>
In this source file, the various functions that handle various format specifiers are defined.

`main.h`<br>
This header file contains all function prototypes of the functions used across all C source files in this directory.<br>
It also has structures that have been defined for purposes of function implementation.


`u_o_x_handlers.c`<br>
This source file contains the function `oct_print`, `hex_print` and `unsigned_int` that handle the `%o`, `%x` and `%u` format specifiers respectively.<br>
Each function has the function signature:<br>
`int func_name(va_list, char *, int);`<br>
where the first formal paramater is a variable of type `va_list` from which the optional argument to be printed is etracted. The second parameter is a pointer to a character array that represents a buffer of size 1024 bytes, where the characters to be written onto the standard output are held. The third parameter is the buffer index at the time of the function call the `_printf` function.<br>
The three functions also return the number of characters that have been added to the buffer (characters that will be printed from the optional argument they have handled).<br>

`s_handler.c`<br>
This source file contains the function `s_print` that is a custom conversion specifier `%S` that prints a string. However, non printable characters (0 < ASCII value < 32 or >= 127) are printed in this way: `\x`, followed by the ASCII code value in hexadecimal (upper case - always 2 characters). <br>
```
_printf("%S\n", "Best\nSchool");

================================

Output: Best\x0ASchool
```
<br>
The code above shows a use case.<br>

`reverse_str.c`
This source file contains the function `reverse_str` that is a custom conversion specifier `%r` that prints a reverse string.
