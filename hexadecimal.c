#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * handle_hexadecimal - handles %x format specifier (lowercase hexadecimal)
 * @args: Arguments passed to the function
 * Return: Number of characters printed
 */
int handle_hexadecimal(va_list args)
{
	unsigned int num;
	char hex_digits[] = "0123456789abcdef";
	int digits = 0;
	int i;
	char hex[100];

	num = va_arg(args, unsigned int);

	while (num != 0)
	{
		hex[digits] = hex_digits[num % 16];
		num /= 16;
		digits++;
	}
	for (i = digits - 1; i >= 0; i--)
	{
		_putchar(hex[i]);
	}

	return (digits);
}

/**
 * handle_hexadecimal_upper - handles %X format specifier
 * @args: Arguments passed to the function
 * Return: Number of characters printed
 */

int handle_hexadecimal_upper(va_list args)
{
	unsigned int num;
	char hex_digits[] = "0123456789ABCDEF";
	int digits = 0;
	int i;
	char hex[100];

	num = va_arg(args, unsigned int);

	while (num != 0)
	{
		hex[digits] = hex_digits[num % 16];
		num /= 16;
		digits++;
	}
	for (i = digits - 1; i >= 0; i--)
	{
		_putchar(hex[i]);
	}

	return (digits);
}
