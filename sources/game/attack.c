/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-1-navy-zacharie.lawson
** File description:
** attack
*/

#include "navy.h"

void send_target(char *target)
{
    for (int i = 0; i < target[0] - 'A'; i++) {
        kill(CO->pid_other, SIGUSR1);
        usleep(10);
    }
    kill(CO->pid_other, SIGUSR2);
    usleep(10);
    for (int i = 0; i < target[1] - '1'; i++) {
        kill(CO->pid_other, SIGUSR1);
        usleep(10);
    }
    kill(CO->pid_other, SIGUSR2);
}

void hit_marker(char *target, char **e_map)
{
    if (e_map[target[1] - '1'][target[0] - 'A'] == 'x' ||
        e_map[target[1] - '1'][target[0] - 'A'] == 'o') {
        my_printf("miss\n");
    } else {
        if (CO->hit) {
            e_map[target[1] - '1'][target[0] - 'A'] = 'x';
            my_printf("hit\n");
            CO->my_hit++;
        } else {
            e_map[target[1] - '1'][target[0] - 'A'] = 'o';
            my_printf("miss\n");
        }
    }
}

void update_map(char **e_map, char *target)
{
    size_t len;

    if (target[0] < 'A' || target[0] > 'H' ||
        target[1] < '0' || target[1] > '8' || target[2] != '\n') {
        my_printf("wrong position\nattack: ");
        getline(&target, &len, stdin);
        update_map(e_map, target);
        return;
    }
    target[2] = '\0';
    send_target(target);
    change_sig(1);
    CO->waiting = 1;
    while (CO->waiting);
    my_printf("%s: ", target);
    hit_marker(target, e_map);
}

void attack(char **my_map, char **e_map)
{
    char *target = NULL;
    size_t len = 0;

    my_printf("attack: ");
    getline(&target, &len, stdin);
    update_map(e_map, target);
    free(target);
    CO->turn = 0;
    my_printf("\n");
}
