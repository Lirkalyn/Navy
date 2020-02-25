/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** some replace
*/

#include <stdlib.h>

char *replace_str_pour(char *str, int pos, int opt)
{
    int i;
    int j;
    int lens[2] = {[0 ... 1] = 0};
    char *res;

    for (lens[0] = 0; str[lens[0]] != '\0'; lens[0]++);
    res = (char *)malloc((lens[0] + 1) * sizeof(char));
    res[lens[0]] = '\0';
    for (i = 0; i < pos; i++)
        res[i] = str[i];
    for (j = i + 1; str[j] != '\0'; j++)
        res[i++] = str[j];
    return res;
}