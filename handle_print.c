#include "main.h"
/**
 * r_handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @r_list: r_list of arguments to be printed.
 * @r_ind: r_ind.
 * @r_buffer: r_buffer array handle print.
 * @r_flags: Calculates active r_flags
 * @r_width: get r_width.
 * @r_precision: r_precision specification
 * @r_size: r_size specifier
 * Return: 1 or 2;
 */
int r_handle_print(const char *fmt, int *r_ind, va_list r_list, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size)
{
	int r, r_unknow_len = 0, r_printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', r_print_char}, {'s', r_print_string}, {'%', r_print_percent},
		{'r', r_print_int}, {'d', r_print_int}, {'b', r_print_binary},
		{'u', r_print_unsigned}, {'o', r_print_octal}, {'x', r_print_hexadecimal},
		{'X', r_print_hexa_upper}, {'p', print_pointer}, {'S', r_print_non_printable},
		{'r', r_print_reverse}, {'R', r_print_rot13string}, {'\0', NULL}
	};
	for (r = 0; fmt_types[r].fmt != '\0'; r++)
		if (fmt[*r_ind] == fmt_types[r].fmt)
			return (fmt_types[r].fn(r_list, r_buffer, r_flags, r_width, r_precision, r_size));

	if (fmt_types[r].fmt == '\0')
	{
		if (fmt[*r_ind] == '\0')
			return (-1);
		r_unknow_len += write(1, "%%", 1);
		if (fmt[*r_ind - 1] == ' ')
			r_unknow_len += write(1, " ", 1);
		else if (r_width)
		{
			--(*r_ind);
			while (fmt[*r_ind] != ' ' && fmt[*r_ind] != '%')
				--(*r_ind);
			if (fmt[*r_ind] == ' ')
				--(*r_ind);
			return (1);
		}
		r_unknow_len += write(1, &fmt[*r_ind], 1);
		return (r_unknow_len);
	}
	return (r_printed_chars);
}

