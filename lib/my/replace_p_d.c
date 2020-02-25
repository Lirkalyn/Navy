/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** some replace
*/

#include <stdlib.h>

void num_len_2(int num, int *len)
{
    if (num == 0)
        *len += 1;
    *len += 1;
    while (num != 0) {
        num /= 10;
        *len += 1;
    }
}

int ds_2_neg2(int lens[], int num, char *res, int i)
{
    int j;
    int bool = 0;

    if (num < 0) {
        bool = 1;
        num *= (-1);
    }
    for (j = (i + lens[0] - 1); num != 0; j--) {
        res[j] = ((num % 10) + '0');
        num /= 10;
    }
    if (bool == 1)
        res[j] = '-';
    j += lens[0];
    return j;
}

int ds_32(int lens[], int num, char *res, int i)
{
    int j;
    int bool = 0;

    if (num > 0)
        bool = 1;
    for (j = (i + lens[0] - 1); num != 0; j--) {
        res[j] = ((num % 10) + '0');
        num /= 10;
    }
    if (bool == 1)
        res[j] = '+';
    j += lens[0];
    return j;
}

int ds_42(int lens[], int num, char *res, int i)
{
    int j = (i + lens[0] - 1);

    res[j - 1] = '+';
    res[j] = '0';
    j += 1;
    return j;
}

char *replace_str_p_ds(char *str, int num, int pos)
{
    int i;
    int j;
    int lens[2] = {[0 ... 1] = 0};
    char *res;

    num_len_2(num, &lens[0]);
    for (lens[1] = 0; str[lens[1]] != '\0'; lens[1]++);
    res = (char *)malloc((lens[0] + lens[1] + 1) * sizeof(char));
    res[(lens[0] + lens[1])] = '\0';
    for (i = 0; i < pos; i++)
        res[i] = str[i];
    if (num == 0)
        j = ds_42(lens, num, res, i);
    else
        j = (num < 0) ? ds_2_neg2(lens, num, res, i) : ds_32(lens, num, res, i);
    i += 3;
    for (;str[i] != '\0'; i++)
        res[j++] = str[i];
    return res;
}