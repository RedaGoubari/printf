#include "main.h"

/**
 * get_size - Calculates size to cast the argument
 * @format: Formatted string to print the arguments
 * @a: List of arguments to printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *a)
{
	int curr_i = *a + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*a = curr_i - 1;
	else
		*a = curr_i;

	return (size);
}
