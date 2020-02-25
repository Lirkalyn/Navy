/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** some replace
*/

#include <stdlib.h>

char *octa_conv(unsigned int src)
{
    int i;
    char *res;
    int pos = 11;

    res = (char *)malloc(13 * sizeof(char));
    res[12] = '\0';
    for (i = 0; i < 12; i++)
        res[i] = '0';
    while (src != 0) {
        res[pos] = ((src % 8) + '0');
        src /= 8;
        pos--;
    }
    return res;
}

int count_oct(char *oct)
{
    int len = 12;
    int i;

    for (i = 0; oct[i] != '\0'; i++) {
        if (oct[i] == '0')
            len--;
        else
            return len;
        if (len == 0)
            return 1;
    }
}

char *replace_str_o(char *str, unsigned int src, int pos)
{
    int i;
    int j;
    int lens[2] = {[0 ... 1] = 0};
    char *oct;
    char *res;

    oct = octa_conv(src);
    lens[1] = count_oct(oct);
    for (lens[0] = 0; str[lens[0]] != '\0'; lens[0]++);
    res = (char *)malloc((lens[0] + lens[1] + 1) * sizeof(char));
    res[(lens[0] + lens[1])] = '\0';
    for (i = 0; i < pos; i++)
        res[i] = str[i];
    for (j = (12 - lens[1]); oct[j] != '\0'; j++)
        res[i++] = oct[j];
    j = (i - lens[1] + 2);
    for (; str[j] != '\0'; j++)
        res[i++] = str[j];
    return res;
}

char *replace_str_h_o_0(char *str, unsigned int src, int pos)
{
    int i;
    int j;
    int lens[2] = {[0 ... 1] = 0};
    char *oct;
    char *res;

    oct = octa_conv(src);
    lens[1] = count_oct(oct);
    for (lens[0] = 0; str[lens[0]] != '\0'; lens[0]++);
    res = (char *)malloc((lens[0] + lens[1] + 1) * sizeof(char));
    res[(lens[0] + lens[1])] = '\0';
    for (i = 0; i < pos; i++)
        res[i] = str[i];
    for (j = (12 - lens[1]); oct[j] != '\0'; j++)
        res[i++] = oct[j];
    j = (i - lens[1] + 3);
    for (; str[j] != '\0'; j++)
        res[i++] = str[j];
    return res;
}