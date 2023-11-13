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

	if (format == NULL)
		return (-1);

	va_start(nArgs, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;

			check_modifier(nArgs, &format, &count);

		}
		else
		{
			write(STDOUT_FILENO, format, 1);
			(*count)++;
		}
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
		switch (**format)
		{
			case ('c'):
			{
				char chr = va_arg(nArgs, int);

				write(STDOUT_FILENO, &chr, 1);
				(*count)++;
				break;
			}
			case ('s'):
			{
				char *str = va_arg(nArgs, char *);

				if (*str != '\0')
				{
					write(STDOUT_FILENO, str, strlen(str));
					(*count) += strlen(str);
				}
				break;
			}
			case ('%'):
				write(STDOUT_FILENO, "%", 1);
				(*count)++;
				break;
			default:
				write(STDOUT_FILENO, "%%", 2);
				(*count) += 2;
				break;
		}
}
