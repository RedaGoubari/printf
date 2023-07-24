#include "main.h"

/**
 * rd_fill_short_oct_array - calculates short octal number
 *
 * @rd_bnr: array where is stored the binary.
 * @rd_oct: array where is stored the octal.
 *
 * Return: binary array.
 */
char *rd_fill_short_oct_array(char *rd_bnr, char *rd_oct)
{
	int rd_op, rd_i, rd_j, rd_ioct, rd_limit;

	rd_oct[6] = '\0';
	for (rd_i = 15, rd_ioct = 5; rd_i >= 0; rd_i--, rd_ioct--)
	{
		if (rd_i > 0)
			rd_limit = 4;
		else
			rd_limit = 1;
		for (rd_op = 0, rd_j = 1; rd_j <= rd_limit; rd_j *= 2, rd_i--)
			rd_op = ((rd_bnr[rd_i] - '0') * rd_j) + rd_op;
		rd_i++;
		rd_oct[rd_ioct] = rd_op + '0';
	}
	return (rd_oct);
}

