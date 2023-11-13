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
	while (format && format[i] != '\0')
	{
		/**
		* check if index points to %
		* if so check the next char
		* if not print the char
		*/
		if (format[i] == '%')
		{
			format++;
			if (format[i] == '\0')
				break;

			/**
			* char c for char
			*/
			if (format[i] == "c")
			{
				write(1, va_arg(nArgs, int), 1);
				count++;
			}
			else if (format[i] == "%")
			{
				write(1, format, 1);
				count += 2;
			}
			else if (format[i] == "s")
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
		i++;
	}

}
