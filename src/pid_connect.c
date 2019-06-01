/*
** EPITECH PROJECT, 2019
** navy
** File description:
** pid_connect
*/

#include "struct.h"
#include "my.h"

void disp_pid_p1(pid_t pid)
{
    my_putstr("my_pid: ");
    my_put_nbr(pid);
    my_putchar('\n');
    my_putstr("waiting for enemy connection...\n\n");
}

void connect_1(int sig, siginfo_t *sinfo, void *data)
{
    (void) sig;
    (void) data;
    global.connect = 0;
    global.piduser = sinfo->si_pid;
    kill(global.piduser, 1);
}

int connect_2(int pid, char *fp)
{
    kill(global.piduser, SIGUSR1);
    usleep(100000);
    if (global.siguser)
        return 1;
    my_putstr("my_pid: ");
    my_put_nbr(pid);
    my_putchar('\n');
    my_putstr("successfully connected\n\n");
    return (0);
}

int ftc_player_2(int pid, char *fd)
{
    struct sigaction s2;

    s2.sa_sigaction = &catch_signal;
    sigaction(1, &s2, NULL);
    sigaction(10, &s2, NULL);
    global.piduser = pid;
    global.map = create_map(fd);
    if (connect_2(getpid(), fd))
        return 1;
    global.siguser = 1;
    global.map_empty = create_empty_map();
    put_map_in_file("enemy2.txt");
    read_map_enemy("enemy1.txt");
    disp_board();
    while (global.end)
        game_loop_p2();
    return 0;
}

int ftc_player_1(char *fd, pid_t pid)
{
    struct sigaction s;
    struct sigaction s2;

    s2.sa_sigaction = &catch_signal;
    s.sa_sigaction = &connect_1;
    s.sa_flags = SA_SIGINFO;
    sigaction(1, &s2, NULL);
    sigaction(10, &s, NULL);
    disp_pid_p1(pid);
    while (global.connect);
    my_putstrn("enemy connected\n");
    global.map = create_map(fd);
    global.map_empty = create_empty_map();
    put_map_in_file("enemy1.txt");
    while (global.end)
        game_loop_p1();
    return 0;
}