/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** strcpy
*/


void my_putchar(char c);

void my_putstr(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = ('\0');
    return (dest);
}
