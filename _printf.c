#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
*_printf - a function that prints a formatted string
*@format:character
*@...:variadic arguments 
*Return:number of characters printed
*/

int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	int num = 0;
	int i = 0;
	int (*f)(va_list);
	
	va_start(args, format);
	
	if (format == NULL)
	{
		return (-1);
	}

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			printed_chars = write (1, &format[i], 1);
			num = num + printed_chars;
			i++;
			continue;
		}
		if (format[i] == '%')
		{
			f = format_specifier(&format[i + 1]);
			if (f!= NULL)
			{
				printed_chars = f(args);
				num = num + printed_chars;
				i += 2;
			
				continue;
			}
			if (format [i + 1] == '\0')
			{
				printed_chars = write (1, &format[i], 1);
				num = num + printed_chars;
				i++;
				continue;
			}
	
			va_end(args);
			return (printed_chars);
		}

	}
	return (num);
}
