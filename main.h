#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _rintf(const char format, ...);
void check_modifier(va_list nArgs, const char **format, unsigned int *count);

#endif
