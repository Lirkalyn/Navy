/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** some replace
*/

#include <stdlib.h>

void num_len2(unsigned int num, int *len)
{
    while (num != 0) {
        num /= 10;
        *len += 1;
    }
}

int replace_str_ds_3(int lens[], unsigned int num, char *res, int i)
{
    int j;

    for (j = (i + lens[0] - 1); num != 0; j--) {
        res[j] = ((num % 10) + '0');
        num /= 10;
    }
    j += lens[0] + 1;
    return j;
}

char *replace_str_u(char *str, unsigned int num, int pos)
{
    int i;
    int j;
    int lens[2] = {[0 ... 1] = 0};
    char *res;

    num_len2(num, &lens[0]);
    for (lens[1] = 0; str[lens[1]] != '\0'; lens[1]++);
    res = (char *)malloc((lens[0] + lens[1] + 1) * sizeof(char));
    res[(lens[0] + lens[1])] = '\0';
    for (i = 0; i < pos; i++)
        res[i] = str[i];
    j = replace_str_ds_3(lens, num, res, i);
    i += 2;
    for (;str[i] != '\0'; i++) {
        res[j] = str[i];
        j++;
    }
    return res;
}