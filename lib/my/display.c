/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** display
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}