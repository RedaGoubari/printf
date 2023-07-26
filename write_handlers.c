#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * r_handle_write_char - Prints string
 * @d: char types.
 * @r_buffer: r_buffer array handle to print
 * @r_flags:  Calculates r_flags active.
 * @r_width: get r_width.
 * @r_precision: specifier r_precision
 * @r_size: specifier r_size
 *
 * Return: Number of chars printed.
 */
int r_handle_write_char(char d, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size)
{ /* char is stored at left and paddind at r_buffer's right */
	int r = 0;
	char r_padd = ' ';

	UNUSED(r_precision);
	UNUSED(r_size);

	if (r_flags & F_ZERO)
		r_padd = '0';

	r_buffer[r++] = d;
	r_buffer[r] = '\0';

	if (r_width > 1)
	{
		r_buffer[BUFF_SIZE - 1] = '\0';
		for (r = 0; r < r_width - 1; r++)
			r_buffer[BUFF_SIZE - r - 2] = r_padd;

		if (r_flags & F_MINUS)
			return (write(1, &r_buffer[0], 1) +
					write(1, &r_buffer[BUFF_SIZE - r - 1], r_width - 1));
		else
			return (write(1, &r_buffer[BUFF_SIZE - r - 1], r_width - 1) +
					write(1, &r_buffer[0], 1));
	}

	return (write(1, &r_buffer[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * r_write_number - Prints string
 * @is_negative: arguments Lista
 * @r_ind: char types.
 * @r_buffer: r_buffer array handle print
 * @r_flags:  Calculates r_flags active
 * @r_width: get r_width.
 * @r_precision: specifier r_precision
 * @r_size: specifier r_size
 *
 * Return: Number of char printed.
 */
int r_write_number(int is_negative, int r_ind, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size)
{
	int r_length = BUFF_SIZE - r_ind - 1;
	char r_padd = ' ', r_extra_ch = 0;

	UNUSED(r_size);

	if ((r_flags & F_ZERO) && !(r_flags & F_MINUS))
		r_padd = '0';
	if (is_negative)
		r_extra_ch = '-';
	else if (r_flags & F_PLUS)
		r_extra_ch = '+';
	else if (r_flags & F_SPACE)
		r_extra_ch = ' ';

	return (r_write_num(r_ind, r_buffer, r_flags, r_width, r_precision,
		r_length, r_padd, r_extra_ch));
}

/**
 * r_write_num - Write number using a buffer
 * @r_ind: Index  which the number starts  the buffer
 * @r_buffer: r_buffer
 * @r_flags: r_flags
 * @r_width: r_width
 * @r_prec: precision specifier
 * @r_length: lenght Number
 * @r_padd: chararacter Pading
 * @extra_c: Extra chararacter
 *
 * Return: Number of printed chars.
 */
int r_write_num(int r_ind, char r_buffer[],
	int r_flags, int r_width, int r_prec,
	int r_length, char r_padd, char extra_c)
{
	int r, r_padd_start = 1;

	if (r_prec == 0 && r_ind == BUFF_SIZE - 2 && r_buffer[r_ind] == '0' && r_width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (r_prec == 0 && r_ind == BUFF_SIZE - 2 && r_buffer[r_ind] == '0')
		r_buffer[r_ind] = r_padd = ' '; /* r_width is displayed with padding ' ' */
	if (r_prec > 0 && r_prec < r_length)
		r_padd = ' ';
	while (r_prec > r_length)
		r_buffer[--r_ind] = '0', r_length++;
	if (extra_c != 0)
		r_length++;
	if (r_width > r_length)
	{
		for (r = 1; r < r_width - r_length + 1; r++)
			r_buffer[r] = r_padd;
		r_buffer[r] = '\0';
		if (r_flags & F_MINUS && r_padd == ' ')/* Asign extra char to left of r_buffer */
		{
			if (extra_c)
				r_buffer[--r_ind] = extra_c;
			return (write(1, &r_buffer[r_ind], r_length) + write(1, &r_buffer[1], r - 1));
		}
		else if (!(r_flags & F_MINUS) && r_padd == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				r_buffer[--r_ind] = extra_c;
			return (write(1, &r_buffer[1], r - 1) + write(1, &r_buffer[r_ind], r_length));
		}
		else if (!(r_flags & F_MINUS) && r_padd == '0')/* extra char to left of r_padd */
		{
			if (extra_c)
				r_buffer[--r_padd_start] = extra_c;
			return (write(1, &r_buffer[r_padd_start], r - r_padd_start) +
				write(1, &r_buffer[r_ind], r_length - (1 - r_padd_start)));
		}
	}
	if (extra_c)
		r_buffer[--r_ind] = extra_c;
	return (write(1, &r_buffer[r_ind], r_length));
}

/**
 * r_write_unsgnd - Writes unsigned number
 * @is_negative: Num indicating if the num is negative
 * @r_ind: Index at which the number starts in the r_buffer
 * @r_buffer: Array of characters
 * @r_flags: specifiers flags
 * @r_width: specifier width
 * @r_precision: precision specifier
 * @r_size: size specifier
 *
 * Return: Number of written characters.
 */
int r_write_unsgnd(int is_negative, int r_ind,
	char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size)
{
	/* The number stored at the buffer's right and starts at position r */
	int r_length = BUFF_SIZE - r_ind - 1, r = 0;
	char r_padd = ' ';

	UNUSED(is_negative);
	UNUSED(r_size);

	if (r_precision == 0 && r_ind == BUFF_SIZE - 2 && r_buffer[r_ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (r_precision > 0 && r_precision < r_length)
		r_padd = ' ';

	while (r_precision > r_length)
	{
		r_buffer[--r_ind] = '0';
		r_length++;
	}

	if ((r_flags & F_ZERO) && !(r_flags & F_MINUS))
		r_padd = '0';

	if (r_width > r_length)
	{
		for (r = 0; r < r_width - r_length; r++)
			r_buffer[r] = r_padd;

		r_buffer[r] = '\0';

		if (r_flags & F_MINUS) /* Asign extra character to left of buffer [r_buffer>r_padd]*/
		{
			return (write(1, &r_buffer[r_ind], r_length) + write(1, &r_buffer[0], r));
		}
		else /* Asign extra character to left of padding [r_padd>r_buffer]*/
		{
			return (write(1, &r_buffer[0], r) + write(1, &r_buffer[r_ind], r_length));
		}
	}

	return (write(1, &r_buffer[r_ind], r_length));
}

/**
 * r_write_pointer - Write address memory
 * @r_buffer: Arrays of characters
 * @r_ind: Index which the number starts in the r_buffer
 * @r_length: length number
 * @r_width: specifier width
 * @r_flags: specifier flags
 * @r_padd: Character representing the padding
 * @extra_c: Character representing extra character
 * @r_padd_start: Index at which padding should start
 *
 * Return: Number of written characters.
 */
int r_write_pointer(char r_buffer[], int r_ind, int r_length,
	int r_width, int r_flags, char r_padd, char extra_c, int r_padd_start)
{
	int r;

	if (r_width > r_length)
	{
		for (r = 3; r < r_width - r_length + 3; r++)
			r_buffer[r] = r_padd;
		r_buffer[r] = '\0';
		if (r_flags & F_MINUS && r_padd == ' ')/* Asign extra char to left of r_buffer */
		{
			r_buffer[--r_ind] = 'x';
			r_buffer[--r_ind] = '0';
			if (extra_c)
				r_buffer[--r_ind] = extra_c;
			return (write(1, &r_buffer[r_ind], r_length) + write(1, &r_buffer[3], r - 3));
		}
		else if (!(r_flags & F_MINUS) && r_padd == ' ')/* extra char to left of r_buffer */
		{
			r_buffer[--r_ind] = 'x';
			r_buffer[--r_ind] = '0';
			if (extra_c)
				r_buffer[--r_ind] = extra_c;
			return (write(1, &r_buffer[3], r - 3) + write(1, &r_buffer[r_ind], r_length));
		}
		else if (!(r_flags & F_MINUS) && r_padd == '0')/* extra char to left of r_padd */
		{
			if (extra_c)
				r_buffer[--r_padd_start] = extra_c;
			r_buffer[1] = '0';
			r_buffer[2] = 'x';
			return (write(1, &r_buffer[r_padd_start], r - r_padd_start) +
				write(1, &r_buffer[r_ind], r_length - (1 - r_padd_start) - 2));
		}
	}
	r_buffer[--r_ind] = 'x';
	r_buffer[--r_ind] = '0';
	if (extra_c)
		r_buffer[--r_ind] = extra_c;
	return (write(1, &r_buffer[r_ind], BUFF_SIZE - r_ind - 1));
}

