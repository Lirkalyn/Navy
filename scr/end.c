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

#include <stdio.h>

void kll(int pid, int signal)
{
    usleep(10000);
    kill(pid, signal);
}

int end_turn_1(char **map)
{
    int tmp = get_pid(0);

    get_pid(-50);
    pause();
    if (get_pid(0) == 51) {
        get_pid(tmp);
        return 1;
    }
    else if (end_game(map) == 1) {
        kll(get_pid(0), SIGUSR1);//kill(get_pid(0), SIGUSR1);
        get_pid(tmp);
        return 2;
    }
    else {
        kll(get_pid(0), SIGUSR2);//kill(get_pid(0), SIGUSR2);
        get_pid(tmp);
        return 0;
    }
}

int end_turn_2(char **map)
{
    int tmp = get_pid(0);

        get_pid(-50);
        if (end_game(map) == 1) {
            kll(get_pid(0), SIGUSR1);//kill(get_pid(0), SIGUSR1);
            get_pid(tmp);
            return 2;
        }
        else {
            kll(get_pid(0), SIGUSR2);//kill(get_pid(0), SIGUSR2);
            get_pid(tmp);
            return 0;
        }
        pause();
        if (get_pid(0) == 51) {
            get_pid(tmp);
            return 1;
        }
}

int end_game(char **map)
{
    int nb[4] = {[0 ... 3] = 0};

    for (int i = 2; i < 10; i++)
        for (int j = 2; j < 17; j++) {
            if (map[i][j] == '2')
                nb[0] += 1;
            if (map[i][j] == '3')
                nb[1] += 1;
            if (map[i][j] == '4')
                nb[2] += 1;
            if (map[i][j] == '5')
                nb[3] += 1;
        }
//    my_printf("2 = %d, 3 = %d, 4 = %d, 5 = %d", nb[0], nb[1], nb[2], nb[3]);
    if (nb[0] == 0 && nb[1] == 0 && nb[2] == 0 && nb[3] == 0) {
        my_printf("Enemy won\n");
        kll(get_pid(0), SIGUSR1);
        return 1;
    }
    else
        return 0;
}