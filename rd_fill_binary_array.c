#include "main.h"

/**
 * rd_fill_binary_array - prints decimal to binary
 * @binary: pointer to binary
 * @rd_int_in: number input
 * @rd_isneg: if input number negative
 * @rd_limit: size  the binary
 * Return: number chars printed.
 */
char *rd_fill_binary_array(char *binary, long int rd_int_in,
		int rd_isneg, int rd_limit)
{
	int rd_i;

	for (rd_i = 0; rd_i < rd_limit; rd_i++)
		binary[rd_i] = '0';
	binary[rd_limit] = '\0';
	for (rd_i = rd_limit - 1; rd_int_in > 1; rd_i--)
	{
		if (rd_int_in == 2)
			binary[rd_i] = '0';
		else
			binary[rd_i] = (rd_int_in % 2) + '0';
		rd_int_in /= 2;
	}
	if (rd_int_in != 0)
		binary[rd_i] = '1';
	if (rd_isneg)
	{
		for (rd_i = 0; binary[rd_i]; rd_i++)
			if (binary[rd_i] == '0')
				binary[rd_i] = '1';
			else
				binary[rd_i] = '0';
	}
	return (binary);
}

