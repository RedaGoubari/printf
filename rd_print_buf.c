#include "main.h"

/**
 * rd_print_buf - buffer prints
 * @rd_buf: pointer buffer
 * @rd_nbuf: number bytes to print
 * Return: number bytes printed.
 */
int rd_print_buf(char *rd_buf, unsigned int rd_nbuf)
{
	return (write(1, rd_buf, rd_nbuf));
}

