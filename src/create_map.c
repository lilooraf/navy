/*
** EPITECH PROJECT, 2019
** navy
** File description:
** create_map
*/

#include "my.h"

char **place_vertical(char **map, char *coord)
{
    char b = coord[0];
    int x = pos_x(coord[2], map[0]);
    int y = my_getnbr(&coord[3]) + 1;
    int b1 = my_getnbr(&b);
    int idx = 0;

    while (idx < b1) {
        map = place_point(x, y, map, b);
        y++;
        idx++;
    }
    return map;
}

char **place_horizontal(char **map, char *coord)
{
    char b = coord[0];
    int x = pos_x(coord[2], map[0]);
    int y = my_getnbr(&coord[3]) + 1;
    int b1 = my_getnbr(&b);
    int idx = 0;

    while (idx < b1) {
        map = place_point(x, y, map, b);
        x += 2;
        idx++;
    }
    return map;
}

char **place_boat(char **map_coord, char **map)
{
    for (int i = 0; map_coord[i]; i++) {
        if (detect_vertical(map_coord[i]))
            map = place_vertical(map, map_coord[i]);
        if (detect_horizontal(map_coord[i]))
            map = place_horizontal(map, map_coord[i]);
    }
    return map;
}

char **create_map(char *map_path)
{
    char *info_map = read_map(map_path);
    char **map_coord = my_str_to_word_array(info_map);
    char **map = create_empty_map();

    map = place_boat(map_coord, map);
    free(info_map);
    for (int i = 0; map_coord[i]; i++)
        free(map_coord[i]);
    return map;
}
