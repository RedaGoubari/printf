#include "main.h"
/**
 * rd_prinlunt - prints a long unsigned integer
 * @rd_arguments: number to print
 * @rd_buf:  pointer buffer
 * @rd_ibuf: index for  pointer buffer
 * Return: number of chars printed.
 */
int rd_prinlunt(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf)
{
	unsigned long int rd_int_in, rd_int_temp, rd_i, rd_div;

	rd_int_in = va_arg(rd_arguments, unsigned long int);
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
	return (rd_i);
}

