#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
 
int _printf(const char *format, ...);
 
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    
    printf("**** THIS IS THE {{{OG}}} PRINTF*****\n\n");

    len2 = printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Percent:[%%]\n");
    printf("String:[%s]\n", "I am a string !");
    printf("Character:[%c]\n", 'H');
    printf("Unsigned:[%u]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Address:[%p]\n", addr);
    printf("Len:[%d]\n", len2);
    printf("Length:[%d, %i]\n", len2, len2);
    printf("Unknown:[%%r]\n");
    printf("Negative:[%d]\n", -762534);
    
    printf("\n\n**** THIS IS WHERE I START TESTING MY _PRINTF*****\n\n");
    
    len = _printf("Let's try to printf a simple sentence.\n");
    len = _printf("Percent:[%%]\n");
    printf("\n");
    _printf("String:[%s]\n", "I am a string !");
     printf("\n");
    _printf("Character:[%c]\n", 'H');
    printf("\n");
    _printf("Unsigned:[%u]\n", ui);
    printf("\n");
    _printf("Unsigned octal:[%o]\n", ui);
    printf("\n");
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("\n");
    _printf("Address:[%p]\n", addr);
    printf("\n");
    _printf("Len:[%d]\n", len);
     printf("\n");
    _printf("Length:[%d, %i]\n", len2, len2);
    _printf("Unknown:[%r]\n");
     printf("\n"); 
    _printf("Negative:[%d]\n", -762534);
    return (0);
}
