/*
** EPITECH PROJECT, 2019
** navy
** File description:
** disp_board
*/

#include <my.h>

void disp_board(void)
{
    my_putstr("my positions:\n");
    for (int i = 0; global.map[i]; i++)
        my_putstr(global.map[i]);
    my_putstr("\nenemy's positions:\n");
    for (int i = 0; global.map_empty[i]; i++)
        my_putstr(global.map_empty[i]);
    my_putchar('\n');
}

void put_map_in_file(char *fp)
{
    char *map = my_calloc(sizeof(char), 181);
    int fd = open(fp, O_WRONLY);
    for (int i = 0; i <= 10; i++) {
        map = strcpy_end(map, global.map[i]);
    }
    write(fd, map, 180);
    close(fd);
    free(map);
}

void read_map_enemy(char *fp)
{
    char *buff = my_calloc(sizeof(char), 181);
    int fd = open(fp, O_RDONLY);

    read(fd, buff, 180);
    global.map_enemy = my_str_to_word_array(buff);
}

void change_map(char **map)
{
    char *buff = my_calloc(sizeof(char), 6);
    int fd = open("result.txt", O_RDONLY);

    read(fd, buff, 5);
    int x = pos_x(buff[0], map[0]);
    int y = buff[1] - '0' + 1;
    if (buff[4] == 'h') {
        map[y][x] = 'x';
    }
    if (buff[4] == 'm') {
        map[y][x] = 'o';
    }
    free(buff);
}

char *detect_map(char **tab, char *str, char **map)
{
    int x = pos_x(str[0], map[0]);
    int y = str[1] - '0';
    char *hit = ": hit";
    char *missed = ": missed";

    if (map[y + 1][x] != '.') {
        tab[y + 1][x] = 'x';
        return (my_strcat(cl_str(str), hit));
    }
    else
        tab[y + 1][x] = 'o';
    return (my_strcat(cl_str(str), missed));
}
