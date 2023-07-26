#include "main.h"

/**
 * r_is_printable - Evaluates char is printable
 * @d: Char evaluated.
 *
 * Return: 1 if d is print, 0 otherwise
 */
int r_is_printable(char d)
{
	if (d >= 32 && d < 127)
		return (1);

	return (0);
}

/**
 * r_append_hexa_code - Append ascci hexadecimal code to r_buffer
 * @r_buffer: Array of characters.
 * @r: Index which to start appending.
 * @ascii_code: CODE ASSCI.
 * Return: Always 3
 */
int r_append_hexa_code(char ascii_code, char r_buffer[], int r)
{
	char r_map_to[] = "0123456789ABCDEF";
	/* The hexa format code  always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	r_buffer[r++] = '\\';
	r_buffer[r++] = 'x';

	r_buffer[r++] = r_map_to[ascii_code / 16];
	r_buffer[r] = r_map_to[ascii_code % 16];

	return (3);
}

/**
 * r_is_digit - Verifies char is a digit
 * @d: Character to evaluated
 *
 * Return: 1 if d is a digit, 0 otherwise
 */
int r_is_digit(char d)
{
	if (d >= '0' && d <= '9')
		return (1);

	return (0);
}

/**
 * r_convert_size_number - Casts number to the r_size specified
 * @r_num: Number be casts.
 * @r_size: Number indicating type to casts.
 *
 * Return: Casted value of r_num
 */
long int r_convert_size_number(long int r_num, int r_size)
{
	if (r_size == S_LONG)
		return (r_num);
	else if (r_size == S_SHORT)
		return ((short)r_num);

	return ((int)r_num);
}

/**
 * r_convert_size_unsgnd - Casts a number to the r_size specified
 * @r_num: Number be casts
 * @r_size: Number indicating type to be casts
 *
 * Return: Casted value of r_num
 */
long int r_convert_size_unsgnd(unsigned long int r_num, int r_size)
{
	if (r_size == S_LONG)
		return (r_num);
	else if (r_size == S_SHORT)
		return ((unsigned short)r_num);

	return ((unsigned int)r_num);
}

