#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * handle_integer_d - handles %d format specifier
 * @args: Arguments passed to the function
 * Return: Number of characters printed
 */
int handle_integer_d(va_list args)
{
	int num = va_arg(args, int);
	int div = 1;
	int len = 0;
	unsigned int n;

	if (num < 0)
	{
		len += _putchar('-');
		n = -num;
	}
	else
	{
		n = num;
	}

	while (n / div > 9)
	{
		div *= 10;
	}

	while (div != 0)
	{
		len += _putchar('0' + n / div);
		n %= div;
		div /= 10;
	}

	return (len);
}


/**
 * handle_integer_i - handles %i format specifier
 * @n: unsigned int to be printed
 * Return: Number of characters printed
 */
int handle_integer_i(va_list args)
{
	int num = va_arg(args, int);
	int div = 1;
	int len = 0;
	unsigned int n;

	if (num < 0)
	{
		len += _putchar('-');
		n = -num;
	}
	else
	{
		n = num;
	}

	while (n / div > 9)
	{
		div *= 10;
	}

	while (div != 0)
	{
		len += _putchar('0' + n / div);
		n %= div;
		div /= 10;
	}

	return (len);
}
