#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct spec - struct of member operators
 * @s: format specifier string
 * @f: function pointer to the corresponding handler function
 */
struct spec
{
	char *s;
	int (*f)(va_list);
};

/**
 * spec_t - typedef for spec
 */
typedef struct spec spec_t;

int _printf(const char *format, ...);
int (*format_specifier(const char *format))(va_list);
int _putchar(char c);
int handle_char(va_list args);
int handle_string(va_list args);
int handle_percent(va_list args);
int handle_integer_d(va_list args);
int handle_integer_i(va_list args);
int print_integer(int num);
int handle_octal(va_list args);
int handle_hexadecimal(va_list args);
int handle_hexadecimal_upper(va_list args);
int handle_reversed_string(va_list args);
int handle_binary(va_list args);
void print_unsigned_decimal(unsigned int num, int digits);
int count_digits(unsigned int num);


#endif /* MAIN_H */
