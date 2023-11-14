#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int _printf(const char *format, ...);
void check_string_modifier(va_list nArgs, const char **format, int *count);
int check_int_modifier(va_list nArgs, const char **format, int *count);

#endif
