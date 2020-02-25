/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** some replace
*/

#include <stdlib.h>

char *bina_conv(unsigned int src)
{
    int i;
    char *res;
    int pos = 31;

    res = (char *)malloc(33 * sizeof(char));
    res[32] = '\0';
    for (i = 0; i < 32; i++)
        res[i] = '0';
    while (src != 0) {
        res[pos] = ((src % 2) + '0');
        src /= 2;
        pos--;
    }
    return res;
}

int count_bin(char *bin)
{
    int len = 32;
    int i;

    for (i = 0; bin[i] != '\0'; i++) {
        if (bin[i] == '0')
            len--;
        else
            return len;
        if (len == 0)
            return 1;
    }
}

char *replace_str_b(char *str, unsigned int src, int pos)
{
    int i;
    int j;
    int lens[2] = {[0 ... 1] = 0};
    char *bin;
    char *res;

    bin = bina_conv(src);
    lens[1] = count_bin(bin);
    for (lens[0] = 0; str[lens[0]] != '\0'; lens[0]++);
    res = (char *)malloc((lens[0] + lens[1] + 1) * sizeof(char));
    res[(lens[0] + lens[1])] = '\0';
    for (i = 0; i < pos; i++)
        res[i] = str[i];
    for (j = (32 - lens[1]); bin[j] != '\0'; j++)
        res[i++] = bin[j];
    j = (i - lens[1] + 2);
    for (; str[j] != '\0'; j++)
        res[i++] = str[j];
    return res;
}