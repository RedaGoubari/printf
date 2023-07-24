#include "main.h"

/**
 * rd_fill_oct_array - writes character c to stdout
 *
 * @rd_bnr: array  is stored the binary.
 * @rd_oct: array  is stored the octal.
 *
 * Return: array binary .
 */
char *rd_fill_oct_array(char *rd_bnr, char *rd_oct)
{
	int rd_op, rd_i, rd_j, rd_ioct, rd_limit;

	rd_oct[11] = '\0';
	for (rd_i = 31, rd_ioct = 10; rd_i >= 0; rd_i--, rd_ioct--)
	{
		if (rd_i > 1)
			rd_limit = 4;
		else
			rd_limit = 2;
		for (rd_op = 0, rd_j = 1; rd_j <= rd_limit; rd_j *= 2, rd_i--)
			rd_op = ((rd_bnr[rd_i] - '0') * rd_j) + rd_op;
		rd_i++;
		rd_oct[rd_ioct] = rd_op + '0';
	}
	return (rd_oct);
}

