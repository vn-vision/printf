#include "main.h"

/**
* check_string_modifier - produces output according to format
* returns number of char printed excluding
*	: null byte '\0'
* write output to stdout stream
* @nArgs: List of var arguments.
* @format: integers
* @count: increment the numbers
* Return: void
*
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

		if (str != NULL)
		{
			write(1, str, strlen(str));
			(*count) += strlen(str);
		}
	}

	return (*count);
}
