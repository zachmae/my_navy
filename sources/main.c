/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-1-navy-zacharie.lawson
** File description:
** main
*/

#include "navy.h"

core_t *CO;

int print_usage(int ac, char **av)
{
    if (ac == 2)
        if (my_strcmp(av[1], "-h") == 0) {
            my_printf("USAGE:\n      ./navy [first_player_PID] "
                    "navy_positions\nDESCRIPTION\n      "
                    "first_player_PID: only for the 2nd player."
                    " pid of the first player.\n      "
                    "navy_positions: file representing the "
                    "positions of the ships.\n");
            return 1;
        }
    return 0;
}

int main_function(int ac, char **av)
{
    int ret = 0;
    CO = malloc(sizeof(*CO));
    CO->sig_target = malloc(sizeof(char) * 3);
    CO->act = malloc(sizeof(*(CO->act)));
    if (ac == 2) {
        ret = player1(av);
    }
    if (ac == 3) {
        ret = player2(av);
    }
    free(CO->act);
    free(CO->sig_target);
    free(CO);
    return ret;
}

int main(int ac, char **av)
{
    if (print_usage(ac, av))
        return 0;
    if (ac != 2 && ac != 3)
        return 84;
    if (check_pid(ac, av) || check_file(ac, av))
        return 84;
    return main_function(ac, av);
}