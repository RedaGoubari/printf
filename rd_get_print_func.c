#include "main.h"
/**
 * rd_get_print_func - selects correct function to perform the operation.
 * @rd_s: argument of indentifier
 * @rd_index: rd_index argument indentifier
 * Return: pointer to  function.
 */
int (*rd_get_print_func(const char *rd_s, int rd_index))(va_list, char *, unsigned int)
{
	print_t pr[] = {
		{"c", rd_print_chr}, {"rd_s", rd_print_str},
		{"rd_i", rd_print_int}, {"d", rd_print_int},
		{"b", rd_print_bnr}, {"u", rd_print_unt},
		{"o", rd_print_oct}, {"x", rd_print_hex},
		{"X", rd_print_upx}, {"rd_s", rd_print_usr},
		{"p", rd_print_add}, {"li", rd_prinlint},
		{"ld", rd_prinlint}, {"lu", rd_prinlunt},
		{"lo", rd_iprinloct}, {"lx", rd_prinlhex},
		{"lX", rd_prinlupx}, {"hi", rd_prinhint},
		{"hd", rd_prinhint}, {"hu", rd_prinhunt},
		{"ho", rd_prinhoct}, {"hx", rd_prinhhex},
		{"hX", rd_prinhupx}, {"#o", rd_prinnoct},
		{"#x", rd_prinnhex}, {"#X", rd_prinnupx},
		{"#rd_i", rd_print_int}, {"#d", rd_print_int},
		{"#u", rd_print_unt}, {"+rd_i", rd_prinpint},
		{"+d", rd_prinpint}, {"+u", rd_print_unt},
		{"+o", rd_print_oct}, {"+x", rd_print_hex},
		{"+X", rd_print_upx}, {" rd_i", rd_prinsint},
		{" d", rd_prinsint}, {" u", rd_print_unt},
		{" o", rd_print_oct}, {" x", rd_print_hex},
		{" X", rd_print_upx}, {"R", rd_print_rot},
		{"r", rd_print_rev}, {"%", rd_print_prg},
		{"l", rd_print_prg}, {"h", rd_print_prg},
		{" +rd_i", rd_prinpint}, {" +d", rd_prinpint},
		{"+ rd_i", rd_prinpint}, {"+ d", rd_prinpint},
		{" %", rd_print_prg}, {NULL, NULL},
	};
	int rd_i = 0, rd_j = 0, rd_first_index;

	rd_first_index = rd_index;
	while (pr[rd_i].type_arg)
	{
		if (rd_s[rd_index] == pr[rd_i].type_arg[rd_j])
		{
			if (pr[rd_i].type_arg[rd_j + 1] != '\0')
				rd_index++, rd_j++;
			else
				break;
		}
		else
		{
			rd_j = 0;
			rd_i++;
			rd_index = rd_first_index;
		}
	}
	return (pr[rd_i].f);
}

