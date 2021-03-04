/*
** EPITECH PROJECT, 2020
** my strdup
** File description:
** duplicate a string
*/

#include "stdlib.h"

char *my_strcpy(char *dest, char const *src);

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *dest;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    dest = my_strcpy(dest, src);
    return (dest);
}
