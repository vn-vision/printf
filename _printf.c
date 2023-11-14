#include "main.h"

/**
* _printf - produces output according to format
* returns number of char printed excluding
*	: null byte '\0'
* write output to stdout stream
* @format: character string
* Return: 0 Always true.
*
*/

int _printf(const char *format, ...)
{
	int count = 0;
	va_list nArgs;

	if (format == NULL)
		return (-1);

	va_start(nArgs, format);

	while (format && *format != '\0')
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

			/**
			* char_string modifiers
			*/
				
			check_string_modifier(nArgs, &format, &count);
			
			/**
			* integer modifiers
			*/
			
			check_int_modifier(nArgs, &format, &count);
		}
		format++;
	}
	
	va_end(nArgs);
	return (count);
}
