/*
** EPITECH PROJECT, 2020
** my_navi
** File description:
** boat-desu
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../include/my.h"

char **boat_maker4(int letter, int number, int value, char **map)
{
    if (map[number][letter] != '.') {
        map[0][0] = '0';
        return map;
    }
    else
        map[number][letter] = value;
    return map;
}

int *boat_maker3(int opt, int i, int search, char **map)
{
    int *coor = (int *)malloc(2 * sizeof(int));

    if (opt == 0) {
        for (int j = 2; j < 17; j++)
            coor[0] = (map[0][j] == search) ? j : coor[0];
        for (int j = 2; j < 10; j++)
            coor[1] = (map[j][0] == (i + '0')) ? j : coor[1];
    }
    else if (opt == 1) {
        for (int j = 2; j < 17; j++)
            coor[0] = (map[0][j] == (i + 65)) ? j : coor[0];
        for (int j = 2; j < 10; j++)
            coor[1] = (map[j][0] == search) ? j : coor[1];
    }
    return coor;
}

char **together(int opt, int i, char *line, char **map)
{
    int *coor;

    if (opt == 0) {
    coor = boat_maker3(0, i, line[2], map);
    map = boat_maker4(coor[0], coor[1], line[0], map);
    }
    else if (opt == 1) {
        coor = boat_maker3(1, i, line[3], map);
        map = boat_maker4(coor[0], coor[1], line[0], map);
    }
    return map;
}

char **boat_maker2(char *line, char **map)
{
    if ((line[2] == line[5]) && (line[3] < line[6]))
        for (int i = (line[3] - '0'); i <= (line[6] - '0'); i++)
            map = together(0, i, line, map);
    else if ((line[2] == line[5]) && (line[6] < line[3]))
        for (int i = (line[6] - '0'); i <= (line[3] - '0'); i++)
            map = together(0, i, line, map);
    if ((line[3] == line[6]) && (line[2] < line[5]))
        for (int i = (line[2] - 65); i <= (line[5] - 65); i++)
            map = together(1, i, line, map);
    else if ((line[3] == line[6]) && (line[5] < line[2]))
        for (int i = (line[5] - 65); i <= (line[2] - 65); i++)
            map = together(1, i, line, map);
    return map;
}

char **boat_maker(char *path, char **map)
{
    char *buf;
    char *tmp;
    int fd = open(path, O_RDONLY);
    int lenght = 31;
    int i = 0;

    buf = (char *)malloc((lenght + 1) * sizeof(char));
    if (fd == -1 || buf == NULL)
        return NULL;
    read(fd, buf, lenght);
    buf[lenght] = '\0';
    close(fd);
    while (buf[i] != '\0') {
        i += (i != 0) ? 1 : 0;
        tmp = (char *)malloc((7 + 1) * sizeof(char));
        for (int j = 0; buf[i] != '\n' && buf[i] != '\0'; tmp[j++] = buf[i++]);
        map = boat_maker2(tmp, map);
    }
    return map;
}