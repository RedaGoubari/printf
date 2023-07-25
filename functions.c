#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * r_print_char - Prints a chararacters
 * @r_types: arguments List
 * @r_buffer: r_buffer array handle print
 * @r_flags:  Calculates r_flags active
 * @r_width: r_width
 * @r_precision: specification r_precision
 * @r_size: r_size specifier
 * Return: characters printed Number
 */
int r_print_char(va_list r_types, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size)
{
	char d = va_arg(r_types, int);

	return (r_handle_write_char(d, r_buffer, r_flags, r_width, r_precision, r_size));
}
/************************* PRINT A STRING *************************/
/**
 * r_print_string - Prints string
 * @r_types: arguments List
 * @r_buffer: r_buffer array handle print
 * @r_flags:  Calculates r_flags active
 * @r_width: get r_width.
 * @r_precision: specification r_precision
 * @r_size: r_size specifier
 * Return:  characters printed Number
 */
int r_print_string(va_list r_types, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size)
{
	int r_length = 0, r;
	char *r_str = va_arg(r_types, char *);

	UNUSED(r_buffer);
	UNUSED(r_flags);
	UNUSED(r_width);
	UNUSED(r_precision);
	UNUSED(r_size);
	if (r_str == NULL)
	{
		r_str = "(null)";
		if (r_precision >= 6)
			r_str = "      ";
	}

	while (r_str[r_length] != '\0')
		r_length++;

	if (r_precision >= 0 && r_precision < r_length)
		r_length = r_precision;

	if (r_width > r_length)
	{
		if (r_flags & F_MINUS)
		{
			write(1, &r_str[0], r_length);
			for (r = r_width - r_length; r > 0; r--)
				write(1, " ", 1);
			return (r_width);
		}
		else
		{
			for (r = r_width - r_length; r > 0; r--)
				write(1, " ", 1);
			write(1, &r_str[0], r_length);
			return (r_width);
		}
	}

	return (write(1, r_str, r_length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * r_print_percent - percent sign Prints
 * @r_types: Lista of arguments
 * @r_buffer: r_buffer array to handle print
 * @r_flags:  Calculates r_flags active
 * @r_width: get r_width.
 * @r_precision: specification r_precision
 * @r_size: r_size specifier
 * Return:  characters printed Number
 */
int r_print_percent(va_list r_types, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size)
{
	UNUSED(r_types);
	UNUSED(r_buffer);
	UNUSED(r_flags);
	UNUSED(r_width);
	UNUSED(r_precision);
	UNUSED(r_size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * r_print_int - int Print
 * @r_types: Lista of arguments
 * @r_buffer: r_buffer array to handle print
 * @r_flags:  Calculates r_flags active
 * @r_width: get r_width.
 * @r_precision: specification r_precision
 * @r_size: r_size specifier
 * Return:  characters printed Number
 */
int r_print_int(va_list r_types, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size)
{
	int r = BUFF_SIZE - 2;
	int r_is_negative = 0;
	long int y = va_arg(r_types, long int);
	unsigned long int r_num;

	y = r_convert_size_number(y, r_size);

	if (y == 0)
		r_buffer[r--] = '0';

	r_buffer[BUFF_SIZE - 1] = '\0';
	r_num = (unsigned long int)y;

	if (y < 0)
	{
		r_num = (unsigned long int)((-1) * y);
		r_is_negative = 1;
	}

	while (r_num > 0)
	{
		r_buffer[r--] = (r_num % 10) + '0';
		r_num /= 10;
	}

	r++;

	return (r_write_number(r_is_negative, r, r_buffer, r_flags, r_width, r_precision, r_size));
}

/************************* PRINT BINARY *************************/
/**
 * r_print_binary - Prints unsigned number
 * @r_types: Lista of arguments
 * @r_buffer: r_buffer array to handle print
 * @r_flags:  Calculates r_flags active
 * @r_width: get r_width.
 * @r_precision: specification r_precision
 * @r_size: r_size specifier
 * Return: Numbers of char printed.
 */
int r_print_binary(va_list r_types, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size)
{
	unsigned int n, y, r, r_sum;
	unsigned int a[32];
	int count;

	UNUSED(r_buffer);
	UNUSED(r_flags);
	UNUSED(r_width);
	UNUSED(r_precision);
	UNUSED(r_size);

	n = va_arg(r_types, unsigned int);
	y = 2147483648; /* (2 ^ 31) */
	a[0] = n / y;
	for (r = 1; r < 32; r++)
	{
		y /= 2;
		a[r] = (n / y) % 2;
	}
	for (r = 0, r_sum = 0, count = 0; r < 32; r++)
	{
		r_sum += a[r];
		if (r_sum || r == 31)
		{
			char z = '0' + a[r];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

