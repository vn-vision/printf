#include "main.h"


/**
* _printf - produces output according to format
* returns the number of characters printed excluding
* : null byte '\0'
* writes output to stdout stream
* @format: integers
* Return: 0 Always true.
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
		* char i, d for ints
		*/
		if (format[i] == 'i' || format[i] == 'd')
		{
			int num = va_arg(nArgs, int);

			/**
			* Convert integer to string with dynamic allocation
			*/
			int len = snprintf(NULL, 0, "%d", num);
			char *num_str = malloc(len + 1);
			if (num_str == NULL)
			{
				return -1;
			}
			snprintf(num_str, len + 1, "%d", num);

			write(1, num_str, len);

			count += len;

			free(num_str);
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		i++;
	}

	va_end(nArgs);
	return count;
}
