#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
* _printf -produces output according to format
* returns number of char printed excluding
*	: null byte '\0'
* write output to stdout stream
* @format: character string
* Return: 0 Always true.
*
*/

int _printf(const char *format, ...)
{
	va_list nArgs;
	unsigned int count = 0;

	va_start(nArgs, format);
	while (*format != '\0')
	{
		check_modifier(nArgs, &format, &count);
		format++;
	}
	va_end(nArgs);
	return (count);
}

/**
* check_modifier - checks modifier type
* @nArgs: the variable list
* @format: the string passed in _printf()
* @count: counter
* Return: void
*/

void check_modifier(va_list nArgs, const char **format, unsigned int *count)
{
	if (**format == '%')
	{
		(*format)++;
		switch (**format)
		{
			case ('d'):
			{
				write(STDOUT_FILENO, va_arg(nArgs, int), sizeof(int));
				(*count)++;
				break;
			}
			case ('i'):
			{
				write(STDOUT_FILENO, va_arg(nArgs, int), sizeof(int));
				(*count)++;
				break;
			}
			case ('%'):
				write(STDOUT_FILENO, "%", 1);
				(*count)++;
				break;
			default:
				write(STDOUT_FILENO, *format, sizeof(char));
				(*count)++;
				break;
		}

	}
	else
	{
		write(STDOUT_FILENO, format, 1);
		(*count)++;
	}
}
