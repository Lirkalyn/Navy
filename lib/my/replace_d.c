/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** some replace
*/

#include <stdlib.h>

void num_len(int num, int *len)
{
    if (num <= 0)
        *len += 1;
    while (num != 0) {
        num /= 10;
        *len += 1;
    }
}

int ds_2_neg(int lens[], int num, char *res, int i)
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

int ds_3(int lens[], int num, char *res, int i)
{
    int j;

    for (j = (i + lens[0] - 1); num != 0; j--) {
        res[j] = ((num % 10) + '0');
        num /= 10;
    }
    j += lens[0] + 1;
    return j;
}

int ds_4(int lens[], int num, char *res, int i)
{
    int j = (i + lens[0] - 1);

    res[j--] = '0';
    j += lens[0] + 1;
    return j;
}

char *replace_str_ds(char *str, int num, int pos)
{
    int i;
    int j;
    int lens[2] = {[0 ... 1] = 0};
    char *res;

    num_len(num, &lens[0]);
    for (lens[1] = 0; str[lens[1]] != '\0'; lens[1]++);
    res = (char *)malloc((lens[0] + lens[1] + 1) * sizeof(char));
    res[(lens[0] + lens[1])] = '\0';
    for (i = 0; i < pos; i++)
        res[i] = str[i];
    if (num == 0)
        j = ds_4(lens, num, res, i);
    else
        j = (num < 0) ? ds_2_neg(lens, num, res, i) : ds_3(lens, num, res, i);
    i += 2;
    for (;str[i] != '\0'; i++)
        res[j++] = str[i];
    return res;
}