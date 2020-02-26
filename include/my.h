/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** h-desu
*/

#ifndef _MY_H_
#define _MY_H_

void my_putchar(char c);
int myputstr(char *str, int opt);
int my_puterror(char *str, int opt);
int my_put_nbr(int nb);
int str_cmp(char const *s1, char const *s2);
int check_map(char *path);
int check_map2(char *line);
int my_show_word_array(char * const *tab);
char **map_maker(char *path);
char **boat_maker(char *path, char **map);
int find_enemy(int argc, char *argv[]);
int get_pid(int pid);

#endif
