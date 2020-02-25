/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** main
*/

#include <stdarg.h>
#include <stdint.h>
#include "printf.h"

char *special_cases(char *str, va_list param, int pos, int i)
{
    if (pos == 14 && (str[i + 2] == 'd' || str[i + 2] == 'i'))
        return wich_switch(str, param, pos, i);
    else if (pos == 15) {
        if (str[i + 2] == 'o')
            return wich_switch(str, param, pos, i);
        if (str[i + 2] == 'x')
            return wich_switch(str, param, (pos + 1), i);
        if (str[i + 2] == 'X')
            return wich_switch(str, param, (pos + 2), i);
    }
    return str;
}

char *pre_replace_str(char *str, va_list param, int *i, int *j)
{
    char test[17][2] = {"%d", "%c", "%s", "%S", "%p", "%b", "%o", "%%", "%u",
        "%x", "%X", "%l", "%i", "%n", "%+", "%#", 0};
    int ok = 0;
    int pos = 0;

    for (*i = 0; str[*i] != '\0'; *i += 1) {
        for (*j = 0; *j < 2; *j += 1) {
            if (str[(*i + *j)] == test[pos][*j])
                ok++;
            else if (pos++ < 16)
                *j = 0;
        }
        if (ok == 2 && pos <= 13)
            str = wich_switch(str, param, pos, *i);
        else if (ok == 2 && pos > 13)
            str = special_cases(str, param, pos, *i);
        ok = 0;
        pos = 0;
    }
    return str;
}

void my_printf(char *str, ...)
{
    char *res;
    int i;
    int j;
    int num = 0;
    va_list param;

    va_start (param, str);
    str = pre_replace_str(str, param, &i, &j);
    my_putstr(str);
}