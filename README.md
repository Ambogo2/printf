# Printf
This is a collaborative project to create a custom made printf function which takes inputs and arguments just like the printf available in the standard C library.

## Overview of printf
The printf function in C is used for formatted output. It’s part of the Standard Input/Output Library (stdio.h)
This function is responsible for writting output to the stdout(standard output stream), and the output produced is based on a format.
Printf function contains a formatted string, this string contains both text and format specifiers whic are place holders for the value to e printed.

## Format Specifiers
Format specifiers in printf are placeholders that tell the function how to format and print data. They start with a ‘%’ character and are followed by a character that specifies the data type to be printed.
The common format specifiers are:
* %d: Format as a signed decimal integer.
* %i: formats as a signed integer.
* %u: Format as an unsigned decimal integer.
* %f: Format as a floating-point number.
* %s: Format as a null-terminated string.
* %c: Format as a character.
* %x: Format as a hexadecimal number, lowercase.
* %X: Format as a hexadecimal number, uppercase.
