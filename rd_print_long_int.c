#include "main.h"
/**
 * rd_prinlint - prints a long integer
 * @rd_arguments: string input
 * @rd_buf:  pointer buffer
 * @rd_ibuf: index for  pointer buffer
 * Return: number of chars printed.
 */
int rd_prinlint(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf)
{
	long int rd_int_input;
	unsigned long int rd_int_in, rd_int_temp, rd_i, rd_div, rd_isneg;

	rd_int_input = va_arg(rd_arguments, long int);
	rd_isneg = 0;
	if (rd_int_input < 0)
	{
		rd_int_in = rd_int_input * -1;
		rd_ibuf = rd_handl_buf(rd_buf, '-', rd_ibuf);
		rd_isneg = 1;
	}
	else
	{
		rd_int_in = rd_int_input;
	}

	rd_int_temp = rd_int_in;
	rd_div = 1;
	while (rd_int_temp > 9)
	{
		rd_div *= 10;
		rd_int_temp /= 10;
	}
	for (rd_i = 0; rd_div > 0; rd_div /= 10, rd_i++)
	{
		rd_ibuf = rd_handl_buf(rd_buf, ((rd_int_in / rd_div) % 10) + '0', rd_ibuf);
	}
	return (rd_i + rd_isneg);
}

