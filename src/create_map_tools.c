/*
** EPITECH PROJECT, 2019
** navy
** File description:
** create_map_tools
*/

#include "my.h"

char **place_point(int x, int y, char **map, char b)
{
    map[y][x] = b;
    return map;
}

int detect_vertical(char *coord)
{
    if (coord[2] == coord[5])
        return 1;
    else
        return 0;
}

int detect_horizontal(char *coord)
{
    if (coord[3] == coord[6])
        return 1;
    else
        return 0;
}

char *read_map(char *map_path)
{
    int i = 0;
    int j;
    char *buff = NULL;
    char *tmp = NULL;
    char *dest = NULL;
    int fd = open(map_path, O_RDONLY);

    for (int x = 0; i != 1; x++) {
        buff = my_calloc(sizeof(char), 2);
        j = read(fd, buff, 1);
        if (j > 0) {
            tmp = my_calloc(sizeof(char), (j + my_strlen(dest) + 1));
            dest = strcpy_end(tmp, dest);
            dest = strcpy_end(dest, buff);
        }
        if (j == 0)
            i = 1;
    }
    return (dest);
}