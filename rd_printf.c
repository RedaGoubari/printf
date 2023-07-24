#include "main.h"

/**
 * rd_printf - rd_formatted output conversion and print data.
 * @rd_format: string input.
 *
 * Return: number of chars printed.
 */
int rd_printf(const char *rd_format, ...)
{
	unsigned int rd_i = 0, rd_len = 0, rd_ibuf = 0;
	va_list arguments;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;

	va_start(arguments, rd_format), buffer = malloc(sizeof(char) * 1024);
	if (!rd_format || !buffer || (rd_format[rd_i] == '%' && !rd_format[rd_i + 1]))
		return (-1);
	if (!rd_format[rd_i])
		return (0);
	for (rd_i = 0; rd_format && rd_format[rd_i]; rd_i++)
	{
		if (rd_format[rd_i] == '%')
		{
			if (rd_format[rd_i + 1] == '\0')
			{	rd_print_buf(buffer, rd_ibuf), free(buffer), va_end(arguments);
				return (-1);
			}
			else
			{	function = rd_get_print_func(rd_format, rd_i + 1);
				if (function == NULL)
				{
					if (rd_format[rd_i + 1] == ' ' && !rd_format[rd_i + 2])
						return (-1);
					rd_handl_buf(buffer, rd_format[rd_i], rd_ibuf), rd_len++, rd_i--;
				}
				else
				{
					rd_len += function(arguments, buffer, rd_ibuf);
					rd_i += rd_ev_print_func(rd_format, rd_i + 1);
				}
			} rd_i++;
		}
		else
			rd_handl_buf(buffer, rd_format[rd_i], rd_ibuf), rd_len++;
		for (rd_ibuf = rd_len; rd_ibuf > 1024; rd_ibuf -= 1024)
			;
	}
	rd_print_buf(buffer, rd_ibuf), free(buffer), va_end(arguments);
	return (rd_len);
}

