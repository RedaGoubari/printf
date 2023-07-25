#include "main.h"

/**
 * r_get_flags - Calculates r_flags active
 * @format: Formatted string in which to print arg
 * @r: take parameter.
 * Return: r_flags:
 */
int r_get_flags(const char *format, int *r)
{
        /* - + 0 # ' ' */
        /* 1 2 4 8  16 */
        int e, r_curr_i;
        int r_flags = 0;
        const char r_FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
        const int r_FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

        for (r_curr_i = *r + 1; format[r_curr_i] != '\0'; r_curr_i++)
        {
                for (e = 0; r_FLAGS_CH[e] != '\0'; e++)
                        if (format[r_curr_i] == r_FLAGS_CH[e])
                        {
                                r_flags |= r_FLAGS_ARR[e];
                                break;
                        }

                if (r_FLAGS_CH[e] == 0)
                        break;
        }

        *r = r_curr_i - 1;

        return (r_flags);
}
