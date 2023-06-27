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
	int num = 0;
	int i = 0;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			printed_chars = write(1, &format[i], 1);
			num += printed_chars;
		}
		else
		{
			i++;
			if (format[i] == '%')
			{
				printed_chars = write(1, &format[i], 1);
				num += printed_chars;
			}
			else if (format[i] == '\0')
				return (-1);
			else
			{
				int (*f)(va_list);

				f = format_specifier(&format[i]);
				if (f != NULL)
				{
					printed_chars = f(args);
					if (printed_chars == -1)
						return (-1);
					num += printed_chars;
					i++;
				}
				else
				{
					printed_chars = write(1, &format[i - 1], 2);
					num += printed_chars;
				}
			}
		}
		i++;
	}

	va_end(args);
	return (num);
}
