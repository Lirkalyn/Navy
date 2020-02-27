/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** h-desu
*/

#ifndef _MY_H_
#define _MY_H_

#include <signal.h>

void my_putchar(char c);
int myputstr(char *str, int opt);
int my_puterror(char *str, int opt);
int my_put_nbr(int nb);
int str_cmp(char const *s1, char const *s2);
int check_map(char *path);
int check_map2(char *line);
int my_show_word_array(char * const *tab);
char **map_maker(void);
char **boat_maker(char *path, char **map);
int find_enemy(int argc, char *argv[]);
int get_pid(int pid);
int send(char *line, int *turn, int *pos);
int receive(char *line, int *turn, int *letter, int *number);
void test(int si, siginfo_t *siginfo, void *context);
char *input_check(char **map, char **enemy_map, int *pos);
int *boat_maker3(int opt, int i, int search, char **map);
int hit_or_miss(void);
char **act(char **map, char **enemy_map, int *letter, int *number);
char **act2(char **map, char **enemy_map, int touch, char *line);
int disp(char **map, char **enemy_map);
int end_game(char **map);
int end_turn_1(char **map);
int end_turn_2(char **map);
void kll(int pid, int signal);

#endif
