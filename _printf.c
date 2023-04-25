#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

va_start(args, format);

while (*format)
{
if (*format == '%')
{
format++;

switch (*format)
{
case 'c':
count += putchar(va_arg(args, int));
break;
case 's':
count += printf("%s", va_arg(args, char *));
break;
case '%':
count += putchar('%');
break;
case 'd':
case 'i':
count += printf("%d", va_arg(args, int));
break;
default:
putchar('%');
putchar(*format);
count += 2;
break;
}
}
else
{
putchar(*format);
count++;
}
format++;
}

va_end(args);
return (count);
}

