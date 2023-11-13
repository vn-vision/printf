#include <main.h>
/**
 * _printf -  creates a function that looks for format specifiers
 * returns number of char printed excluding
 *  : null byte '\0'
 * @format:  string output
 * write in output in standardoutput format
 * @printme:
 * @no_char:
 * Return: no of characters
 */

int _printf(const char *format, ...)
{
	va_list printme;
	int no_char = 0;

	va_start(printme, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'd':
				case 'i':
				{
				int num = va_arg(args, int);
				char buffer[12];
				int len = sprintf(buffer, "%d", num);

				printme += write(1, buffer, len);
				}
			break;
			default:

			return (-1);
		}
	}
	else
	{
		printme += write(1, format, 1);
	}
	format++;
}
	va_end(printme);
	return (no_char);
	}
/**
 * main - prints the output
 * Return: 0
 */
int main(void)
{
	_printf("Integer: %d \n", 42);
	return (0);
}
