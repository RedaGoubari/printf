#include "main.h"
#include <stdio.h>
/**
 * rd_print_add - prints  address of an input variable
 * @arguments: address input .
 * @rd_buf: pointer buffer =.
 * @rd_ibuf: index for pointer buffer
 * Return: number of printed chars .
 */
int rd_print_add(va_list arguments, char *rd_buf, unsigned int rd_ibuf)
{
	void *rd_add;
	long int rd_int_input;
	int rd_i, rd_count, rd_first_digit, rd_isnegative;
	char *hexadecimal, *binary;
	char rd_nill[] = "(nil)";

	rd_add = (va_arg(arguments, void *));
	if (rd_add == NULL)
	{
		for (rd_i = 0; rd_nill[rd_i]; rd_i++)
			rd_ibuf = rd_handl_buf(rd_buf, rd_nill[rd_i], rd_ibuf);
		return (5);
	}
	rd_int_input = (intptr_t)rd_add;
	rd_isnegative = 0;
	if (rd_int_input < 0)
	{
		rd_int_input = (rd_int_input * -1) - 1;
		rd_isnegative = 1;
	}
	binary = malloc(sizeof(char) * (64 + 1));
	binary = rd_fill_binary_array(binary, rd_int_input, rd_isnegative, 64);
	hexadecimal = malloc(sizeof(char) * (16 + 1));
	hexadecimal = rd_fill_hex_array(binary, hexadecimal, 0, 16);
	rd_ibuf = rd_handl_buf(rd_buf, '0', rd_ibuf);
	rd_ibuf = rd_handl_buf(rd_buf, 'x', rd_ibuf);
	for (rd_first_digit = rd_i = rd_count = 0; hexadecimal[rd_i]; rd_i++)
	{
		if (hexadecimal[rd_i] != '0' && rd_first_digit == 0)
			rd_first_digit = 1;
		if (rd_first_digit)
		{
			rd_ibuf = rd_handl_buf(rd_buf, hexadecimal[rd_i], rd_ibuf);
			rd_count++;
		}
	}
	free(binary);
	free(hexadecimal);
	return (rd_count + 2);
}

