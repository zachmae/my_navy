/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-1-navy-zacharie.lawson
** File description:
** sig_handler
*/

#include "navy.h"

void start_sig_handler1(int sig, siginfo_t *info, void *context)
{
    CO->waiting = 0;
    CO->pid_other = info->si_pid;
}

void wait_hit_handler(int sig, siginfo_t *info, void *context)
{
    CO->waiting = 0;
    if (sig == SIGUSR1)
        CO->hit = 1;
    if (sig == SIGUSR2)
        CO->hit = 0;
}

void recive_target_handler(int sig, siginfo_t *info, void *context)
{
    if (sig == SIGUSR1)
        (CO->sig_target[CO->char_cpt])++;
    if (sig == SIGUSR2)
        (CO->char_cpt)++;
    if (CO->char_cpt == 2)
        CO->waiting = 0;
}

void change_sig(int choice)
{
    CO->act->sa_flags = SA_SIGINFO;
    if (choice == 0) {
        CO->act->sa_sigaction = &start_sig_handler1;
        sigaction(SIGUSR1, CO->act, NULL);
    }
    if (choice == 1) {
        CO->act->sa_sigaction = &wait_hit_handler;
        sigaction(SIGUSR1, CO->act, NULL);
        sigaction(SIGUSR2, CO->act, NULL);
    }
    if (choice == 2) {
        CO->act->sa_sigaction = &recive_target_handler;
        sigaction(SIGUSR1, CO->act, NULL);
        sigaction(SIGUSR2, CO->act, NULL);
    }
}