#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - function printf
 * @format: format.
 * Return: _printed characters.
 */
int _printf(const char *format, ...)
{
	int r, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(r_list, format);

	for (r = 0; format && format[r] != '\0'; r++)
	{
		if (format[r] != '%')
		{
			buffer[r_buff_ind++] = format[r];
			if (r_buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[r], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = r_get_flags(format, &r);
			width = r_get_width(format, &r, r_list);
			precision = r_get_precision(format, &r, r_list);
			size = r_get_size(format, &r);
			++r;
			printed = r_handle_print(format, &r, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents the buffer if exist
 * @buffer: Array of characters
 * @buff_ind: Index which to add characters, represents length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

