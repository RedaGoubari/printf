#include "main.h"

/**
 * rd_fill_hex_array - writes  character c to stdout
 *
 * @bnr: array where is stored the binary.
 * @hex: array where is stored the hexadecimal.
 * @rd_isupp: integer that determines if the hexadecimal array
 * in uppercase or lowercase letter.
 * @rd_limit:  hexsize
 * Return: array binary .
 */
char *rd_fill_hex_array(char *bnr, char *hex, int rd_isupp, int rd_limit)
{
	int rd_op, rd_i, rd_j, toletter;

	hex[rd_limit] = '\0';
	if (rd_isupp)
		toletter = 55;
	else
		toletter = 87;
	for (rd_i = (rd_limit * 4) - 1; rd_i >= 0; rd_i--)
	{
		for (rd_op = 0, rd_j = 1; rd_j <= 8; rd_j *= 2, rd_i--)
			rd_op = ((bnr[rd_i] - '0') * rd_j) + rd_op;
		rd_i++;
		if (rd_op < 10)
			hex[rd_i / 4] = rd_op + 48;
		else
			hex[rd_i / 4] = rd_op + toletter;
	}
	return (hex);
}

