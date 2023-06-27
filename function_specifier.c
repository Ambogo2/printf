#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

/**
*handle_char - handles %c format specifier
*@args:Arguments passed to the function
*Return:Number of characters printed
*/

int handle_char(va_list args)
{
	char c;
	int num = 0;

	c = (char)va_arg(args, int);

	num = putchar(c);
	return (num);
}


/**
*handle_string - handles %s format specifier
*@args:Arguments passed to the function
*Return:Number of characters printed
*/

int handle_string(va_list args)
{

	int i;
	const char *str;

	str = va_arg(args, const char *);
	if (str == NULL)
	{
		str = "(null)";
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		putchar(str[i]);
	}
	return (i);
}

