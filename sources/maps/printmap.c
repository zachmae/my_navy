/*
** EPITECH PROJECT, 2020
** printmap
** File description:
** function that printmaps
*/

#include "navy.h"

void print_map(char **map, char const *str)
{
    int c;
    int y = 0;
    int x;

    my_printf("%s\n", str);
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (c = 0; c < 8; c++) {
        my_printf("%d|", c + 1);
        for (x = 0; x < 8; x++) {
            my_printf("%c", map[y][x]);
            if (x != 7)
                my_printf(" ");
        }
        y++;
        my_printf("\n");
    }
    my_printf("\n");
}