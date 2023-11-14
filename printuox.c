#include "main.h"

int w_cha(int C)
{
	return write(1, &C, 1);
}

int w_string(char *string)
{
	if (string != NULL)
		return write(1, string, strlen(str));
	return (0);
}
int w_unsigned(va_list Dec)
{
	unsigned int yuji = va_arg(Dec, unsigned int);
	char buffer [20];
	int length = snprintf(buffr, sizeof(buffer),"%u",num);
	return w_string(buffer);
}

int w_oct(va_list Dec)
{
	unsigned int yuji = va_arg(Dec, unsigned int);
	char buffer[20];
	int length = snprintf(buffer, sizeof(buffer), "%o", num);
	return write_string(buffer);
}
int w_hexa(va_list Dec, int upperCase)
{
	unsigned int yuji = va_arg(dec, unsigned int);
	char buffer[20];
	const char *format = (uppercase) ? "%X" : "%x";
	int len = snprintf(buffer, sizeof(buffer), format, num);
	return write_string(buffer);
}
int _printf(const char *format, ...)
{
	int count = 0;
	va_list Dec;

	if (format == NULL)
		return (-1);

	va_start(Dec, format);

	while (*format)
	{
		if (*format != '%')
		{
			count += w_cha(*format);
		}
		else
		{
			format++;

			if (*format == '\0')
				break;

			switch (*format)
			{
				case 'C':
					count += w_cha(va_arg(Dec, int));
					break;
				case 'S':
					count += w_string(va_arg(Dec, char *));
					break;
				case 'u':
					count += w_unsigned(Dec);
					break
				case 'o':
					count += w_oct(Dec);
					break;
				case 'x':
					count += w_hexa(Dec, 0);
					break
				case 'X':
					count += w_hexa(Dec, 1);
					break;
			}
		}
		format++;

	}

	va_end(Dec);
	return count;
}
