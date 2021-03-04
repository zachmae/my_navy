/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-1-navy-zacharie.lawson
** File description:
** player1
*/

#include "navy.h"

static void connection(void)
{
    my_printf("my_pid: %d\nWaiting for enemy connection...\n", getpid());
    CO->waiting = 1;
    change_sig(0);
    while (CO->waiting);
    my_printf("\nenemy connected\n\n");
}

int player1(char **av)
{
    char **my_map;
    char **e_map;
    char **pos;
    int ret = 0;

    connection();
    CO->turn = 1;
    pos = get_position(av[1]);
    my_map = place_ship(blank_map(), pos);
    e_map = blank_map();
    free(pos);
    ret = game(my_map, e_map);
    free(my_map);
    free(e_map);
    return ret;
}