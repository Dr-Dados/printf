#include <stdarg.h>
#include <stdlib.h>
#include "main.h"
#include <stdio.h>

int _printf(const char *format, ...)
{
 int count = 0;
 char *s;
	va_list args;
	va_start(args, format);
	
	for (; *format; format++)
	{
		if (*format != '%')
		{
			putchar(*format), count++;
			continue;
		}

		switch (*++format)
		{
			case 'c':
				putchar(va_arg(args, int)), count++;
				break;
			case 's':
				s = va_arg(args, char *); 
				for (; *s; s++)
					putchar(*s), count++;
				break;
			case '%':
				putchar('%'), count++;
				break;
			default:
				putchar('%'), putchar(*format), count += 2;
		}
	}
	
	va_end(args);
	return count;
}

