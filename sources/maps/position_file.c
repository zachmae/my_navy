/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-1-navy-zacharie.lawson
** File description:
** position_file
*/

#include "navy.h"

void place_ship_between(char ** map, char **pos, int i)
{
    for (int j = 1; j < pos[i][0] - '0' - 1; j++) {
        if (pos[i][3] == pos[i][6]) {
            if (pos[i][2] < pos[i][5])
                map[pos[i][3] - '1'][pos[i][2] - 'A' + j] = pos[i][0];
            if (pos[i][2] > pos[i][5])
                map[pos[i][3] - '1'][pos[i][2] - 'A' - j] = pos[i][0];
        }
        if (pos[i][2] == pos[i][5]) {
            if (pos[i][3] < pos[i][6])
                map[pos[i][3] - '1' + j][pos[i][2] - 'A'] = pos[i][0];
            if (pos[i][3] > pos[i][6])
                map[pos[i][3] - '1' - j][pos[i][2] - 'A'] = pos[i][0];
        }
    }
}

char **place_ship(char **map, char **pos)
{
    for (int i = 0; i < 4; i++) {
        map[pos[i][3] - '1'][pos[i][2] - 'A'] = pos[i][0];
        map[pos[i][6] - '1'][pos[i][5] - 'A'] = pos[i][0];
        place_ship_between(map, pos, i);
    }
    return map;
}

char **get_position(char const *file)
{
    int fd = open(file, O_RDONLY);
    char **pos;
    pos = malloc(sizeof(char *) * 5);
    for (int i = 0; i < 4; i++) {
        pos[i] = malloc(sizeof(char) * 8);
        read(fd, pos[i], 8);
        pos[i][7] = '\0';
    }
    pos[4] = NULL;
    return pos;
}