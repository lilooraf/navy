/*
** EPITECH PROJECT, 2019
** navy
** File description:
** game_loop
*/

#include "my.h"
#include <unistd.h>


void write_file(char *str)
{
    char *clear = my_calloc(sizeof(char), 14);
    write(open("result.txt", O_WRONLY), clear, 14);
    write(open("result.txt", O_WRONLY), str, my_strlen(str));
    free(clear);
}

void set_shoot(void)
{
    write_file(detect_map(global.map_empty, global.pos, global.map_enemy));
    kill(global.piduser, 1);
}

void catch_signal(int sig, siginfo_t *sinfo, void *data)
{
    (void) data;
    (void) sinfo;
    if (sig == 1)
        global.siguser = 0;
}

void game_loop_p1(void)
{
    disp_board();
    global.pos = get_pos();
    read_map_enemy("enemy2.txt");
    set_shoot();
    usleep(10);
    cat_file("result.txt");
    my_putstr("\n");
    if (detect_win(1) || detect_lose(global.map))
        return;
    my_putstr("\nwaiting for enemy's attack...\n");
    while (global.siguser);
    global.siguser = 1;
    change_map(global.map);
    put_map_in_file("enemy1.txt");
    if (detect_lose(global.map) || detect_win(1))
        return;
    cat_file("result.txt");
    my_putstr("\n\n");
}

void game_loop_p2(void)
{
    my_putstrn("waiting for enemy's attack...");
    while (global.siguser);
    global.siguser = 1;
    change_map(global.map);
    put_map_in_file("enemy2.txt");
    if (detect_lose(global.map) || detect_win(2))
        return;
    cat_file("result.txt");
    my_putstr("\n\n");
    global.pos = get_pos();
    read_map_enemy("enemy1.txt");
    set_shoot();
    usleep(10);
    cat_file("result.txt");
    my_putstr("\n\n");
    if (detect_lose(global.map) || detect_win(2))
        return;
    disp_board();
}
