#include "main.h"
/**
 * rd_print_hex - prints a decimal to in hexadecimal
 * @rd_arguments: string input
 * @rd_buf: pointer buffer
 * @rd_ibuf: index for pointer buffer
 * Return: number of printed chars
 */
int rd_print_hex(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf)
{
	int rd_int_input, rd_i, rd_isnegative, rd_count, rd_first_digit;
	char *hexadecimal, *binary;

	rd_int_input = va_arg(rd_arguments, int);
	rd_isnegative = 0;
	if (rd_int_input == 0)
	{
		rd_ibuf = rd_handl_buf(rd_buf, '0', rd_ibuf);
		return (1);
	}
	if (rd_int_input < 0)
	{
		rd_int_input = (rd_int_input * -1) - 1;
		rd_isnegative = 1;
	}
	binary = malloc(sizeof(char) * (32 + 1));
	binary = rd_fill_binary_array(binary, rd_int_input, rd_isnegative, 32);
	hexadecimal = malloc(sizeof(char) * (8 + 1));
	hexadecimal = rd_fill_hex_array(binary, hexadecimal, 0, 8);
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
	return (rd_count);
}

