/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** display-desu
*/

#include <unistd.h>
#include "../include/my.h"

int my_show_word_array(char * const *tab)
{
    int i;
    int j;

    for (i = 0; tab[i] != 0; i++) {
        for (j = 0; tab[i][j] != '\0'; j++)
            my_putchar(tab[i][j]);
        my_putchar('\n');
    }
    return 0;
}