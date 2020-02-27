/*
** EPITECH PROJECT, 2019
** my_navy
** File description:
** check-desu
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/printf.h"

char *input_check(char **map, char **enemy_map, int *pos)
{
    char *line = NULL;
    size_t size;

    my_printf("\nattack: ");
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

int check_map2(char *line)
{
    int len = ((line[0] - '0') - 1);
    int bool[4] = {[0 ... 3] = 0};

    if (line[2] == line[5])
        if (((line[3] + len) == line[6]) || ((line[3] - len) == line[6]))
            bool[0] = bool[0];
        else if (((line[3] + len) >= '9') || ((line[3] - len) <= '0'))
            bool[0] = 1;
        else
            bool[0] = 1;
    else if (line[3] == line[6])
        if (((line[2] - len) == line[5]) || ((line[2] + len) == line[5]))
            bool[1] = bool[1];
        else if (((line[2] + len) > 'H') || ((line[2] - len) < 'A'))
            bool[0] = 1;
        else
            bool[1] = 1;
    else
        bool[2] = 1;
    return (bool[0] == bool[1] == bool[2] == bool[3]) ? 0 : 1;
}

int check_map(char *path)
{
    char *buf;
    char *tmp;
    int fd = open(path, O_RDONLY);
    int lenght = 31;
    int i = 0;

    buf = (char *)malloc((lenght + 1) * sizeof(char));
    if (fd == -1 || buf == NULL)
        return 84;
    read(fd, buf, lenght);
    buf[lenght] = '\0';
    close(fd);
    while (buf[i] != '\0') {
        i += (i != 0) ? 1 : 0;
        tmp = (char *)malloc((7 + 1) * sizeof(char));
        for (int j = 0; buf[i] != '\n' && buf[i] != '\0'; tmp[j++] = buf[i++]);
        if ((check_map2(tmp) == 1) || (tmp[0] < '2' || tmp[0] > '5'))
            return 1;
    }
    return 0;
}