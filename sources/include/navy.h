/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-1-navy-zacharie.lawson
** File description:
** navy
*/

#ifndef NAVY_H_
#define NAVY_H_

#include <unistd.h>
#include <signal.h>
#include "my.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ucontext.h>
#include <fcntl.h>

typedef struct core_s
{
    int waiting;
    int pid_other;
    int turn;
    int my_hit;
    int e_hit;
    int char_cpt;
    char *sig_target;
    int hit;
    struct sigaction *act;
} core_t;

extern core_t *CO;

int player1(char **av);
void change_sig(int choice);

int player2(char **av);

char **blank_map();
void print_map(char **map, char const *str);
char **get_position(char const *file);
char **place_ship(char **map, char **pos);
int game(char **my_map, char **e_map);
void attack(char **my_map, char **e_map);

int check_pid(int ac, char **av);
int check_file(int ac, char **av);
int check_pos(char const *pos);

#endif /* !NAVY_H_ */
