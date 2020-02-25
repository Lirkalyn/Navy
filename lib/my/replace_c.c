/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** some replace
*/

#include <stdlib.h>

char *replace_str_c(char *str, int letter, int pos)
{
    int i;
    int j;
    int str_len;
    char *res;

    for (str_len = 0; str[str_len] != '\0'; str_len++);
    res = (char *)malloc((str_len + 2) * sizeof(char));
    res[(str_len + 1)] = '\0';
    for (i = 0; i < pos; i++)
        res[i] = str[i];
    res[i] = letter;
    i += 1;
    for (;str[i] != '\0'; i++) {
        res[i] = str[(i + 1)];
    }
    return res;
}