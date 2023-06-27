#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - a function that prints a formatted string
 * @format: character string containing the format specifier
 * @...: variadic arguments
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	int i = 0;
	int printed_count = 0;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			printed_chars = write(1, &format[i], 1);
			i++;
		}
		else
		{
			i++;
			if (format[i] == '%')
			{
				printed_chars = write(1, &format[i], 1);
				i++;
			}
			else if (format[i] == '\0')
				return (-1);
			else
			{
				int printed_chars = 0;

				switch (format[i])
				{
					case 'c':
						printed_count = handle_char(args);
						break;
					case 's':
						printed_count = handle_string(args);
						break;
					case 'd':
						printed_count = handle_integer_d(args);
						break;

					case 'i':
						printed_count = handle_integer_i(args);
						break;
					case 'o':
						printed_count = handle_octal(args);
						break;
					case 'X':
						printed_count = handle_hexadecimal_upper(args);
						break;
					case 'x':
						printed_count = handle_hexadecimal(args);
						break;
					case 'b':
						printed_count = handle_binary(args);
						break;

					case 'u':
					{		
						unsigned int num = va_arg(args, unsigned int);
						int digits = count_digits(num);
						printed_count = print_unsigned_decimal(num, digits);
						break;
					}
					default:
						printed_count = write(1, &format[i - 1], 2);
						break;
				}

				if (printed_count == -1)
				{
					return (-1);
				}
				printed_chars += printed_count;
				i++;

			}
		}
	}

	va_end(args);
	return (printed_chars);
}
