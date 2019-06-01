/*
** EPITECH PROJECT, 2019
** navy
** File description:
** ftc_game_board
*/

#include <my.h>

char *cl_str(char *str)
{
    int i = 0;
    int j = 0;
    char *tmp = my_calloc(sizeof(char), my_strlen(str));
    char *dest = my_strdup(str);

    for (i = 0; dest[i] != 0; i++)
        if (dest[i] == '\t' || str[i] == '\n' || str[i] == ':')
            dest[i] = ' ';
    for (i = 0; dest[i] == ' ' && dest[i] != 0; i++);
    for (; dest[i] != 0; i++)
        if (dest[i] == ' ' && dest[i + 1] == ' ');
        else {
            tmp[j] = dest[i];
            j++;
        }
    if (tmp[j - 1] == ' ')
        tmp[j - 1] = '\0';
    free (dest);
    dest = my_strdup(tmp);
    free(tmp);
    return (dest);
}

int pos_x(char c, char *str)
{
    int i;
    int size = my_strlen(str);

    for (i = 0; i < size; i++)
        if (str[i] == c && c!= '|' && c != ' ')
            return (i);
    return (-1);
}

int check_args(char *str)
{
    str = my_clear_str(str);
    if (str[0] >= 65 && str[0] <= 72 && str[1] >= 49 &&
        str[1] <= 56 && (str[2] == ' ' || str[2] == 0 || str[3] == 0))
        return 1;
    else {
        my_putstrn("wrong position");
        return 0;
    }
}

char *get_args(int *error)
{
    int i = 0;
    int j;
    char *buff = NULL;
    char *tmp = NULL;
    char *dest = NULL;

    for (int x = 0; i != 1; x++) {
        buff = my_calloc(sizeof(char), 2);
        j = read(0, buff, 1);
        if (j > 0) {
            tmp = my_calloc(sizeof(char), (j + my_strlen(dest) + 1));
            dest = strcpy_end(tmp, dest);
            dest = strcpy_end(dest, buff);
        }
        if (dest[x] == '\n')
            i = 1;
    }
    if (check_args(dest))
        *error = 0;
    return (dest);
}

char *get_pos(void)
{
    int error = 1;
    char *str = NULL;

    while (error) {
        my_putstr("attack: ");
        str = get_args(&error);
    }
    return (my_clear_str(str));
}
