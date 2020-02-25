/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** some replace
*/

#include <stdarg.h>
#include <stdlib.h>
#include "printf.h"

char *hexa_conv5(int src)
{
    char *res;
    int pos = 9;

    res = (char *)malloc(11 * sizeof(char));
    for (int i = 0; i < 10; i++)
        res[i] = '0';
    res[10] = '\0';
    while (src != 0) {
        if ((src % 16) >= 0 && (src % 16) <= 9)
            res[pos] = ((src % 16) + '0');
        else
            res[pos] = ((src % 16) + 55);
        src /= 16;
        pos--;
    }
    res[pos] = 'X';
    res[pos - 1] = '0';
    return res;
}

int count_hex_3(char *hex)
{
    int len = 10;
    int i;

    for (i = 0; hex[i] != '\0'; i++) {
        if (hex[i] == '0')
            len--;
        else
            return (len + 1);
        if (len == 0)
            return 1;
    }
}

char *replace_str_h_xx_2(char *str, int src, int pos)
{
    int i;
    int j;
    int lens[2] = {[0 ... 1] = 0};
    char *hex;
    char *res;

    hex = hexa_conv5(src);
    for (lens[0] = 0; str[lens[0]] != '\0'; lens[0]++);
    lens[1] = count_hex_3(hex);
    res = (char *)malloc((lens[0] + lens[1] + 1) * sizeof(char));
    res[(lens[0] + lens[1])] = '\0';
    for (i = 0; i < pos; i++)
        res[i] = str[i];
    for (j = (10 - lens[1]); hex[j] != '\0'; j++)
        res[i++] = hex[j];
    j = (i - lens[1] + 3);
    for (; str[j] != '\0'; j++)
        res[i++] = str[j];
    return res;
}

char *replace_str_h_xx(char *str, int src, int pos)
{
    if (src == 0)
        return replace_str_h_o_0(str, src, pos);
    else
        return replace_str_h_xx_2(str, src, pos);
}