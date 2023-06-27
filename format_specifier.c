#include "main.h"

/**
*format_specifier - checks format specifier and assigns appropriate function
*@format:format specifier
*Return: pointer to a function
*/

int (*format_specifier(const char *format))(va_list)
{
	int i;
	spec_t specifiers[] = {
		{"c", handle_char},
		{"s", handle_string},
		{"%", handle_percent},
		{"d", handle_integer_d},
		{"i", handle_integer_i},
		{"o", handle_octal},
		{"b", handle_binary},
		{"x", handle_hexadecimal},
		{"X", handle_hexadecimal_upper},
		{"r", handle_reversed_string },
		{NULL, NULL}
		};

	for (i = 0; specifiers[i].s != NULL; i++)
	{
		if (*specifiers[i].s == *format)
		{
			return (specifiers[i].f);
		}
	}
	return (NULL);
}
