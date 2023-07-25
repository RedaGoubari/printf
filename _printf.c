#include "main.h"

void print_buffer(char r_buffer[], int *r_buff_ind);

/**
 * _printf - function printf
 * @format: format.
 * Return: _printed characters.
 */
int _printf(const char *format, ...)
{
	int r, r_printed = 0, r_printed_chars = 0;
	int r_flags, r_width, r_precision, r_size, r_buff_ind = 0;
	va_list r_list;
	char r_buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(r_list, format);

	for (r = 0; format && format[r] != '\0'; r++)
	{
		if (format[r] != '%')
		{
			r_buffer[r_buff_ind++] = format[r];
			if (r_buff_ind == BUFF_SIZE)
				print_buffer(r_buffer, &r_buff_ind);
			/* write(1, &format[r], 1);*/
			r_printed_chars++;
		}
		else
		{
			print_buffer(r_buffer, &r_buff_ind);
			r_flags = r_get_flags(format, &r);
			r_width = r_get_width(format, &r, r_list);
			r_precision = r_get_precision(format, &r, r_list);
			r_size = r_get_size(format, &r);
			++r;
			r_printed = r_handle_print(format, &r, r_list, r_buffer,
				r_flags, r_width, r_precision, r_size);
			if (r_printed == -1)
				return (-1);
			r_printed_chars += r_printed;
		}
	}

	print_buffer(r_buffer, &r_buff_ind);

	va_end(r_list);

	return (r_printed_chars);
}

/**
 * print_buffer - Prints the contents the r_buffer if exist
 * @r_buffer: Array of characters
 * @r_buff_ind: Index which to add characters, represents length.
 */
void print_buffer(char r_buffer[], int *r_buff_ind)
{
	if (*r_buff_ind > 0)
		write(1, &r_buffer[0], *r_buff_ind);

	*r_buff_ind = 0;
}

