#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_char - prints a single character to stdout
 * @args: variable arguments list
 * @count: pointer to character count
 */
void print_char(va_list args, int *count)
{
	int c = va_arg(args, int);

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
