#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024


/* r_flags */
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
 * @fmt: format.
 * @fm_t: associated function.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int r_handle_print(const char *fmt, int *r,
va_list r_list, char r_buffer[], int r_flags, int r_width, int r_precision, int r_size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int r_print_char(va_list r_types, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size);
int r_print_string(va_list r_types, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size);
int r_print_percent(va_list r_types, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size);

/* Functions to print numbers */
int r_print_int(va_list r_types, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size);
int r_print_binary(va_list r_types, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size);
int r_print_unsigned(va_list r_types, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size);
int r_print_octal(va_list r_types, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size);
int r_print_hexadecimal(va_list r_types, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size);
int r_print_hexa_upper(va_list r_types, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size);

int r_print_hexa(va_list r_types, char map_to[],
char r_buffer[], int r_flags, char flag_ch, int r_width, int r_precision, int r_size);

/* Function to print non printable characters */
int r_print_non_printable(va_list r_types, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size);

/* Funcion to print memory address */
int r_print_pointer(va_list r_types, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size);

/* Funciotns to handle other specifiers */
int r_get_flags(const char *format, int *r);
int r_get_width(const char *format, int *r, va_list r_list);
int r_get_precision(const char *format, int *r, va_list r_list);
int r_get_size(const char *format, int *r);

/*Function to print string in reverse*/
int r_print_reverse(va_list r_types, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size);

/*Function to print a string in rot 13*/
int r_print_rot13string(va_list r_types, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size);

/* r_width handler */
int r_handle_write_char(char d, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size);
int r_write_number(int is_positive, int r_ind, char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size);
int r_write_num(int r_ind, char bff[], int r_flags, int r_width, int r_precision,
	int length, char padd, char extra_c);
int r_write_pointer(char r_buffer[], int r_ind, int length,
	int r_width, int r_flags, char padd, char extra_c, int padd_start);

int r_write_unsgnd(int is_negative, int r_ind,
char r_buffer[],
	int r_flags, int r_width, int r_precision, int r_size);

/****************** UTILS ******************/
int r_is_printable(char);
int r_append_hexa_code(char, char[], int);
int r_is_digit(char);

long int r_convert_size_number(long int r_num, int r_size);
long int r_convert_size_unsgnd(unsigned long int r_num, int r_size);

#endif /* MAIN_H */
