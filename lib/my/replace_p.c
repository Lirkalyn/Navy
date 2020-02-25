/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** some replace
*/

#include <stdlib.h>

char *hexa_conv(void *src)
{
    char *res;
    long long test = (long long)src;
    int pos = 13;

    res = (char *)malloc(15 * sizeof(char));
    res[0] = '0';
    res[1] = 'x';
    res[14] = '\0';
    while (pos > 1) {
        if ((test % 16) >= 0 && (test % 16) <= 9)
            res[pos] = ((test % 16) + '0');
        else
            res[pos] = ((test % 16) + 87);
        test /= 16;
        pos--;
    }
    return res;
}

char *replace_str_p(char *str, void *src, int pos)
{
    int i;
    int j;
    int lens[2] = {[0 ... 1] = 0};
    char *hex;
    char *res;

    hex = hexa_conv(src);
    for (lens[0] = 0; str[lens[0]] != '\0'; lens[0]++);
    lens[1] = 14;
    res = (char *)malloc((lens[0] + lens[1] + 1) * sizeof(char));
    res[(lens[0] + lens[1])] = '\0';
    for (i = 0; i < pos; i++)
        res[i] = str[i];
    for (j = 0; hex[j] != '\0'; j++)
        res[i++] = hex[j];
    j = (i - lens[1] + 2);
    for (; str[j] != '\0'; j++)
        res[i++] = str[j];
    return res;
}