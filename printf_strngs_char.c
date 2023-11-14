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
		switch (**format)
		{
			case ('c'):
			{
				char chr = va_arg(nArgs, int);

				write(1, &chr, 1);
				(*count)++;
				break;
			}
			case ('s'):
			{
				char *str = va_arg(nArgs, char *);

				if (str == NULL && *str == '\0')
				{
					write(1, "(null)", 6);
					(*count) += 6;
				}
				else
				{
					write(1, str, strlen(str));
					(*count) += strlen(str);
				}
				break;
			}
			case ('%'):
				write(1, "%", 1);
				(*count)++;
				break;
			default:
				write(1, *format, 1);
				(*count)++;
				break;
		}
}
