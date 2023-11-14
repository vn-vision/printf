#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * _print - produces output according to format
 * @format: character string
 * @...: variable arguments
 *
 * Return: Number of characters printed (excluding null byte '\0').
 */
int _print(const char *format, ...)
{
    int count = 0;
    va_list nArgs;

    if (format == NULL)
        return -1;

    va_start(nArgs, format);

    while (*format)
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

            if (*format == 'c')
            {
                int c = va_arg(nArgs, int);
                write(1, &c, 1);
                count++;
            }
            else if (*format == '%')
            {
                write(1, format, 1);
                count++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(nArgs, char *);

                if (str != NULL && *str != '\0')
                {
                    write(1, str, strlen(str));
                    count += strlen(str);
                }
            }
        }
        format++;
    }

    va_end(nArgs);
    return count;
}
