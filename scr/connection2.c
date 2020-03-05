/*
** EPITECH PROJECT, 2020
** my_navi
** File description:
** connection-desu
*/

#include <sys/signal.h>
#include <signal.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/printf.h"

int hit_or_miss(void)
{
    int tmp = get_pid(0);
    int rsl;

    get_pid(-20);
    kll(tmp, SIGUSR1);
    pause();
    rsl = get_pid(0);
    get_pid(tmp);
    return rsl;
}

void send_choice(int pos, int tmp)
{
    if ((pos % 2) == 0)
        kll(tmp, SIGUSR1);
    else if ((pos % 2) == 1)
        kll(tmp, SIGUSR2);
}

int send(char *line, int *turn, int *pos)
{
    int tmp = get_pid(0);

    get_pid(-50);
    for (int i = 0; i < 3; i++) {
        send_choice(pos[0], tmp);
        pos[0] /= 2;
        pause();
    }
    for (int i = 0; i < 3; i++) {
        send_choice(pos[1], tmp);
        pos[1] /= 2;
        pause();
    }
    get_pid(tmp);
}

int receive(char *line, int *turn, int *letter, int *number)
{
    int tmp = get_pid(0);
    struct sigaction sig;

    sig.sa_flags = SA_SIGINFO;
    sig.sa_sigaction = &test;
    sigaction(SIGUSR1, &sig, NULL);
    sigaction(SIGUSR2, &sig, NULL);
    my_printf("waiting for enemy's attack...\n");
    for (int i = 0; i < 6; i++) {
        get_pid(-5);
        pause();
        if (i < 3)
            letter[(2 - i)] = ((get_pid(0) * (-1)) - 1);
        else
            number[(5 - i)] = ((get_pid(0) * (-1)) - 1);
        kll(tmp, SIGUSR1);
    }
    get_pid(tmp);
}