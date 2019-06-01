/*
** EPITECH PROJECT, 2019
** navy
** File description:
** main
*/

#include "my.h"

int check_map_rigor(char *str)
{
    char *file = NULL;

    if (open(str, O_RDONLY) < 0)
        return 1;
    file = read_file(str);
    if (!check_format(file))
        return 1;
    return 0;
}

int pid_connect(int ac, char **av)
{
    if (ac == 2) {
        if (check_map_rigor(av[1]))
            return 84;
        if (ftc_player_1(av[1], getpid()))
            return 84;
    }
    if (ac == 3) {
        if (check_map_rigor(av[2]))
            return 84;
        if (ftc_player_2(my_getnbr(av[1]), av[2]))
            return 84;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (usage(ac, av))
        return 0;
    return (pid_connect(ac, av));
}
