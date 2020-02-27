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

/*char **act(char **map, char **enemy_map, int *letter, int *number)
{
    char let = (((letter[0] * 4) + (letter[1] * 2) + letter[2]) + 65);
    char num = ((number[0] * 4) + (number[1] * 2) + number[2] + 1);
    int *coor = boat_maker3(0, num, let, map);
    int tmp = get_pid(0);

    get_pid(-99);
    if (map[coor[1]][coor[0]] == '.') {
        enemy_map[coor[1]][coor[0]] = 'o';
        pause();
        kill(tmp, SIGUSR1);
    }
    else if (map[coor[1]][coor[0]] >= '1' && map[coor[1]][coor[0]] <= '8') {
        map[coor[1]][coor[0]] = 'x';
        pause();
        kill(tmp, SIGUSR2);
    }
    get_pid(tmp);
    return enemy_map;
}*/

int game2(char **map, char ***enemy_map, int *turn, int *pos)
{
    char *line = NULL;
    int *letter = (int *)malloc(3 * sizeof(int));
    int *number = (int *)malloc(3 * sizeof(int));
    int touch = 0;

    if (*turn == 1) {
        line = input_check(map, *enemy_map, pos);
        if (line == NULL)
            return 84;
        send(line, turn, pos);
        touch = hit_or_miss();
        *enemy_map = act2(map, *enemy_map, touch, line);
        *turn += 1;
    }
    else if (*turn == 2) {
        receive(line, turn, letter, number);
        *enemy_map = act(map, *enemy_map, letter, number);
        *turn -= 1;
/*        for (int i = 0; i < 3; i++)
            my_printf("%d", letter[i]);
        my_printf("\n");
        for (int i = 0; i < 3; i++)
            my_printf("%d", number[i]);*/
    }
}

int game(char **map, int *loop, int turn)
{
    int *pos = (int *)malloc(2 * sizeof(int));
    char **enemy_map;
    //int loop = 2;

    enemy_map = map_maker();
    if (enemy_map == NULL || pos == NULL)
        return 84;
        my_printf("my positions:\n");
        my_show_word_array(map);
        my_printf("\nenemy's positions:\n");
        my_show_word_array(enemy_map);
    while (*loop == 2) {
        game2(map, &enemy_map, &turn, pos);
        my_printf("my positions:\n");
        my_show_word_array(map);
        my_printf("\nenemy's positions:\n");
        my_show_word_array(enemy_map);
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