#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
* _print - produces output according to format
* returns number of char printed excluding
*	: null byte '\0'
* write output to stdout stream
* @format: character string
* @nArgs: stores variable arguments
* @count: keeps count of characters
* Return: 0 Always true.
*
*/

void check_modifier(va_list nArgs, const char *format, int *count);

int _print(const char *format, ...)
{
	int count = 0, i = 0;
	va_list nArgs;

	/**
	* check whether format is empty
	*/
	if (format == NULL)
		return (-1);

	va_start(nArgs, format);

	/**
	* check whether index points to null byte
	* loop until null byte is reached
	*/
	while (*format)
	{
		/**
		* check if index points to %
		* if so check the next char
		* if not print the char
		*/
		if (format[i] != '%')
		{
			format++;
			if (format[i] == '\0')
				break;

			/**
			* char c for char
			*/
			if (format[i] == 'c')
			{
				char c = va_arg(nArgs, int);

				write(1, &c, 1);
				count++;
			}
			else if (format[i] == '%')
			{
				write(1, format, 1);
				count++;
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(nArgs, char *);

				if (str != NULL && *str != '\0')
				{
					write(1, str, strlen(str));
					count += strlen(str);
				}
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(nArgs);
	return (count);
}
