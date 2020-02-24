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

/*int check_map3(char *path)
{
    char *buf;
    char *tmp;
    int fd = open(path, O_RDONLY);
    int lenght = 31;
    int i = 0;

    buf = (char *)malloc((lenght + 1) * sizeof(char));
    if (fd == -1 || buf == NULL)
        return 84;
    read(fd, buf, lenght);
    buf[lenght] = '\0';
    close(fd);
    while (buf[i] != '\0') {
        i += (i != 0) ? 1 : 0;
        tmp = (char *)malloc((7 + 1) * sizeof(char));
        for (int j = 0; buf[i] != '\n' && buf[i] != '\0'; tmp[j++] = buf[i++]);
//        if (check_map2(tmp) == 1)
//            return 1;
    }
//    return 0;
}*/

int start_game(int argc, char *argv[])
{
    char **map;

    if (check_map(argv[(argc - 1)]) == 1)
        return 84;
    map = map_maker(argv[(argc - 1)]);
    if (map == NULL)
        return 84;
//    my_show_word_array(map);
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