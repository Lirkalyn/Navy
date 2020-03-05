/*
** EPITECH PROJECT, 2020
** my_navy
** File description:
** it's over-desu
*/

#include <sys/signal.h>
#include <signal.h>
#include <stdarg.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/printf.h"

void kll(int pid, int signal)
{
    usleep(10000);
    kill(pid, signal);
}

int end_game_2(char **enemy_map)
{
    int nb = 0;

    for (int i = 2; i < 10; i++)
        for (int j = 2; j < 17; j++)
            nb += (enemy_map[i][j] == 'x') ? 1 : 0;
    if (nb == 14) {
        my_printf("I won\n");
        return 1;
    }
    else
        return 0;
}

int end_game(char **map)
{
    int nb[4] = {[0 ... 3] = 0};

    for (int i = 2; i < 10; i++)
        for (int j = 2; j < 17; j++) {
            nb[0] += (map[i][j] == '2') ? 1 : 0;
            nb[1] += (map[i][j] == '3') ? 1 : 0;
            nb[2] += (map[i][j] == '4') ? 1 : 0;
            nb[3] += (map[i][j] == '5') ? 1 : 0;
        }
    if (nb[0] == 0 && nb[1] == 0 && nb[2] == 0 && nb[3] == 0) {
        my_printf("Enemy won\n");
        return 1;
    }
    else
        return 0;
}