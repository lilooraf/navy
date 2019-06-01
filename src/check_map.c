/*
** EPITECH PROJECT, 2019
** navy
** File description:
** check_map
*/

#include "my.h"

int int_range(char c)
{
    if (c > 58 || c < 49)
        return 1;
    return 0;
}

int char_rang(char c)
{
    if (c < 65 || c > 72)
        return 1;
    return 0;
}

int check_rigor(char **len)
{
    int i = 0;

    for (; len[i]; i++) {
        if (my_strlen(len[i]) != 7)
            return 0;
        if (len[i][1] != ':' || len[i][4] != ':')
            return 0;
        if (len[i][0] < 50 || len[i][0] > 53 || int_range(len[i][3])
            || int_range(len[i][6]))
            return 0;
        if (char_rang(len[i][2]) && char_rang(len[i][6]))
            return 0;
    }
    if (i < 4)
        return 0;
    return 1;
}

int add_map(char **len)
{
    int add = 0;

    for (int i = 0; len[i]; i++) {
        add = len[i][0] - 48;
        if (len[i][3] != len[i][6] && len[i][2] != len[i][5])
            return 1;
        if (len[i][2] == len[i][5] && len[i][3] != (len[i][6] - (add - 1)))
            return 1;
        if (len[i][3] == len[i][6] && len[i][2] != (len[i][5] - (add - 1)))
            return 1;
    }
    return 0;
}

int check_format(char *map)
{
    int i = 0;
    char **len = my_str_to_word_array(map);

    for (i = 0; len[i]; i++);
    if (my_strlen(len[i - 1]) < 2)
        len[i - 1] = NULL;
    if (!check_rigor(len) || !check_len_boat(len))
        return 0;
    if (add_map(len))
        return 0;
    return 1;
}
