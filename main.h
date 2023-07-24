#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct print - struct for printer functions
 * @type_arg: identifier
 * @f: pointer to printer functions
 *
 * Description: struct that stores pointers to
 * printer functions.
 */
typedef struct print
{
	char *type_arg;
	int (*f)(va_list, char *, unsigned int);
} print_t;

int rd_printf(const char *rd_format, ...);
int rd_print_prg(va_list __attribute__((unused)), char *, unsigned int);
int rd_print_chr(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf);
int rd_print_str(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf);
int rd_print_int(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf);
int rd_print_bnr(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf);
int rd_print_unt(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf);
int rd_print_oct(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf);
int rd_print_hex(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf);
int rd_print_upx(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf);
int rd_print_usr(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf);
int rd_print_add(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf);
int rd_print_rev(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf);
int rd_print_rot(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf);
int rd_prinlint(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf);
int rd_prinlunt(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf);
int rd_iprinloct(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf);
int rd_prinlhex(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf);
int rd_prinlupx(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf);
int rd_prinhint(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf);
int rd_prinhunt(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf);
int rd_prinhoct(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf);
int rd_prinhhex(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf);
int rd_prinhupx(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf);
int rd_prinpint(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf);
int rd_prinnoct(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf);
int rd_prinnhex(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf);
int rd_prinnupx(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf);
int rd_prinsint(va_list rd_arguments, char *rd_buf, unsigned int rd_ibuf);
int (*rd_get_print_func(const char *rd_s, int rd_index))(va_list, char *, unsigned int);
int rd_ev_print_func(const char *rd_s, int rd_index);
unsigned int rd_handl_buf(char *rd_buf, char rd_c, unsigned int rd_ibuf);
int rd_print_buf(char *rd_buf, unsigned int rd_nbuf);
char *rd_fill_binary_array(char *binary, long int rd_int_in, int rd_isneg, int rd_limit);
char *rd_fill_oct_array(char *rd_bnr, char *rd_oct);
char *rd_fill_long_oct_array(char *rd_bnr, char *rd_oct);
char *rd_fill_short_oct_array(char *rd_bnr, char *rd_oct);
char *rd_fill_hex_array(char *bnr, char *hex, int rd_isupp, int rd_limit);

#endif

