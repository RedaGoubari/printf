#include "main.h"

/**
 * rd_handl_buf - concatenates buffer characters
 * @rd_buf: pointer buffer
 * @rd_c: charcter concatenate
 * @rd_ibuf: index of pointer buffer
 * Return: index of pointer buffer .
 */
unsigned int rd_handl_buf(char *rd_buf, char rd_c, unsigned int rd_ibuf)
{
	if (rd_ibuf == 1024)
	{
		rd_print_buf(rd_buf, rd_ibuf);
		rd_ibuf = 0;
	}
	rd_buf[rd_ibuf] = rd_c;
	rd_ibuf++;
	return (rd_ibuf);
}
