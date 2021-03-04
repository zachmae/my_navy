/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-1-navy-zacharie.lawson
** File description:
** game
*/

#include "navy.h"

void disp_all(char **my_map, char **e_map)
{
    print_map(my_map, "my positions:");
    print_map(e_map, "enemy's positions:");
}

void get_shot_on_map(char *target, char ** my_map)
{
    if (my_map[target[1] - '1'][target[0] - 'A'] == 'x' ||
        my_map[target[1] - '1'][target[0] - 'A'] == 'o') {
        my_printf("missed\n");
        kill(CO->pid_other, SIGUSR2);
    } else {
        if (!(my_map[target[1] - '1'][target[0] - 'A'] == '.')) {
            my_map[target[1] - '1'][target[0] - 'A'] = 'x';
            CO->e_hit++;
            my_printf("hit\n");
            kill(CO->pid_other, SIGUSR1);
        } else {
            my_map[target[1] - '1'][target[0] - 'A'] = 'o';
            my_printf("missed\n");
            kill(CO->pid_other, SIGUSR2);
        }
    }
}

void wait(char **my_map, char **e_map)
{
    my_printf("waiting for enemy’s attack...\n");
    change_sig(2);
    CO->char_cpt = 0;
    CO->sig_target[0] = 'A';
    CO->sig_target[1] = '1';
    CO->waiting = 1;
    while (CO->waiting);
    my_printf("%s: ", CO->sig_target);
    get_shot_on_map(CO->sig_target, my_map);
    CO->turn = 1;
    my_printf("\n");
}

int game(char **my_map, char **e_map)
{
    CO->my_hit = 0;
    CO->e_hit = 0;
    int i = 1;
    while (CO->e_hit != 14 && CO->my_hit != 14) {
        if (i == 1)
            disp_all(my_map, e_map);
        if (CO->turn) {
            attack(my_map, e_map);
        } else {
            wait(my_map, e_map);
        }
        i *= -1;
    }
    disp_all(my_map, e_map);
    if (CO->e_hit == 14) {
        my_printf("Enemy won");
        return 1;
    } else {
        my_printf("I won\n");
        return 0;
    }
}
