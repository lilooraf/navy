/*
** EPITECH PROJECT, 2018
** read_file
** File description:
** read_file
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int check(char const *buff)
{
    int i = 0;

    while (buff[i] != 0) {
        if (buff[i] == 0)
            return (0);
        write(1, &buff[i], 1);
        i++;
    }
    return (1);
}

void cat_file(char const *filepath)
{
    int a = open(filepath, O_RDONLY);
    char *buff = malloc(sizeof(char));

    while (read(a, buff, 1) && check(buff));
}