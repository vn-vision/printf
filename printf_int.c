#include "main.h"


/**
* check_int_modifier - checks for int modifier
* returns the number of int printed excluding
* : null byte '\0'
* writes output to stdout stream
* @nArgs: List of var arguments.
* @format: integers
* @count: increment the numbers
* Return: void
*/

int check_int_modifier(va_list nArgs, const char **format, int *count)
{

		if (**format == 'i' || **format == 'd')
		{
			int nList = va_arg(nArgs, int);

			/**
			* Convert integer to string with dynamic allocation
			*/

			int len = snprintf(NULL, 0, "%d", nList);
			char *nList_String = malloc(len + 1);

			if (nList_String == NULL)
				return (-1);

			snprintf(nList_String, len + 1, "%d", nList);

			write(1, nList_String, len);

			(*count) += len;

			free(nList_String);
		}
	
		return (*count);
}
