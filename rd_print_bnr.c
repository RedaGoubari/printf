#include "main.h"

/**
 * rd_print_bnr - prints decimal in binary
 * @rd_arguments: string input
 * @rd_buf: pointer buffer
 * @rd_ibuf: index for pointer buffer
 * Return: number of printed chars .
 */
int rd_print_bnr(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf)
{
	int rd_int_input, rd_count, rd_i, rd_first_one, rd_isnegative;
	char *binary;

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
	rd_first_one = 0;
	for (rd_count = rd_i = 0; binary[rd_i]; rd_i++)
	{
		if (rd_first_one == 0 && binary[rd_i] == '1')
			rd_first_one = 1;
		if (rd_first_one == 1)
		{
			rd_ibuf = rd_handl_buf(rd_buf, binary[rd_i], rd_ibuf);
			rd_count++;
		}
	}
	free(binary);
	return (rd_count);
}

