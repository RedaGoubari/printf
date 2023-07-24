#include "main.h"
/**
 * rd_iprinloct - prints long decimal number in octal
 * @rd_arguments: input number
 * @rd_buf:  pointer buffer
 * @rd_ibuf: index for  pointer buffer
 * Return: number of chars printed.
 */
int rd_iprinloct(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf)
{
	long int rd_int_input, rd_i, rd_isnegative, rd_count, rd_first_digit;
	char *octal, *binary;

	rd_int_input = va_arg(rd_arguments, long int);
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

	binary = malloc(sizeof(char) * (64 + 1));
	binary = rd_fill_binary_array(binary, rd_int_input, rd_isnegative, 64);
	octal = malloc(sizeof(char) * (22 + 1));
	octal = rd_fill_long_oct_array(binary, octal);
	for (rd_first_digit = rd_i = rd_count = 0; octal[rd_i]; rd_i++)
	{
		if (octal[rd_i] != '0' && rd_first_digit == 0)
			rd_first_digit = 1;
		if (rd_first_digit)
		{
			rd_ibuf = rd_handl_buf(rd_buf, octal[rd_i], rd_ibuf);
			rd_count++;
		}
	}
	free(binary);
	free(octal);
	return (rd_count);
}

