/*
** EPITECH PROJECT, 2019
** check_map_2.c
** File description:
** error handle
*/

#include <stdbool.h>
#include "my.h"

bool check_len_boat(char **len)
{
    int j = 0;

    for (int i = 0; len[i + 1] != NULL; i++)
        if (len[i][0] == len[i + 1][0])
            return false;
    return true;            
}
