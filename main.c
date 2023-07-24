#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
int len;
int len2;
unsigned int ui;
void *addr;

len = rd_printf("Let's try to printf a simple sentence.\n");
len2 = rd_printf("Let's try to printf a simple sentence.\n");
ui = (unsigned int)INT_MAX + 1024;
addr = (void *)0x7ffe637541f0;
rd_printf("Length:[%d, %i]\n", len, len);
printf("Length:[%d, %i]\n", len2, len2);
rd_printf("Negative:[%d]\n", -762534);
printf("Negative:[%d]\n", -762534);
rd_printf("Unsigned:[%u]\n", ui);
printf("Unsigned:[%u]\n", ui);
rd_printf("Unsigned octal:[%o]\n", ui);
printf("Unsigned octal:[%o]\n", ui);
rd_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
rd_printf("Character:[%c]\n", 'H');
printf("Character:[%c]\n", 'H');
rd_printf("String:[%s]\n", "I am a string !");
printf("String:[%s]\n", "I am a string !");
rd_printf("Address:[%p]\n", addr);
printf("Address:[%p]\n", addr);
len = rd_printf("Percent:[%%]\n");
len2 = printf("Percent:[%%]\n");
rd_printf("Len:[%d]\n", len);
printf("Len:[%d]\n", len2);
rd_printf("Unknown:[%r]\n");
printf("Unknown:[%r]\n");
return (0);
}
