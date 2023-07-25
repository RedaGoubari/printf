#include "main.h"

/**
 * r_get_precision - Calculates r_precision for printing
 * @format: Formatted string in which print the arg
 * @r: r_list of arguments toprinted.
 * @r_list: arguments of r_list.
 * Return: r_precision.
 */
int r_get_precision(const char *format, int *r, va_list r_list)
{
	int r_curr_i = *r + 1;
	int r_precision = -1;

	if (format[r_curr_i] != '.')
		return (r_precision);

	r_precision = 0;

	for (r_curr_i += 1; format[r_curr_i] != '\0'; r_curr_i++)
	{
		if (r_is_digit(format[r_curr_i]))
		{
			r_precision *= 10;
			r_precision += format[r_curr_i] - '0';
		}
		else if (format[r_curr_i] == '*')
		{
			r_curr_i++;
			r_precision = va_arg(r_list, int);
			break;
		}
		else
			break;
	}

	*r = r_curr_i - 1;

	return (r_precision);
}
