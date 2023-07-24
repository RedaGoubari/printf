#include "main.h"
#include <stdio.h>
/**
 * rd_print_chr - writes the character c to stdout
 * @rd_arguments: char input
 * @rd_buf: pointer buffer
 * @rd_ibuf: index for pointer buffer
 * Return: On success 1.
 */
int rd_print_chr(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf)
{
	char c;

	c = va_arg(rd_arguments, int);
	rd_handl_buf(rd_buf, c, rd_ibuf);

	return (1);
}

