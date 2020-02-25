/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** main of my_runner
*/

/*#include <stdlib.h>
#include <time.h>*/
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "include/my.h"

#include <stdio.h>

int start_game(int argc, char *argv[])
{
    char **map;

    if (check_map(argv[(argc - 1)]) == 1)
        return 84;
    map = map_maker(argv[(argc - 1)]);
    if (map == NULL)
        return 84;
    map = boat_maker(argv[(argc - 1)], map);
    if (map[0][0] == '0')
        return 84;
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