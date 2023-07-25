#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * r_print_pointer - Prints value of a pointer variable
 * @r_types: Lista of arguments
 * @r_buffer: r_buffer array handle print
 * @r_flags:  Calculates r_flags active
 * @r_width: get r_width
 * @r_precision: specification r_precision
 * @r_size: specifier r_size 
 * Return: characters Number printed.
 */
int r_print_pointer(va_list r_types, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size)
{
	char r_extra_c = 0, r_padd = ' ';
	int r_ind = BUFF_SIZE - 2, r_length = 2, r_padd_start = 1; /* r_length=2, for '0x' */
	unsigned long r_num_addrs;
	char r_map_to[] = "0123456789abcdef";
	void *r_addrs = va_arg(r_types, void *);

	UNUSED(r_width);
	UNUSED(r_size);

	if (r_addrs == NULL)
		return (write(1, "(nil)", 5));

	r_buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(r_precision);

	r_num_addrs = (unsigned long)r_addrs;

	while (r_num_addrs > 0)
	{
		r_buffer[r_ind--] = r_map_to[r_num_addrs % 16];
		r_num_addrs /= 16;
		r_length++;
	}

	if ((r_flags & F_ZERO) && !(r_flags & F_MINUS))
		r_padd = '0';
	if (r_flags & F_PLUS)
		r_extra_c = '+', r_length++;
	else if (r_flags & F_SPACE)
		r_extra_c = ' ', r_length++;

	r_ind++;

	/*return (write(1, &r_buffer[r], BUFF_SIZE - r - 1));*/
	return (r_write_pointer(r_buffer, r_ind, r_length,
		r_width, r_flags, r_padd, r_extra_c, r_padd_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * r_print_non_printable - Prints ascii codes in hexa of non printable characters
 * @r_types: Lista of arguments
 * @r_buffer: r_buffer array handle print
 * @r_flags:  Calculates r_flags active
 * @r_width: get r_width
 * @r_precision: specification r_precision
 * @r_size: specifier r_size 
 * Return: characters Number printed
 */
int r_print_non_printable(va_list r_types, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size)
{
	int r = 0, r_offset = 0;
	char *r_str = va_arg(r_types, char *);

	UNUSED(r_flags);
	UNUSED(r_width);
	UNUSED(r_precision);
	UNUSED(r_size);

	if (r_str == NULL)
		return (write(1, "(null)", 6));

	while (r_str[r] != '\0')
	{
		if (r_is_printable(r_str[r]))
			r_buffer[r + r_offset] = r_str[r];
		else
			r_offset += r_append_hexa_code(r_str[r], r_buffer, r + r_offset);

		r++;
	}

	r_buffer[r + r_offset] = '\0';

	return (write(1, r_buffer, r + r_offset));
}

/************************* PRINT REVERSE *************************/
/**
 * r_print_reverse - reverse string Prints .
 * @r_types: Lista of arguments
 * @r_buffer: r_buffer array handle print
 * @r_flags:  Calculates r_flags active
 * @r_width: get r_width
 * @r_precision: specification r_precision
 * @r_size: specifier r_size 
 * Return: Numbers of chars printed
 */

int r_print_reverse(va_list r_types, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size)
{
	char *r_str;
	int r, r_count = 0;

	UNUSED(r_buffer);
	UNUSED(r_flags);
	UNUSED(r_width);
	UNUSED(r_size);

	r_str = va_arg(r_types, char *);

	if (r_str == NULL)
	{
		UNUSED(r_precision);

		r_str = ")Null(";
	}
	for (r = 0; r_str[r]; r++)
		;

	for (r = r - 1; r >= 0; r--)
	{
		char z = r_str[r];

		write(1, &z, 1);
		r_count++;
	}
	return (r_count);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * r_print_rot13string - Print a string in rot13.
 * @r_types: Lista of arguments
 * @r_buffer: r_buffer array handle print
 * @r_flags:  Calculates r_flags active
 * @r_width: get r_width
 * @r_precision: specification r_precision
 * @r_size: specifier r_size 
 * Return: Numbers of chars printed
 */
int r_print_rot13string(va_list r_types, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size)
{
	char z;
	char *r_str;
	unsigned int r, e;
	int r_count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	r_str = va_arg(r_types, char *);
	UNUSED(r_buffer);
	UNUSED(r_flags);
	UNUSED(r_width);
	UNUSED(r_precision);
	UNUSED(r_size);

	if (r_str == NULL)
		r_str = "(AHYY)";
	for (r = 0; r_str[r]; r++)
	{
		for (e = 0; in[e]; e++)
		{
			if (in[e] == r_str[r])
			{
				z = out[e];
				write(1, &z, 1);
				r_count++;
				break;
			}
		}
		if (!in[e])
		{
			z = r_str[r];
			write(1, &z, 1);
			r_count++;
		}
	}
	return (r_count);
}


