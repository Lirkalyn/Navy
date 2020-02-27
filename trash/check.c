/*
** EPITECH PROJECT, 2020
** my_navy
** File description:
** only one-desu
*/

#include <sys/signal.h>
#include <signal.h>
#include <stdarg.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/printf.h"
#include <stdio.h>

char *input_check(char **map, char **enemy_map, int *pos)
{
    char *line = NULL;
    size_t size;

    my_printf("attack: ");
    if (getline(&line, &size, stdin) == -1)
        return NULL;
    if (line[0] < 'A' || line[0] > 'H') {
        my_printf("wrong position\n");
        return input_check(map, enemy_map, pos);
    }
    else if (line[1] < '1' || line[1] > '8') {
        my_printf("wrong position\n");
        return input_check(map, enemy_map, pos);
    }
    pos[0] = (line[0] - 65);
    pos[1] = ((line[1] - '0') - 1);
    return line;
}