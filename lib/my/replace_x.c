/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** some replace
*/

#include <stdlib.h>

char *hexa_conv2(int src)
{
    char *res;
    int pos = 7;

    res = (char *)malloc(9 * sizeof(char));
    res[8] = '\0';
    while (pos >= 0) {
        if ((src % 16) >= 0 && (src % 16) <= 9)
            res[pos] = ((src % 16) + '0');
        else
            res[pos] = ((src % 16) + 87);
        src /= 16;
        pos--;
    }
    return res;
}

int count_hex(char *hex)
{
    int len = 8;
    int i;

    for (i = 0; hex[i] != '\0'; i++) {
        if (hex[i] == '0')
            len--;
        else
            return len;
        if (len == 0)
            return 1;
    }
}

char *replace_str_x(char *str, int src, int pos)
{
    int i;
    int j;
    int lens[2] = {[0 ... 1] = 0};
    char *hex;
    char *res;

    hex = hexa_conv2(src);
    for (lens[0] = 0; str[lens[0]] != '\0'; lens[0]++);
    lens[1] = count_hex(hex);
    res = (char *)malloc((lens[0] + lens[1] + 1) * sizeof(char));
    res[(lens[0] + lens[1])] = '\0';
    for (i = 0; i < pos; i++)
        res[i] = str[i];
    for (j = (8 - lens[1]); hex[j] != '\0'; j++)
        res[i++] = hex[j];
    j = (i - lens[1] + 2);
    for (; str[j] != '\0'; j++)
        res[i++] = str[j];
    return res;
}