#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * count_digits - counts the number of digits in a decimal number
 * @num: the decimal number
 * Return: the number of digits
 */
int count_digits(unsigned int num)
{
	int count = 0;

	if (num == 0)
	{
		return (1);
	}

	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

/**
 * print_unsigned_decimal - prints an unsigned decimal number
 * @num: the unsigned decimal number
 * @digits: the number of digits
 */
void print_unsigned_decimal(unsigned int num, int digits)
{
	if (digits == 0)
	{
		return;
	}
	print_unsigned_decimal(num / 10, digits - 1);
	_putchar('0' + (num % 10));
}

/**
 * handle_octal - handles %o format specifier
 * @args: Arguments passed to the function
 * Return: Number of characters printed
 */
int handle_octal(va_list args)
{
	unsigned int num;
	int digits = 0;
	int i;
	int arr[100];

	num = va_arg(args, unsigned int);

	while (num != 0)
	{
		arr[digits] = num % 8;
		num /= 8;
		digits++;
	}

	for (i = digits - 1; i >= 0; i--)
	{
		_putchar('0' + arr[i]);
	}
	return (digits);
}

/**
 * handle_unsigned_decimal - handles %u format specifier (unsigned decimal)
 * @args: Arguments passed to the function
 * Return: Number of characters printed
 */
int handle_unsigned_decimal(va_list args)
{
	unsigned int num;
	int digits;

	num = va_arg(args, unsigned int);

	digits = count_digits(num);
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	print_unsigned_decimal(num, digits);
	return (digits);
}
