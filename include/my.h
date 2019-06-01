/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef __MY_H__
#define __MY_H__

#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

typedef struct global
{
    int connect;
    int siguser;
    int piduser;
    char *pos;
    char **map;
    char **map_empty;
    char **map_enemy;
    char *shoot;
    int error;
    int end;
}global_t;

extern global_t global;

void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_str_isalpha(char const *str);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
int my_str_isprintable(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
void my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *);
int my_putstrn(char const *);
int my_getnbr(char const *str);
int my_strlen(char const *str);
int my_putnbr_base(int nb, char const *base);
char *my_strcpy(char *dest, char *src);
char *my_strdup(char const *src);
void *my_calloc(size_t elem_size, size_t elems);
char **my_str_to_word_array(char *str);
char **my_str_to_word_array_char(char *str, char c);
char *my_clear_str(char *str);
int check_num(char **av);
int usage(int ac, char **av);
char *strcpy_end(char *dest, char *src);
int pid_connect(int ac, char **av);
void catch_signal(int sig, siginfo_t *sinfo, void *data);
void disp_board();
void cat_file(char const *filepath);
char *read_file(char const *filepath);
char **create_empty_map(void);
char *create_line(int idx);
char *sep_line(void);
char *first_line(char *line);
char **create_map(char *map_path);
char **place_boat(char **map_coord, char **map);
char **place_horizontal(char **map, char *coord);
char **place_vertical(char **map, char *coord);
int detect_horizontal(char *coord);
int detect_vertical(char *coord);
char **place_point(int x, int y, char **map, char b);
char *read_map(char *map_path);
int detect_win(int user);
int detect_lose(char **map);
void put_map_in_file(char *fp);
void read_map_enemy(char *fp);
void change_map(char **map);
int ftc_player_1(char *fd, pid_t pid);
int ftc_player_2(int pid, char *fd);
void game_loop_p1();
void game_loop_p2();
char *get_pos();
char *detect_map(char **tab, char *str, char **map);
int pos_x(char c, char *str);
char *cl_str(char *str);
int check_map_rigor(char *);
int check_format(char *map);
bool check_len_boat(char **len);

#endif
