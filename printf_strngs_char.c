#include "main.h"

/**
* check_string_modifier - checks modifier type
* @nArgs: the variable list
* @format: the string passed in _printf()
* @count: counter
* Return: void
*/

void check_string_modifier(va_list nArgs, const char **format, int *count)
{
	if (**format == 'c')
	{
		char c = va_arg(nArgs, int);

		write(1, &c, 1);
		(*count)++;
	}
	else if (**format == '%')
	{
		write(1, "%", 1);
		(*count)++;
	}
	else if (**format == 's')
	{
		char *str = va_arg(nArgs, char *);

		if (str != NULL && *str != '\0')
		{
			write(1, str, strlen(str));
			(*count) += strlen(str);
		}
	}
}
