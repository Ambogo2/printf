#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * handle_binary - handles %b format specifier
 * @args: Arguments passed to the function
 * Return: Number of characters printed
 */
int handle_binary(va_list args)
{
unsigned int num;
int digits = 0;
int i;
int arr[100];

num = va_arg(args, unsigned int);

while (num != 0)
{
arr[digits] = num % 2;
num /= 2;
digits++;
}

for (i = digits - 1; i >= 0; i--)
{
_putchar('0' + arr[i]);
}
return (digits);
}
