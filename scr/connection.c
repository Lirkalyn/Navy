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
    get_pid(siginfo->si_pid);
    kill(get_pid(0), SIGUSR2);
    my_printf("enemy connected\n\n");
}

void testbis(int si, siginfo_t *siginfo, void *context)
{
    if (get_pid(0) == siginfo->si_pid)
        my_printf("successfully connected\n\n");
}

int find_enemy(int argc, char *argv[])
{
    struct sigaction sig;

    sig.sa_flags = SA_SIGINFO;
    if (argc == 2) {
        my_printf("my_pid: %d\nwaiting for enemy connection...\n\n", getpid());
        sig.sa_sigaction = &test;
        sigaction(SIGUSR1, &sig, NULL);
        if (usleep(100000000.0) == -1)
            return 84;
    }
    else if (argc == 3) {
        for (int i = 0; argv[1][i] != '\0'; i++)
            epid = ((epid * 10) + (argv[1][i] - '0'));
        kill(epid, SIGUSR1);
        sig.sa_sigaction = &testbis;
        sigaction(SIGUSR2, &sig, NULL);
        if (usleep(100000000.0) == -1)
            return 84;
    }
    return 0;
}