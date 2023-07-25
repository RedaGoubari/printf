#include "main.h"

/**
 * r_get_size - Calculates the r_size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @r: List of arguments to be printed.
 *
 * Return: Precision.
 */
int r_get_size(const char *format, int *r)
{
	int r_curr_i = *r + 1;
	int r_size = 0;

	if (format[r_curr_i] == 'l')
		r_size = S_LONG;
	else if (format[r_curr_i] == 'h')
		r_size = S_SHORT;

	if (r_size == 0)
		*r = r_curr_i - 1;
	else
		*r = r_curr_i;

	return (r_size);
}
