#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_integer - Recursive helper function to print an integer
 * @num: Integer to be printed
 * Return: Number of digits printed
 */
int print_integer(int num)
{
	int digits = 0;

	if (num != 0)
	{
		digits = print_integer(num / 10);
		_putchar('0' + (num % 10));
		digits++;
	}

	return (digits);
}

/**
 * handle_integer_d - handles %d format specifier
 * @args: Arguments passed to the function
 * Return: Number of characters printed
 */
int handle_integer_d(va_list args)
{
	int num = va_arg(args, int);
	int digits = 0;
	int is_negative = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
		_putchar('-');
	}

	digits = print_integer(num);
	return (digits + is_negative);
}

/**
 * handle_integer_i - handles %i format specifier
 * @args: Arguments passed to the function
 * Return: Number of characters printed
 */
int handle_integer_i(va_list args)
{
	return (handle_integer_d(args));
}
