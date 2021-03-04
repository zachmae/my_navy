/*
** EPITECH PROJECT, 2020
** map check
** File description:
** error handling for maps
*/

#include "navy.h"

#define ABS(value) (((value) < 0)? (value) * -1 : (value))

int is_numcoord(char c)
{
    if (c >= '1' && c <= '8')
        return 1;
    return 0;
}

int is_lettercoord(char c)
{
    if (c >= 'A' && c <= 'H')
        return 1;
    return 0;
}

int check_spacing(char const *pos, int y)
{
    int space = pos[y * 8] - '1';

    if (!(pos[y * 8 + 2] != pos[y * 8 + 5] ^ pos[y * 8 + 3] != pos[y * 8 + 6]))
        return 1;
    if (pos[y * 8 + 2] != pos[y * 8 + 5])
        if (ABS(pos[y * 8 + 2] - pos[y * 8 + 5]) != space)
            return 1;
    if (pos[y * 8 + 3] != pos[y * 8 + 6])
        if (ABS(pos[y * 8 + 3] - pos[y * 8 + 6]) != space)
            return 1;
    return 0;
}

int check_pos(char const *pos)
{
    int y = 0;
    for (; pos[y * 8] != '\0'; y++) {
        if (pos[y * 8] != y + '2')
            return 1;
        if (pos[y * 8] > '5' || pos[y * 8] < '2')
            return 1;
        if (!(is_numcoord(pos[y * 8 + 3]) && is_numcoord(pos[y * 8 + 6])))
            return 1;
        if (!(is_lettercoord(pos[y * 8 + 2]) &&
            is_lettercoord(pos[y * 8 + 5])))
            return 1;
        if (check_spacing(pos, y))
            return 1;
        if (pos[y * 8 + 1] != ':' || pos[y * 8 + 4] != ':')
            return 1;
    }
    return 0;
}

int boat_collide(char **map)
{
    int y;
    int x;
    int c = 0;

    for (y = 0; map[y]; y++) {
        for (x = 0; map[y][x]; x++) {
            if (!(map[y][x] == '.'))
                c++;
        }
    }
    if (c != 14)
        return 1;
    return 0;
}