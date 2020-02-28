/*
** EPITECH PROJECT, 2020
** my_navy
** File description:
** act-desu
*/

#include <sys/signal.h>
#include <signal.h>
#include <stdarg.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/printf.h"

int disp(char **map, char **enemy_map)
{
    my_printf("my positions:\n");
    my_show_word_array(map);
    my_printf("\nenemy's positions:\n");
    my_show_word_array(enemy_map);
    my_printf("\n");
}

char **act(char **map, char **enemy_map, int *letter, int *number)
{
    char let = (((letter[0] * 4) + (letter[1] * 2) + letter[2]) + 65);
    char num = ((number[0] * 4) + (number[1] * 2) + number[2] + 1);
    int *coor = boat_maker3(0, num, let, map);
    int tmp = get_pid(0);

    get_pid(-99);
    if (map[coor[1]][coor[0]] == '.') {
        map[coor[1]][coor[0]] = 'o';
        my_printf("%c%c: missed\n\n", let, (num + '0'));
        pause();
        kll(tmp, SIGUSR1);
    }
    else if (map[coor[1]][coor[0]] >= '1' && map[coor[1]][coor[0]] <= '8') {
        map[coor[1]][coor[0]] = 'x';
        my_printf("%c%c: hit\n\n", let, (num + '0'));
        pause();
        kll(tmp, SIGUSR2);
    }
    get_pid(tmp);
    return map;
}

char **act2(char **map, char **enemy_map, int touch, char *line)
{
    int *coor = boat_maker3(0, (line[1] - '0'), line[0], map);

    if (touch == -22) {
        my_printf("%c%c: hit\n\n", line[0], line[1]);
        enemy_map[coor[1]][coor[0]] = 'x';
    }
    else if (touch == -21) {
        my_printf("%c%c: missed\n\n", line[0], line[1]);
        enemy_map[coor[1]][coor[0]] = 'o';
    }
    return enemy_map;
}