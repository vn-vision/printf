#include <main.h>

int _printf(const char *format, ...)
{
	va_list printme;
	int no_char = 0;

	va_start(printme, format );

	while(*format != '\0')
	{
		if (*format == '%')
		{
			format ++;
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

			return(-1);
		}
	}
	else 
	{
		printme += write(1, format, 1);
	}
	format++;
}
	va_end(printme);
	return no_char;
	}

int main()
{
	_printf("Integer: %d \n", 42);
	return 0;
}
