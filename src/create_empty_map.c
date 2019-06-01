/*
** EPITECH PROJECT, 2019
** navy
** File description:
** empty_map
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

char *first_line(char *line)
{
    line = my_calloc(sizeof(char), 19);
    line[0] = ' ';
    line[1] = '|';
    line[2] = 'A';
    line[3] = ' ';
    line[4] = 'B';
    line[5] = ' ';
    line[6] = 'C';
    line[7] = ' ';
    line[8] = 'D';
    line[9] = ' ';
    line[10] = 'E';
    line[11] = ' ';
    line[12] = 'F';
    line[13] = ' ';
    line[14] = 'G';
    line[15] = ' ';
    line[16] = 'H';
    line[17] = '\n';
    return line;
}

char *sep_line(void)
{
    char *line = malloc(sizeof(char) * 19);
    int idx = 2;

    line[0] = '-';
    line[1] = '+';
    while (idx < 18) {
        line[idx] = '-';
        idx++;
    }
    line[17] = '\n';
    line[18] = '\0';
    return line;
}

char *create_line(int idx)
{
    char *line = malloc(sizeof(char) * 19);
    int idx2 = 2;
    int idx3 = 0;

    line[0] = idx + '0';
    line[1] = '|';
    while (idx2 < 18) {
        if (idx3 == 0) {
            line[idx2] = '.';
            idx3 = 1;
        }
        else if (idx3 == 1) {
            line[idx2] = ' ';
            idx3 = 0;
        }
        idx2++;
    }
    line[17] = '\n';
    line[18] = '\0';
    return line;
}

char **create_empty_map(void)
{
    char **map = NULL;
    int idx = 2;
    int idx2 = 1;

    map = malloc(sizeof(char *) * 11);
    map[0] = first_line(map[0]);
    map[1] = sep_line();
    while (idx < 10) {
        map[idx] = create_line(idx2);
        idx++;
        idx2++;
    }
    map[idx] = NULL;
    return map;
}
