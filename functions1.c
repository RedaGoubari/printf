#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * r_print_unsigned - Prints an unsigned number
 * @r_types: arguments list
 * @r_buffer: r_buffer array handle print
 * @r_flags:  Calculates r_flags active
 * @r_width: get r_width
 * @r_precision: specification r_precision
 * @r_size: r_size specifier
 * Return:  characters Number printed .
 */
int r_print_unsigned(va_list r_types, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size)
{
	int r = BUFF_SIZE - 2;
	unsigned long int r_num = va_arg(r_types, unsigned long int);

	r_num = convert_size_unsgnd(r_num, r_size);

	if (r_num == 0)
		r_buffer[r--] = '0';

	r_buffer[BUFF_SIZE - 1] = '\0';

	while (r_num > 0)
	{
		r_buffer[r--] = (r_num % 10) + '0';
		r_num /= 10;
	}

	r++;

	return (r_write_unsgnd(0, r, r_buffer,
				r_flags, r_width, r_precision, r_size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * r_print_octal - Prints an unsigned number in octal notation
 * @r_types: Lista of arguments
 * @r_buffer: r_buffer array handle print
 * @r_flags:  Calculates r_flags active
 * @r_width: get r_width
 * @r_precision: specification r_precision
 * @r_size: r_size specifier
 * Return:  characters Number printed
 */
int r_print_octal(va_list r_types, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size)
{

	int r = BUFF_SIZE - 2;
	unsigned long int r_num = va_arg(r_types, unsigned long int);
	unsigned long int r_init_num = r_num;

	UNUSED(r_width);

	r_num = convert_size_unsgnd(r_num, r_size);

	if (r_num == 0)
		r_buffer[r--] = '0';

	r_buffer[BUFF_SIZE - 1] = '\0';

	while (r_num > 0)
	{
		r_buffer[r--] = (r_num % 8) + '0';
		r_num /= 8;
	}

	if (r_flags & F_HASH && r_init_num != 0)
		r_buffer[r--] = '0';

	r++;

	return (r_write_unsgnd(0, r, r_buffer,
				r_flags, r_width, r_precision, r_size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * r_print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @r_types: Lista of arguments
 * @r_buffer: r_buffer array handle print
 * @r_flags:  Calculates r_flags active
 * @r_width: get r_width
 * @r_precision: specification r_precision
 * @r_size: r_size specifier
 * Return:  characters Number printed
 */
int r_print_hexadecimal(va_list r_types, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size)
{
	return (r_print_hexa(r_types, "0123456789abcdef", r_buffer,
		r_flags, 'x', r_width, r_precision, r_size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * r_print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @r_types: Lista of arguments
 * @r_buffer: r_buffer array handle print
 * @r_flags:  Calculates r_flags active
 * @r_width: get r_width
 * @r_precision: specification r_precision
 * @r_size: r_size specifier
 * Return:  characters Number printed
 */
int r_print_hexa_upper(va_list r_types, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size)
{
	return (r_print_hexa(r_types, "0123456789ABCDEF", r_buffer,
		r_flags, 'X', r_width, r_precision, r_size));
}

/************** PRINT HEXX r_num IN LOWER OR UPPER **************/
/**
 * r_print_hexa - Prints a hexadecimal number in lower or upper
 * @r_types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @r_buffer: r_buffer array handle print
 * @r_flags:  Calculates r_flags active
 * @flag_ch: Calculates r_flags active
 * @r_width: get r_width
 * @r_precision: specification r_precision
 * @r_size: r_size specifier
 * @r_size: r_size specification
 * Return:  characters Number printed.
 */
int r_print_hexa(va_list r_types, char map_to[], char r_buffer[],
	int r_flags, char flag_ch, int r_width, int r_precision, int r_size)
{
	int r = BUFF_SIZE - 2;
	unsigned long int r_num = va_arg(r_types, unsigned long int);
	unsigned long int r_init_num = r_num;

	UNUSED(r_width);

	r_num = convert_size_unsgnd(r_num, r_size);

	if (r_num == 0)
		r_buffer[r--] = '0';

	r_buffer[BUFF_SIZE - 1] = '\0';

	while (r_num > 0)
	{
		r_buffer[r--] = map_to[r_num % 16];
		r_num /= 16;
	}

	if (r_flags & F_HASH && r_init_num != 0)
	{
		r_buffer[r--] = flag_ch;
		r_buffer[r--] = '0';
	}

	r++;

	return (r_write_unsgnd(0, r, r_buffer,
				r_flags, r_width, r_precision, r_size));
}





