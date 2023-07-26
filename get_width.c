#include "main.h"

/**
 * r_get_width - Calculates r_width for print
 * @format: Formatted string in which to print arg.
 * @r: r_list of arg printed.
 * @r_list: r_list arg.
 *
 * Return: r_width.
 */
int r_get_width(const char *format, int *r, va_list r_list)
{
	int r_curr_i;
	int r_width = 0;

	for (r_list = *r + 1; format[r_curr_i] != '\0'; r_curr_i++)
	{
		if (r_is_digit(format[r_curr_i]))
		{
			r_width *= 10;
			r_width += format[r_curr_i] - '0';
		}
		else if (format[r_curr_i] == '*')
		{
			r_curr_i++;
			r_width = va_arg(r_list, int);
			break;
		}
		else
			break;
	}

	*r = r_curr_i - 1;

	return (r_width);
}

