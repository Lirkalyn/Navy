/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** main of my_runner
*/

/*#include <stdlib.h>
#include <time.h>*/
//#include <sigaction.h>
#include <sys/signal.h>
#include <signal.h>
#include <stdarg.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "include/my.h"
#include "include/printf.h"

#include <stdio.h>

int player_2(char ***map, char ***enemy_map, int *turn, int *pos)
{
    char *line = NULL;
    int *letter = (int *)malloc(3 * sizeof(int));
    int *number = (int *)malloc(3 * sizeof(int));
    int touch = 0;

    disp(*map, *enemy_map);
    receive(line, turn, letter, number);
    *map = act(*map, *enemy_map, letter, number);
    if (end_game(*map) == 1)
        return 1;
    line = input_check(*map, *enemy_map, pos);
    if (line == NULL)
        return 84;
    send(line, turn, pos);
    touch = hit_or_miss();
    *enemy_map = act2(*map, *enemy_map, touch, line);
/*    if (end_turn_1(*map) == 1) {
        my_printf("I won\n");
        return 0;
    }*/
}

int player_1(char ***map, char ***enemy_map, int *turn, int *pos)
{
    char *line = NULL;
    int *letter = (int *)malloc(3 * sizeof(int));
    int *number = (int *)malloc(3 * sizeof(int));
    int touch = 0;

    disp(*map, *enemy_map);
    line = input_check(*map, *enemy_map, pos);
    if (line == NULL)
        return 84;
    send(line, turn, pos);
    touch = hit_or_miss();
    *enemy_map = act2(*map, *enemy_map, touch, line);
    receive(line, turn, letter, number);
    *map = act(*map, *enemy_map, letter, number);
    if (end_game(*map) == 1)
        return 1;
/*    if (end_turn_1(*map) == 1) {
        my_printf("I won\n");
        return 0;
    }*/
}

int game(char **map, int *loop, int turn)
{
    int *pos = (int *)malloc(2 * sizeof(int));
    char **enemy_map;

    enemy_map = map_maker();
    if (enemy_map == NULL || pos == NULL)
        return 84;
    while (*loop == 2) {
        if (turn == 1)
            player_1(&map, &enemy_map, &turn, pos);
        else if (turn == 2)
            player_2(&map, &enemy_map, &turn, pos);
    }
}

int start_game(int argc, char *argv[])
{
    char **map;
    int loop = 2;
    int turn = 0;

    if (check_map(argv[(argc - 1)]) == 1)
        return 84;
    map = map_maker();
    if (map == NULL)
        return 84;
    map = boat_maker(argv[(argc - 1)], map);
    if (map[0][0] == '0')
        return 84;
    if (find_enemy(argc, argv) == 84)
        return 84;
        turn = (argc == 2) ? 1 : 2;
        game(map, &loop, turn);
    return loop;
}

int main(int argc, char *argv[])
{
    if (argc == 2 && str_cmp(argv[1], "-h") == 0) {
        myputstr("USAGE", 0);
        myputstr("\t./navy [first_player_pid] navy_positions", 0);
        myputstr("DESCRIPTION", 0);
        myputstr("\tfirst_player_pid: only for the 2nd player.", 1);
        myputstr("pid of the first player.", 0);
        myputstr("\tnavy_positions: file representing the", 1);
        myputstr("positions of the ships.", 0);
    }
    else
        return start_game(argc, argv);
}