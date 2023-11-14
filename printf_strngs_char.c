#include "main.h"

/**
* _print - produces output according to format
* returns number of char printed excluding
*	: null byte '\0'
* write output to stdout stream
* @format: character string
* @nArgs: stores variable arguments
* char c for char
* @count: keeps count of characters
* Return: 0 Always true.
*
*/
void check_modifier(va_list nArgs, const char *format, int *count);
int _print(const char *format, ...)
{
	int count = 0;
	va_list nArgs;

	if (format == NULL)
		return (-1);

	va_start(nArgs, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == 'c')
			{
				int c = va_arg(nArgs, int);

				write(1, &c, 1);
				count++;
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(nArgs, char *);

				if (str != NULL)
				{
					write(1, str, strlen(str));
					count += strlen(str);
				}
			}
		}
		format++;
	}
	va_end(nArgs);
	return (count);
}
