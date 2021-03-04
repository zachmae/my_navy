/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-1-navy-zacharie.lawson
** File description:
** check_args
*/

#include "navy.h"

int is_num(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int check_pid(int ac, char **av)
{
    if (ac == 3) {
        for (int i = 0; av[1][i] != '\0'; i++)
            if (!is_num(av[1][i]))
                return 1;
    }
    return 0;
}

int open_file(int ac, char **av)
{
    char *filepath;
    int fd;

    if (ac == 2)
        filepath = av[1];
    if (ac == 3)
        filepath = av[2];
    fd = open(filepath, O_RDONLY);
    return fd;
}

int check_file(int ac, char **av)
{
    char buffer[33];
    char test_buffer[1];
    int fd = open_file(ac, av);
    int len = 0;

    if (fd == -1)
        return 1;
    len = read(fd, buffer, 32);
    if (len != 32)
        return 1;
    len = read(fd, test_buffer, 1);
    if (len != 0)
        return 1;
    buffer[32] = '\0';
    if (check_pos(buffer))
        return 1;
    close(fd);
    return 0;
}
