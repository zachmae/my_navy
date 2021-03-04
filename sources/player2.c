/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-1-navy-zacharie.lawson
** File description:
** player2
*/

#include "navy.h"

static int connection(int pid)
{
    my_printf("my_pid: %d\n", getpid());
    if (kill(pid, SIGUSR1) == 0) {
        my_printf("successfully connected\n\n");
        CO->pid_other = pid;
    } else
        return 84;
    return 0;
}

int player2(char **av)
{
    char **my_map;
    char **e_map;
    char **pos;
    int ret;

    if (connection(my_getnbr(av[1])) == 84)
        return 84;
    CO->turn = 0;
    pos = get_position(av[2]);
    my_map = place_ship(blank_map(), pos);
    e_map = blank_map();
    free(pos);
    ret = game(my_map, e_map);
    free(my_map);
    free(e_map);
    return ret;
}