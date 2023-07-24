#include "main.h"

/**
 * rd_fill_long_oct_array - calculates long octal number
 *
 * @rd_bnr: array  is stored the binary.
 * @rd_oct: array  is stored the octal.
 *
 * Return: array binary .
 */
char *rd_fill_long_oct_array(char *rd_bnr, char *rd_oct)
{
	int rd_op, rd_i, rd_j, ioct, limit;

	rd_oct[22] = '\0';
	for (rd_i = 63, ioct = 21; rd_i >= 0; rd_i--, ioct--)
	{
		if (rd_i > 0)
			limit = 4;
		else
			limit = 1;
		for (rd_op = 0, rd_j = 1; rd_j <= limit; rd_j *= 2, rd_i--)
			rd_op = ((rd_bnr[rd_i] - '0') * rd_j) + rd_op;
		rd_i++;
		rd_oct[ioct] = rd_op + '0';
	}
	return (rd_oct);
}

