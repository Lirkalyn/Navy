/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** switchs
*/

#include <stdarg.h>
#include <stdint.h>
#include "printf.h"

char *replace_str(char *str, va_list param, int pos, int i)
{
    switch (pos)
    {
        case 0:
            return replace_str_ds(str, va_arg(param, int), i);
        case 1:
            return replace_str_c(str, va_arg(param, int), i);
        case 2:
            return replace_str_s(str, va_arg(param, char *), i, 0);
        case 3:
            return replace_str_ss(str, va_arg(param, char *), i);
        case 4:
            return replace_str_p(str, va_arg(param, void *), i);
        case 5:
            return replace_str_b(str, va_arg(param, uint32_t), i);
        case 6:
            return replace_str_o(str, va_arg(param, uint32_t), i);
        default:
        break;
    }
}

char *replace_str2(char *str, va_list param, int pos, int i)
{
    switch (pos)
    {
        case 7:
            return replace_str_pour(str, i, 0);
        case 8:
            return replace_str_u(str, va_arg(param, uint32_t), i);
        case 9:
            return replace_str_x(str, va_arg(param, int), i);
        case 10:
            return replace_str_xx(str, va_arg(param, int), i);
        case 11:
            return replace_str_ds(str, va_arg(param, int), i);
        case 12:
            return replace_str_ds(str, va_arg(param, int), i);
        case 13:
            return replace_str_n(str, va_arg(param, int *), i);
        default:
        break;
    }
}

char *replace_str3(char *str, va_list param, int pos, int i)
{
    switch (pos)
    {
        case 14:
            return replace_str_p_ds(str, va_arg(param, int), i);
        case 15:
            return replace_str_h_o(str, va_arg(param, uint32_t), i);
        case 16:
            return replace_str_h_x(str, va_arg(param, int), i);
        case 17:
            return replace_str_h_xx(str, va_arg(param, int), i);
        default:
        break;
    }
}

char *wich_switch(char *str, va_list param, int pos, int i)
{
    if (pos >= 0 && pos <= 6)
        return replace_str(str, param, pos, i);
    if (pos >= 7 && pos <= 13)
        return replace_str2(str, param, pos, i);
    if (pos >= 14 && pos <= 17)
        return replace_str3(str, param, pos, i);
}