#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_all_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_character(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_all_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_all_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_all_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_all_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_all_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_all_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_all_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_all_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_all_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_all_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_all_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int get_all_flags(const char *format, int *i);
int get_all_width(const char *format, int *i, va_list list);
int get_all_precision(const char *format, int *i, va_list list);
int get_all_size(const char *format, int *i);

/*Function to print string in reverse*/
int print_all_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_all_rot13string (va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_all_printable(char);
int append_hex_code(char, char[], int);
int is_digit(char);

long int convert_size_num(long int num, int size);
long int convert_size_unsgnde(unsigned long int num, int size);

#endif /* MAIN_H */

