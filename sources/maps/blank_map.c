/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-1-navy-zacharie.lawson
** File description:
** blank_map
*/

#include "navy.h"

char **blank_map(void)
{
    char **map = malloc(sizeof(char *) * 9);
    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(char) * 9);
        for (int j = 0; j < 8; j++)
            map[i][j] = '.';
        map[i][8] = '\0';
    }
    map[8] = NULL;
    return map;
}