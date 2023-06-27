#include <string.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_reversed_string - handles %r format specifier
 * @args: Arguments passed to the function
 * Return: Number of characters printed
 */
int handle_reversed_string(va_list args)
{
	int i, len;
	const char *str;

	str = va_arg(args, const char *);
	if (str == NULL)
	{
		str = "(null)";
	}

	len = strlen(str);

	for (i = len - 1; i >= 0; i--)
	{
		putchar(str[i]);
	}

	return (len);
}
