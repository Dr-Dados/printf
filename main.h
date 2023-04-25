#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...);

//fonction

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


#endif
