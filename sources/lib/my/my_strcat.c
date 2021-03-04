/*
** EPITECH PROJECT, 2020
** my strcat
** File description:
** contain my strcat
*/

#include <stdlib.h>

int my_strlen(char *str);

char *my_strcat(char *dest, char *src)
{
    int count;
    int i = 0;
    char *res;

    res = malloc(sizeof(*res) * (my_strlen(dest) + my_strlen(src) + 1));
    while (dest[i] != '\0') {
        res[i] = dest[i];
        i++;
    }
    for (count = 0; src[count] != '\0'; count++) {
        res[i + count] = src[count];
    }
    res[i + count] = '\0';
    return (res);
}
