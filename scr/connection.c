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

int epid = 0;

int get_pid(int pid)
{
    if (pid == 0)
        return epid;
    else
        epid = pid;
}

void test(int si, siginfo_t *siginfo, void *context)
{
    if (get_pid(0) == 0 && si == SIGUSR1) {
        get_pid(siginfo->si_pid);
        kll(get_pid(0), SIGUSR2);
        my_printf("enemy connected\n\n");
    }
    else if (get_pid(0) == siginfo->si_pid && si == SIGUSR2)
        my_printf("successfully connected\n\n");
    if (get_pid(0) == -5 && si == SIGUSR1)
        get_pid(-1);
    else if (get_pid(0) == -5 && si == SIGUSR2)
        get_pid(-2);
    if (get_pid(0) == -20 && si == SIGUSR1)
        get_pid(-21);
    else if (get_pid(0) == -20 && si == SIGUSR2)
        get_pid(-22);
    if (get_pid(0) == -50 && si == SIGUSR1)
        get_pid(-51);
}

int find_enemy(int argc, char *argv[])
{
    struct sigaction sig;

    my_printf("my_pid: %d\n", getpid());
    sig.sa_flags = SA_SIGINFO;
    if (argc == 2) {
        my_printf("waiting for enemy connection...\n\n");
        sig.sa_sigaction = &test;
        sigaction(SIGUSR1, &sig, NULL);
        sigaction(SIGUSR2, &sig, NULL);
        pause();
    }
    else if (argc == 3) {
        for (int i = 0; argv[1][i] != '\0'; i++)
            epid = ((epid * 10) + (argv[1][i] - '0'));
        kll(epid, SIGUSR1);
        sig.sa_sigaction = &test;
        sigaction(SIGUSR1, &sig, NULL);
        sigaction(SIGUSR2, &sig, NULL);
        pause();
    }
}