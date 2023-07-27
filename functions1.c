#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_all_unsigned - Prints unsigned number
 * @types: List a of arg
 * @buffer: Buffer array to be handle print
 * @flags:  Calculates a active flags
 * @width: get a  width
 * @precision: Precision specifications
 * @size: Size specifiers
 * Return: Number of characters printed.
 */
int print_all_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnde(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_all_octal - Prints unsigned number in octal notation
 * @types: Lista of arg
 * @buffer: Buffer array to be handle print
 * @flags:  Calculate active flag
 * @width: width
 * @precision: Precision specifications
 * @size: Size specifiers
 * Return: Number of characters printed
 */
int print_all_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnde(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_all_hexadecimal - Prints unsigned number in hexadecimal notation
 * @types: List of arg
 * @buffer: Buffer array to be handle print
 * @flags:  Calculates activ flags
 * @width:  width
 * @precision: Precision specificatio
 * @size: Size specifie
 * Return: Number of characters printed
 */
int print_all_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_all_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_all_hexa_upper - Prints an unsigned num in upper hexadecimal notation
 * @types: List of arg
 * @buffer: Buffer array to be  handle print
 * @flags:  Calculates flags active
 * @width: width
 * @precision: Precision specific
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_all_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_all_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_all_hexa - Prints a hexadecimal num in lower or upper
 * @types: List of arg
 * @map_to: Array of values to map the num
 * @buffer: Buffer array to be handle print
 * @flags:  Calculates flagsactive
 * @flag_ch: Calculates flags active
 * @width: width
 * @precision: Precision specific
 * @size: Size specifier
 * @size: Size specific
 * Return: Number of charscter printed
 */
int print_all_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnde(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}


