#include <stdio.h>
#include <stdarg.h>
/**
 * printf - main function
 * @format: pointer parameter used
 * Return: count
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;
	while (*format != '\0') {
	if (*format == '%') {
	format++;
	switch (*format) {
	case 'c': {
	char c = va_arg(args, int);
	putchar(c);
	count++;
	break;
	}
	case 's': {
	char *s = va_arg(args, char *);
	fputs(s, stdout);
	count += strlen(s);
	break;
	}
	case '%': {
	putchar('%');
	count++;
	break;
		  }
            }
        }
        else {
            putchar(*format);
            count++;
        }
        format++;
    }
    
    va_end(args);
	return (count);
}
