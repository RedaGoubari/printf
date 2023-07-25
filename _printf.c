#include "main.h"

void print_r_buffer(char r_buffer[], int *buff_ind);

/**
 * _printf - printf function
 * @format: format.
 * Return: printed char.
 */
int _printf(const char *format, ...)
{
	int r, r_print = 0, printed_characters = 0;
	int r_flags, r_width, r_precision, size, buff_ind = 0;
	va_list r_list;
	char r_buffer[BUFF_r_size];

	if (format == NULL)
		return (-1);

	va_start(r_list, format);

	for (r = 0; format && format[r] != '\0'; r++)
	{
		if (format[r] != '%')
		{
			r_buffer[r_buff_ind++] = format[r];
			if (r_buff_ind == BUFF_r_size)
				print_r_buffer(r_buffer, &buff_ind);
			/* write(1, &format[r], 1);*/
			printed_characters++;
		}
		else
		{
			print_r_buffer(r_buffer, &buff_ind);
			r_flags = r_get_flags(format, &r);
			r_width = r_get_width(format, &r, r_list);
			r_precision = r_get_precision(format, &r, r_list);
			size = get_size(format, &r);
			++r;
			printed = r_handle_print(format, &r, r_list, r_buffer,
				r_flags, r_width, r_precision, size);
			if (printed == -1)
				return (-1);
			printed_characters += printed;
		}
	}

	print_r_buffer(r_buffer, &buff_ind);

	va_end(r_list);

	return (printed_characters);
}

/**
 * print_r_buffer - Prints the contents the r_buffer if exist
 * @r_buffer: Array of characters
 * @buff_ind: Index which to add characters, represents length.
 */
void print_r_buffer(char r_buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &r_buffer[0], *buff_ind);

	*buff_ind = 0;
}

