#include "main.h"

/**
 * print_char - prints a single character to stdout
 * @args: variable arguments list
 * @count: pointer to character count
 */
void print_char(va_list args, int *count)
{
int c;

c = va_arg(args, int);

putchar(c);
(*count)++;
}

/**
 * print_string - prints a string to stdout
 * @args: variable arguments list
 * @count: pointer to character count
 */
void print_string(va_list args, int *count)
{
char *s = va_arg(args, char *);

for (; *s; s++)
{
putchar(*s);
(*count)++;
}
}

/**
 * print_percent - prints a percent character to stdout
 * @count: pointer to character count
 */
void print_percent(int *count)
{
putchar('%');
(*count)++;
}
/**
 * print_decimal - prints a decimal number to stdout
 * @args: variable arguments list
 * @count: pointer to character count
 */
void print_decimal(va_list args, int *count)
{
int temp, i, digit;
int n = va_arg(args, int);
int digits = 0;

if (n == 0)
{
putchar('0');
(*count)++;
return;
}

if (n < 0)
{
putchar('-');
(*count)++;
n = -n;
}

temp = n;
while (temp != 0)
{
digits++;
temp /= 10;
}

while (digits > 0)
{
int divisor = 1;
for (i = 1; i < digits; i++)
{
divisor *= 10;
}
digit = n / divisor;
n %= divisor;
digits--;
putchar(digit + '0');
(*count)++;
}
}

/**
 * print_integer - prints an integer to stdout
 * @args: variable arguments list
 * @count: pointer to character count
 */
void print_integer(va_list args, int *count)
{
print_decimal(args, count);
}

/**
 * _printf - prints formatted output to stdout
 * @format: format string
 *
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
int count = 0;
va_list args;

va_start(args, format);

for (; *format; format++)
{
if (*format != '%')
{
putchar(*format);
count++;
continue;
}

format++;

switch (*format)
{
case 'c':
print_char(args, &count);
break;
case 's':
print_string(args, &count);
break;
case '%':
print_percent(&count);
break;
case 'd':
case 'i':
print_integer(args, &count);
break;
default:
putchar('%');
putchar(*format);
count += 2;
break;
}
}

va_end(args);
return (count);
}
