/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** more-desu
*/

//#include "my.h"

int str_cmp(char const *s1, char const *s2)
{
    int i;

    for (i = 0; s1[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return (1);
    return (0);
}