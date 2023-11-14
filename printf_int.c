#include "main.h"


/**
* check_int_modifier - checks for int modifier
* returns the number of int printed excluding
* : null byte '\0'
* writes output to stdout stream
* @nArgs: List of var arguments.
* @*format: integers
* @count: increment the numbers
* Return: void 
*/

int check_int_modifier(va_list nArgs, const char **format, int *count)
{

		if (**format == 'i' || **format == 'd')
		{
			int num = va_arg(nArgs, int);

			/**
			* Convert integer to string with dynamic allocation
			*/
			
			int len = snprintf(NULL, 0, "%d", num);
			char *num_str = malloc(len + 1);
			if (num_str == NULL)
				return (-1);
				
			snprintf(num_str, len + 1, "%d", num);

			write(1, num_str, len);

			(*count) += len;

			free(num_str);
		}
		
		return (*count);
}
