/*
** EPITECH PROJECT, 2019
** navy
** File description:
** win_lose
*/

#include <my.h>

void check_map(char c, int *i)
{
    if (c != '.' && c != 'x' && c != 'o')
        *i += 1;
}

int detect_lose(char **map)
{
    int i = 0;

    for (int y = 2; y < 10; y++)
        for (int x = 2; x < 17; x += 2)
            check_map(map[y][x], &i);
    if (i == 0) {
        global.end = 0;
        cat_file("result.txt");
        my_putstr("\n\n");
        disp_board();
        my_putstr("Enemy won\n");
        kill(global.piduser, 1);
        return 1;
    }
    return 0;
}

int detect_win(int user)
{
    int i = 0;

    if (user == 1)
        read_map_enemy("enemy2.txt");
    if (user == 2)
        read_map_enemy("enemy1.txt");
    for (int y = 2; y < 10; y++)
        for (int x = 2; x < 17; x += 2)
            check_map(global.map_enemy[y][x], &i);
    if (i == 0) {
        global.end = 0;
        disp_board();
        my_putstr("I won\n");
        kill(global.piduser, 1);
        return 1;
    }
    return 0;
}
